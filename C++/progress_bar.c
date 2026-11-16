#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Seed with current time so every run has different step sizes
    srand(time(NULL));

    int i = 0;
    while (1) {
        printf("\rProgress: %3d%% completed", i);
        fflush(stdout);

        if (i >= 100) {
            break;
        }

        sleep(1);

        i += (rand() % 23) + 1;

        if (i > 100) {
            i = 100;
        }
    }

    printf("\n");
    return 0;
}
