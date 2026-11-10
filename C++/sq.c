#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv[]){
  if (argc < 2){
    fprintf(stderr,"<Usage> : sq <number>\n");
    return -1;
  }
  long n;
  for (int i = 1;i<argc;i++) {
    n = strtol(argv[i],NULL,10);
    printf("%ld ",n*n);
  }
  printf("\n");
  return 0;
}
