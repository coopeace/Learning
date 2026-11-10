#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define FIFO_NAME "ipc_channel"

int main(void){
  if (mkfifo(FIFO_NAME, 0666)==-1){
    if (errno != EEXIST) {
      perror("mkfifo failed");
      return -1;
    }
  }

  printf("[Writer] Waiting for a reader to connect---\n");

  FILE *fp = fopen(FIFO_NAME,"w");
  if (fp==NULL){
    perror("fopen Failed");
  }

  printf("[Writer] Reader connected! Sending messages....\n");
  
  const char *messages[] = {
    "Packet 1 : System initialization\n",
    "Packet 2 : Performing health check\n",
    "Packet 3 : All systems operational\n",
    "QUIT\n"
  };

  for (int i = 0 ; i < 4; i++) {
    fputs(messages[i],fp);

    fflush(fp);

    sleep(1);
  }

  fclose(fp);
  
  printf("[Writer] Finished and close file pointer.\n");

  return 0;
}
