#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

static void sighandler(int signo){
  if(signo == SIGINT){ //interupt
    printf("\nSIGINT\n");
    exit(1);
  }
  if(signo == SIGUSR1){
    printf("PID:%d\n",getpid());
  }

}


int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
