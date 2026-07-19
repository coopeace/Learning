#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char buffer[256];

    // Get Kernel Version
    fp = fopen("/proc/version", "r");
    if (fp != NULL && fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("Kernel Version:\n%s\n", buffer);
        fclose(fp);
    }

    // Get CPU Type and Model
    fp = fopen("/proc/cpuinfo", "r");
    if (fp == NULL) {
        printf("Error opening /proc/cpuinfo\n");
        return 1;
    }

    printf("CPU Details:\n");
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strncmp(buffer, "vendor_id", 9) == 0 || strncmp(buffer, "model name", 10) == 0) {
            printf("%s", buffer);
        }
    }
    fclose(fp);
    return 0;
}
