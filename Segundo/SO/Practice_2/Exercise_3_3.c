/*----------------------------------------------------------------------------------
Pablo Rodríguez Guillén
Extra_3_1.c
This is the source code with the solution of the second part of the third exercise
from the second practice of Operative Systems.

Los hilos productores generan números aleatorios en el intervalo [0,1000] y los
depositan en el búfer limitado de tamaño N. Los hilos consumidores leen los números
depositados en el búfer y realizan las sumas sucesivas de los números leídos.
Para comprobar la corrección de la solución programada los productores realizarán
las sumas de los números que producen para comprobar si las sumas coinciden con
las de los consumidores. Hay un hilo productor y C hilos consumidores. Cada número
generado por el productor ha de ser consumido por TODOS los hilos consumidores.
----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define CONSUMERS 5
#define TAMBUFFER 10

//Buffer where producer sets data and consumer reads and extract data
int buffer[TAMBUFFER];
//General semaphore that counts number of empty spaces in buffer
sem_t empty;
//General semaphore that counts number of ocupied spaces in buffer
sem_t full;
//Binary semaphore for mutual exclusion between consumer and producer
sem_t mutex;

//Function headers
void * Producer();
void * Consumer();

int main () 
{
    //Global variables
    extern sem_t empty, full, mutex;
    srand(time(NULL));
    //Initialisation of semaphores
    if((sem_init(&mutex, 0, 1)) == -1) perror("Error: Failed to initialise sem mutex ");
    if((sem_init(&full, 0, 0)) == -1) perror("Error: Failed to initialise sem full ");
    if((sem_init(&empty, 0, TAMBUFFER)) == -1) perror("Error: Failed to initialise sem empty ");


    //Threads variables
    pthread_t consumer[CONSUMERS];
    pthread_t producer;
    int thread_status;

    int *return_value = 0;

    int thread_index[CONSUMERS];
    //Create consumers
    for(int i = 0; i < CONSUMERS; i++) {
        thread_index[i] = i;
        if((thread_status = pthread_create(&consumer[i], NULL, Consumer, (void *) &thread_index[i]))) {
            fprintf(stderr, "Failed to create consumer thread");
            exit(thread_status);
        }
    }
    //Create producer
    if((thread_status = pthread_create(&producer, NULL, Producer, NULL))) {
        fprintf(stderr, "Failed to create producer thread");
        exit(thread_status);
    }

    //Wait consumers
    for(int i = 0; i < CONSUMERS; i++) {
        if((thread_status = pthread_join(consumer[i], (void *) &return_value))) fprintf(stderr, "Error %d in pthread_join\n", thread_status);
        printf("Consumer thread %lu has finished with value %d\n", consumer[i], *return_value);
    }
    //Wait producer
    if((thread_status = pthread_join(producer, (void *) &return_value))) fprintf(stderr, "Error %d in pthread_join\n", thread_status);
    printf("Producer thread %lu has finished with value %d\n", producer, *return_value);
}

//Producer thread
void * Producer()
{
    printf("Estoy en producer\n");
    extern int buffer[TAMBUFFER];
    extern sem_t mutex, full, empty;
    int number, producer_addition = 0;
    int *to_return;

    /*To check that the implementation is working properly, iterations
    must be >> TAMBUFFER to fill and empy the buffer multiple times*/
    for(int i = 0; i < 100; i++) {
        number = ((rand() % 1000) + 1);
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[i % TAMBUFFER] = number;
        producer_addition += number;
        printf("Estoy en el bucle %d de producer: %d\n", i, producer_addition);
        sem_post(&mutex);
        sem_post(&full);
    }
    //Return process
    to_return = malloc(sizeof(int));
    *to_return = producer_addition;
    pthread_exit((void *)to_return);
}

//Consumer thread
void * Consumer(void *arg)
{
    printf("Estoy en consumer\n");
    extern int buffer[TAMBUFFER];
    extern sem_t mutex, full, empty;
    int consumer_addition = 0;
    int *to_return;
    int *index;
    index = (int *) arg;


    //Now each consumer consumes all products produced (100)
    for(int i = 0; i < 100; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        consumer_addition += buffer[i % TAMBUFFER];
        //Sets to 0 for easier debugging (if necessary)
        buffer[i % TAMBUFFER] = 0;
        printf("Estoy en el bucle %d de consumer %d: %d\n", i, *index, consumer_addition);
        sem_post(&mutex);
        sem_post(&empty);
    }
    //Return process
    to_return = malloc(sizeof(int));
    *to_return = consumer_addition;
    pthread_exit((void *)to_return);
}