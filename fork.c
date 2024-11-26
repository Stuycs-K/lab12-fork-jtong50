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
#include <sys/wait.h>

int main(){
  printf("%d about to create 2 child processes.\n", getpid());
  pid_t p1;
  p1 = fork();
  if (p1 < 0){
    perror("forkfail");
    exit(1);
  } else if (p1 == 0){
    srand(time(NULL) + getpid()); 
    int one = (rand() % 5) + 1; 
    printf("%d %dsec\n", getpid(), one);
    sleep(one); 
    printf("%d finished after %dsec\n", getpid(), one);
    return one; 
  }
  else{
    pid_t p2;
    p2 = fork();
    if (p2 == 0){
      srand(time(NULL) + getpid()); 
      int two = (rand() % 5) + 1; 
      printf("%d %dsec\n", getpid(), two);
      sleep(two); 
      printf("%d finished after %dsec\n", getpid(), two);
      return two; 
    }
  }

  int status; 
  int childpid = wait(&status); 
  printf("Main process %d is done. %d slept for %dsec\n", getpid(), childpid, WEXITSTATUS(status));

}
