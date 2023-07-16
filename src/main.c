#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

int  main(int argc, char **argv)
{

  hs_loop();
  return EXIT_SUCCESS;

  
}

void hs_loop(void){
  char*line;
  char**args;
  char status;

  do
  {
    printf(">> ");
    line = hs_read_line();
    args = hs_split_line(line);
    status = hs_execute(args);
    free(line);
    free(args);
  } while (status);
  
}

#define HS_RL_BUFSIZE 1024

char *hs_read_line(void){
  int bufsize = HS_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "hs: allocation error\n");
    exit(EXIT_FAILURE);
  }

 while(1){

  c = getchar();

  if (c == EOF || c == '\n'){
    buffer[position] = '\0';
    return buffer;
  } else {
    buffer[position] = c;
  }
  position++;
  
  
  
  if(position >= bufsize){
    bufsize += HS_RL_BUFSIZE;  
    buffer = realloc(buffer, bufsize);
    if (!buffer) {
      fprintf(stderr, "hs: allocation error\n");
      exit(EXIT_FAILURE);

      
          }
 
        }

    }
}