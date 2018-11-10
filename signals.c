#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

static void sighandler1(int signo){
  if (signo == SIGUSR1)
    printf("Parent PID: %d\n", getppid());
}



static void sighandler2(int signo){
  if (signo == SIGINT){
    printf("Exiting due to SIGINT\n");
    exit(0);
  }
}


int main(){
  while (1){
    signal(SIGUSR1, sighandler1);
    signal(SIGINT, sighandler2);

    printf("PID: %d\n", getpid());
    sleep(1);
  }
}
