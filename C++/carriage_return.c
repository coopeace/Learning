#include <stdio.h>
#include <unistd.h>

int main(void) {
    // Prints "Hello World", then \r snaps cursor back to position 0
    // and overwrites "Hello" with "Super"
    printf("Hello World");
    fflush(stdout);
    sleep(1);
    printf("\rSuper\n");
    return 0;
}
