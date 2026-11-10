#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usuage : sudo %s <termnial_name> <message>", argv[0]);
    return 1;
  }

  char *filename = argv[1];

  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    fprintf(stderr, "Failed to open %s\n", filename);
    return 1;
  }

  int total_chars_written = 0;

  for (int i = 2; i < argc; i++) {
    total_chars_written += fprintf(fp, "%s", argv[i]);

    if (i < argc - 1) {
      total_chars_written += fprintf(fp, " ");
    }
  }

  total_chars_written += fprintf(fp, "\n");
  fflush(fp);

  if (total_chars_written > 0) {
    puts("Message was successfully sent");
    printf("total_chars_written : %d\n",total_chars_written);
  } else {
    perror("Message was NOT successfully sent");
  }

  fclose(fp);
  return 0;
}
