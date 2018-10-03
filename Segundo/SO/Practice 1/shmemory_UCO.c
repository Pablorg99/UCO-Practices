//FILE PROVIDED BY UNIVERSITY (MOODLE)

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define ITER		5
#define CHILDREN	5

// The process finished correctly
#define Ok	7

int main()
{
  int i, shmid, status;
  key_t key;
  double *counter;
  void adder(int);
  struct shmid_ds buf;

  // Shared memory
  key = ftok("shmemory.c", 1);
  if ((shmid = shmget(key, sizeof(double), IPC_CREAT | 0777)) == -1)
     exit(1);

  counter = (double *) shmat(shmid, NULL, 0);
  *counter = 0.0;

  // Run children
  for (i = 0; i < CHILDREN; i++) {
  	if (!fork()) {
  	    adder(i);
  	    exit(0);
    }
  }

  // Wait to finish
  for (i = 0; i < CHILDREN; i++) {
  	pid_t pid = wait(&status);
  	printf("\nChild %d finished with status %d\n", pid, WEXITSTATUS(status));
  }

  // Final result
  fprintf(stdout, "Counter: %f\n", *counter);

  // Detach segment
  shmdt(counter);

  // Mark the segment to be destroyed
  shmctl(shmid, IPC_RMID, &buf);

  return 0;
}

void adder(int id)
{
  double x = 1.0, l;
  double *counter;
  int i, shmid;
  key_t key;

  // Shared memory
  key = ftok("shmemory.c", 1);
  if ((shmid = shmget(key, sizeof(double), 0)) == -1)
     perror("Child: ");
  counter = (double *) shmat(shmid, NULL, 0);

  for (i = 0; i < ITER; i++) {
  	l = *counter;
  	fprintf(stdout, "Process %d: %lf\n", id, *counter);
  	l += x;
  	*counter = l;
  }
  fprintf(stdout, "*Process %d: %lf\n", id, *counter);
  shmdt(counter);


  exit(Ok);
}
