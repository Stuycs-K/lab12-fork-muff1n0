#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

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
  if (p1 == 0) {
    srand(time(NULL) + getpid());
    printf("%d %dsec\n", getpid(), (rand() + 1) % 6);
  }
}
