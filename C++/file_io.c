#include <stdio.h>

int main(void){
  char filename[] = "raw_output.txt";
  FILE *fp = fopen(filename,"r");
  if (fp == NULL) {
    fprintf(stderr,"Failed to open %s",filename);
    return 1;
  }
  char line[500];
  while (fgets(line,sizeof(line),fp)!=NULL){
    puts(line);
  }
  fclose(fp);
  return 0;
}
