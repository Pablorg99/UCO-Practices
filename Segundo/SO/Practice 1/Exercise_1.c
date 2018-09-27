/*------------------------------------------------------------------------------
Exercise_1.c
In this file, a parent process creates 3 different child processes that print
their own process id (PID). Then the parent process wait until the children end
and print the PID of the process that has finished and its status.
------------------------------------------------------------------------------*/

//key_t
#include <sys/types.h>
//fork() and getpid()
#include <unistd.h>
//exit()
#include <stdlib.h>
//wait()
#include <wait.h>
//printf()
#include <stdio.h>

int main() {

  //Status store the value returned from exit() in wait() (see parent waiting)
  int status;
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

    //Parent process wait for children
    for (int i = 0; i < 3; i++) {
      pid_t pid = wait(&status);
      printf("Child with PID = %d finished with status: %d\n", pid, WEXITSTATUS(status));
    }

  return 0;
}
