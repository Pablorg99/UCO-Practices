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

int higher_array(int *number) {
  int higher = 0;
  for(int i = 0; i < NTHREADS; i++) {
    if (number[i] > higher) {
      higher = number[i];
    }    
  }
  return higher;  
}

void *adder(void *arg)
{
  double thread_counter, *to_return;
  int *index = (int *) arg;
  
  extern double counter;
  extern int picking[NTHREADS];
  extern int number[NTHREADS];

  for (int i = 0; i < ITER; i++) {
    //When a thread is picking a number, its picking is 1 (true)
    picking[*index] = 1;
    //That thread is the new one, so he gets the highest number (higher + 1)
    number[*index] = higher_array(number) + 1;
    //The thread is not picking number so its picking is set to 0
    picking[*index] = 0;
    //This loop check if the thread number 'j' is picking
    //If not, it checks if its number is higher than the process' number that is running at that moment
    for(int j = 0; j < NTHREADS; j++) {
      while(picking[j]);
      while((number[j] != 0) && ((number[j] < number[*index]) || ((number[j] == number[*index]) && ((j < *index))))); 
    }
    //Critical section beginning
    thread_counter = counter;
    fprintf(stdout, "Thread %d: %f\n", *index, counter);
    thread_counter++;
    counter = thread_counter;
    //Critical section end
    //The process that goes out the critical section is set to 0
    //If this process has not done 1k iterations, it picks another number
    number[*index] = 0;
  }

  to_return = malloc(sizeof(double));

  *to_return = counter;

  pthread_exit((void *) to_return);
}
