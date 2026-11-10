#include <unistd.h>  // read, write, close, sleep
#include <fcntl.h>   // open flags: O_WRONLY, O_CREAT, O_TRUNC

int main(void) {
    char prompt[] = "Opening raw_output.txt...\n";
    write(1, prompt, sizeof(prompt) - 1);

    // Open file on disk -> gets lowest available index: FD 3
    int fd_file = open("raw_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_file < 0) {
        char err[] = "Failed to open file\n";
        write(2, err, sizeof(err) - 1);
        return 1;
    }

    char held_msg[] = "File is OPEN as FD 3. Sleeping for 30 seconds...\n";
    write(1, held_msg, sizeof(held_msg) - 1);

    // Pause execution: inspect /proc/<PID>/fd now!
    sleep(30);

    // Cleanup and release FD 3
    close(fd_file);

    char done_msg[] = "Closed FD 3. Exiting.\n";
    write(1, done_msg, sizeof(done_msg) - 1);

    return 0;
}
