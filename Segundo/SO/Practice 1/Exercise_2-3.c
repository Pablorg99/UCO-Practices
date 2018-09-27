//ftok()
#include <sys/ipc.h>
//key_t and pid_t
#include <sys/types.h>
//fork() and getpid() 
#include <unistd.h>
//shared memory functions
#include <sys/shm.h>
//exit()
#include <stdlib.h>
//wait()
#include <wait.h>
//printf()
#include <stdio.h>

int main() {

  int shmid, status;
  key_t key;

    if (! fork()) {
      printf("PID Child 1 = %d\n", getpid());
      exit(0);
    }

    if (! fork()) {
      printf("PID Child 2 = %d\n", getpid());
      exit(0);
    }

    if (! fork()) {
      printf("PID Child 3 = %d\n", getpid());
      exit(0);
    }

    for (int i = 0; i < 3; i++) {
      pid_t pid = wait(&status);
      printf("Child with PID = %d finished with status: %d\n", pid, WEXITSTATUS(status));
    }

  return 0;
}
