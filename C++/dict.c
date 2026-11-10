#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

// Dynamic buffer to accumulate HTTP response chunks
typedef struct {
    char *memory;
    size_t size;
} MemoryBuffer;

// Callback used by libcurl when bytes arrive over the network
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_bytes = size * nmemb;
    MemoryBuffer *mem = (MemoryBuffer *)userp;

    char *ptr = realloc(mem->memory, mem->size + total_bytes + 1);
    if (!ptr) {
        fprintf(stderr, "Out of memory!\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, total_bytes);
    mem->size += total_bytes;
    mem->memory[mem->size] = '\0';

    return total_bytes;
}

// Navigates and prints the JSON tree matching the Python logic
static void parse_and_display(const char *json_string) {
    cJSON *root = cJSON_Parse(json_string);
    if (!root) {
        fprintf(stderr, "Failed to parse JSON response.\n");
        return;
    }

    // The API returns a top-level array: [ { ... } ]
    if (!cJSON_IsArray(root) || cJSON_GetArraySize(root) == 0) {
        cJSON_Delete(root);
        return;
    }

    cJSON *first_entry = cJSON_GetArrayItem(root, 0);
    cJSON *word_item = cJSON_GetObjectItemCaseSensitive(first_entry, "word");
    if (cJSON_IsString(word_item) && word_item->valuestring) {
        printf("\nWord: %s\n--------------------\n", word_item->valuestring);
    }

    cJSON *meanings = cJSON_GetObjectItemCaseSensitive(first_entry, "meanings");
    if (!cJSON_IsArray(meanings)) {
        cJSON_Delete(root);
        return;
    }

    // Iterate through parts of speech
    cJSON *meaning = NULL;
    cJSON_ArrayForEach(meaning, meanings) {
        cJSON *pos = cJSON_GetObjectItemCaseSensitive(meaning, "partOfSpeech");
        if (cJSON_IsString(pos)) {
            printf("\n[%s]\n", pos->valuestring);
        }

        cJSON *definitions = cJSON_GetObjectItemCaseSensitive(meaning, "definitions");
        if (!cJSON_IsArray(definitions)) continue;

        int def_count = 0;
        int example_count = 0;
        cJSON *def_entry = NULL;

        cJSON_ArrayForEach(def_entry, definitions) {
            if (def_count >= 3) break; // Limit: up to 3 definitions

            cJSON *def_text = cJSON_GetObjectItemCaseSensitive(def_entry, "definition");
            if (cJSON_IsString(def_text) && def_text->valuestring) {
                def_count++;
                printf("  %d. %s\n", def_count, def_text->valuestring);
            }

            // Limit: up to 2 examples per part of speech
            cJSON *example = cJSON_GetObjectItemCaseSensitive(def_entry, "example");
            if (cJSON_IsString(example) && example->valuestring && example_count < 2) {
                printf("     Example: \"%s\"\n", example->valuestring);
                example_count++;
            }
        }
    }

    // Free the entire parsed JSON tree
    cJSON_Delete(root);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <word>\n", argv[0]);
        return -1;
    }

    char *word = argv[1];
    char url[512];
    snprintf(url, sizeof(url), "https://api.dictionaryapi.dev/api/v2/entries/en/%s", word);

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl_handle = curl_easy_init();
    if (!curl_handle) {
        fprintf(stderr, "Failed to initialize curl.\n");
        return 1;
    }

    MemoryBuffer chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    CURLcode res = curl_easy_perform(curl_handle);

    if (res != CURLE_OK) {
        fprintf(stderr, "Network request failed: %s\n", curl_easy_strerror(res));
    } else {
        long response_code;
        curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &response_code);

        if (response_code == 200) {
            parse_and_display(chunk.memory);
        } else if (response_code == 404) {
            printf("Word '%s' not found.\n", word);
        } else {
            printf("API error: Status code %ld\n", response_code);
        }
    }

    // Cleanup resources
    free(chunk.memory);
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();

    return 0;
}
