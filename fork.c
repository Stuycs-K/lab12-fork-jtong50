#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
  printf("%d about to create 2 child processes.\n", getpid());

  pid_t p1;
  p1 = fork();
  if (p1 < 0){
    perror("forkfail");
    exit(1);
  } else if (p1 == 0){

    printf("%d %d\n", getpid());

  }
  else{
    pid_t p2;
    p2 = fork();
    if (p2 == 0){
      printf("%d\n", getpid());
    }
  }

}
