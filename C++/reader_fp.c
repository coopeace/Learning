#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define FIFO_NAME "ipc_channel"
#define BUFFER_SIZE 128

int main(void) {
    // Ensure pipe exists
    if (mkfifo(FIFO_NAME, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo failed");
        return 1;
    }

    printf("[Reader] Waiting for a writer to open the pipe...\n");

    // BLOCKS until a writer opens the file with "w"
    FILE *fp = fopen(FIFO_NAME, "r");
    if (fp == NULL) {
        perror("fopen failed");
        return 1;
    }

    printf("[Reader] Writer detected! Reading lines...\n");

    char buffer[BUFFER_SIZE];

    // fgets() reads until a newline '\n' or EOF (when writer calls fclose)
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("[Received]: %s", buffer);

        if (strncmp(buffer, "QUIT", 4) == 0) {
            printf("[Reader] Received QUIT signal. Exiting.\n");
            break;
        }
    }

    fclose(fp);

    // Remove the pipe file from the filesystem
    unlink(FIFO_NAME);
    return 0;
}
