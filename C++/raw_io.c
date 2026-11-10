#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 64

int main(void){
  char prompt[] = "Type something";
  char output_prefix[] = "\nUser typed: ";
  char buffer[BUFFER_SIZE];
  write(1,prompt,sizeof(prompt)-1);

  ssize_t bytes_read = read(0, buffer, sizeof(buffer));
  if (bytes_read<=0){
    return 1;
  }

  write(1, output_prefix, sizeof(output_prefix)-1);
  write(1,buffer,bytes_read);

  int fd_file = open("raw_output.txt",O_WRONLY | O_CREAT | O_TRUNC,0644);
  if (fd_file<0) {
    char err_msg[] = "Failed to open file\n";
    write(1,err_msg,sizeof(err_msg)-1);
    return 1;
  }
  write(fd_file,buffer,bytes_read);
  close(fd_file);
  return 0;
}
