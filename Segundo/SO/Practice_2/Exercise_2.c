/*------------------------------------------------------------------------------
Practice 2 Exercise 2 OS
Pablo Rodríguez Guillén
Exercise_2.c
Modification to threads_UCO.c to have 4 threads running with Lamport's Algorithm
implementation for counting correctly
------------------------------------------------------------------------------*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define ITER	1000
#define NTHREADS	4

double counter = 0;
int picking[NTHREADS];
int number[NTHREADS];

int main()
{
  pthread_t threads[NTHREADS];
  int status, i, thread_index[NTHREADS];

  extern double counter;
  extern int picking[NTHREADS];
  extern int number[NTHREADS];
  void *adder(void *);
  double *r_value;

  //Initialisation of Lamport's Algorithm's arrays
  for(int i = 0; i < NTHREADS; i++) {
    picking[i] = 0;
    number[i] = 0;
  }

  // Create NTHREADS threads
  for (i = 0; i < NTHREADS; i++) {
  	thread_index[i] = i;
  	if ((status = pthread_create(&threads[i], NULL, adder, (void *) &thread_index[i])))
    exit(status);
  }

  // Wait threads
  for (i = 0; i < NTHREADS; i++) {
  	pthread_join(threads[i], (void **) &r_value);
  	printf("Value returned by %lu thread: %lf\n", threads[i], *r_value);
  }

  // Final result
  fprintf(stdout, "Final counter = %lf\n", counter);

  return 0;
}

void *adder(void *arg)
{
  double thread_counter, *to_return;
  extern double counter;
  extern int picking[NTHREADS];
  extern int number[NTHREADS];
  int *index = (int *) arg;
  int j = 0;

  for (int i = 0; i < ITER; i++) {
    
    picking[*index] = 1;
    number[*index] = j++;
    picking[*index] = 0;
    
    for(j = 0; j < NTHREADS; j++) {
      while(picking[j]);
      while(number[j] != 0 && (number[j] < number[*index]) || (j < *index)); 
    }

    thread_counter = counter;
    fprintf(stdout, "Thread %d: %f\n", *index, counter);
    thread_counter++;
    counter = thread_counter;

    number[*index] = 0;
  }

  to_return = malloc(sizeof(double));

  *to_return = counter;

  pthread_exit((void *) to_return);
}
