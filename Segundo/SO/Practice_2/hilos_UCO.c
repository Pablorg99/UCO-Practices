//FILE PROVIDED BY UNIVERSITY (MOODLE)

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

double counter = 0;

#define ITER	1000
#define NHILOS	3

int main()
{
    pthread_t hilos[NHILOS];
    int status, i, v[NHILOS];
    extern double counter;
    void *adder(void *);
    double *r_value;

    // Create NHILOS threads
    for (i = 0; i < NHILOS; i++) {
    	v[i] = i;
    	if ((status = pthread_create(&hilos[i], NULL, adder, (void *) &v[i])))
	    exit(status);
    }

    // Wait threads
    for (i = 0; i < NHILOS; i++) {
    	pthread_join(hilos[i], (void **) &r_value);
    	printf("Value returned by %lu thread: %lf\n", hilos[i], *r_value);
    }

    // Final result
    fprintf(stdout, "%f\n", counter);

    return 0;
}

void *adder(void *p)
{
    double l, *to_return;
    extern double counter;
    int *id, i;

    id = (int *) p;

    for (i = 0; i < ITER; i++) {
    	l = counter;
    	fprintf(stdout, "Hilo %d: %f\n", *id, counter);
    	l++;
    	counter = l;
    }

    to_return = malloc(sizeof(double));

    *to_return = counter;

    pthread_exit((void *) to_return);
}
