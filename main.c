#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
  printf("%d about to create 2 child processes\n", getpid());
  pid_t p = fork();
  pid_t p1;
  if (p < 0) {
    perror("fork fail");
    exit(1);
  }
  else if (p > 0) {
    p1 = fork();
  }
  int rng;

  if (p1 == 0) {
    srand(time(NULL) + getpid());
    rng = rand() % 5 + 1;
    printf("%d %dsec\n", getpid(), rng);
    sleep(rng);
    printf("%d finished after %dsec\n", getpid(), rng);
    return rng;
  }
  if (p == 0) {
    srand(time(NULL) + getpid());
    rng = rand() % 5 + 1;
    printf("%d %dsec\n", getpid(), rng);
    sleep(rng);
    printf("%d finished after %dsec\n", getpid(), rng);
    return rng;
  }
  if (p > 0) {
    int status;
    int id = wait(&status);
    printf("Main Process %d is done. Child %d slept for %dsec\n", getpid(), id, WEXITSTATUS(status));
  }


}
