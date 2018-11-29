/*----------------------------------------------------------------------------------
Pablo Rodríguez Guillén
Extra_3_1.c
This is the source code with the solution of the first part of the third exercise
from the second practice of Operative Systems.

Los hilos productores generan números aleatorios en el intervalo [0,1000] y los
depositan en el búfer limitado de tamaño N. Los hilos consumidores leen los números
depositados en el búfer y realizan las sumas sucesivas de los números leídos.
Para comprobar la corrección de la solución programada los productores realizarán
las sumas de los números que producen para comprobar si las sumas coinciden con
las de los consumidores. Hay un único hilo productor y un único hilo consumidor.
----------------------------------------------------------------------------------*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

#define TAMBUFFER 10

//Buffer where producer sets data and consumer reads and extract data
int buffer[TAMBUFFER];
//Variables where addition of consumer and producer are stored
/*These are not necessary with only 1 producer and 1 consumer, but are necessary
for the next part of the exercise*/
int producer_addition = 0, consumer_addition = 0;
//General semaphore that counts number of free spaces in buffer
sem_t empty;
//General semaphore that counts number of ocupied spaces in buffer
sem_t full;
//Binary semaphore for mutual exclusion between consumer and producer
sem_t mutex;

//Function headers
void * Producer();
void * Consumer();

int main () {

    //Global variables
    extern sem_t empty, full, mutex;
    srand(time(NULL));
    //Initialisation of semaphores
    if((sem_init(&mutex, 0, 1)) == -1) perror("Error: Failed to initialise sem mutex\n");
    if((sem_init(&full, 0, 0)) == -1) perror("Error: Failed to initialise sem c_full\n");
    if((sem_init(&empty, 0, TAMBUFFER)) == -1) perror("Error: Failed to initialise sem p_empty\n");


    //Threads variables
    pthread_t consumer;
    pthread_t producer;
    int thread_status;

    //Local additions (checks global producer and consumer additions)
    int *consumer_return = 0;
    int *producer_return = 0;

    //Create consumer
    if((thread_status = pthread_create(&consumer, NULL, Consumer, NULL))) {
        fprintf(stderr, "Failed to create consumer thread\n");
        exit(thread_status);
    }
    //Create producer
    if((thread_status = pthread_create(&producer, NULL, Producer, NULL))) {
        fprintf(stderr, "Failed to create producer thread\n");
        exit(thread_status);
    }

    //Waiting consumer
    if(pthread_join(consumer, (void *) &consumer_return)) fprintf(stderr, "Error in pthread_join\n");
    //Just check that pthread_join is getting what pthread_exit returns
    if(*consumer_return == consumer_addition) {
        printf("Consumer addition has been: %d\n", *consumer_return);
    }

    //Waiting producer
    if(pthread_join(producer, (void *) &producer_return)) fprintf(stderr, "Error in pthread_join\n");
    //Just check that pthread_join is getting what pthread_exit returns
    if(*producer_return == producer_addition) {
        printf("Producer addition has been: %d\n", *producer_return);
    }
    
}

//Producer thread
void * Producer()
{
    extern int buffer[TAMBUFFER], producer_addition;
    extern sem_t mutex, full, empty;
    int number;
    int *to_return;

    /*To check that the implementation is working properly 'i' must 
    be >> TAMBUFFER to fill and empy the buffer multiple times*/
    for(int i = 0; i < 100; i++) {
        number = ((rand() % 1000) + 1);
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[i % TAMBUFFER] = number;
        producer_addition += buffer[i % TAMBUFFER];
        sem_post(&mutex);
        sem_post(&full);
    }
    //Return process
    to_return = malloc(sizeof(int));
    *to_return = producer_addition;
    pthread_exit((void *)to_return);
}

//Consumer thread
void * Consumer()
{
    extern int buffer[TAMBUFFER], consumer_addition;
    extern sem_t mutex, full, empty;
    int *to_return;

    /*To check that the implementation is working properly 'i' must 
    be >> TAMBUFFER to fill and empy the buffer multiple times*/
    for(int i = 0; i < 100; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        consumer_addition += buffer[i % TAMBUFFER];
        buffer[i % TAMBUFFER] = 0;
        sem_post(&mutex);
        sem_post(&empty);
    }
    //Return process
    to_return = malloc(sizeof(int));
    *to_return = consumer_addition;
    pthread_exit((void *)to_return);
}