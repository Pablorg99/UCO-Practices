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
las de los consumidores. Hay P hilos productores y C hilos consumidores. Cada número
generado por un productor es consumido por un único consumidor. Esta es la 
formulación estándar del problema del productor consumidor.
----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define PPP 50 //Products per producer
#define PRODUCERS 5
#define CONSUMERS 5
#define TAMBUFFER 10

//Buffer where producer sets data and consumer reads and extract data
int buffer[TAMBUFFER];
//Variables where addition of consumers and producers are stored
int producer_addition = 0, consumer_addition = 0;
//Indices for producers and consumers. In this second part, the iterator can not be
//used as index anymore because it is not common for all producers/consumers threads
int producer_index = 0;
int consumer_index = 0;
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
    pthread_t producer[PRODUCERS];
    int thread_status;

    int *return_value = 0;

    //Create consumers
    for(int i = 0; i < CONSUMERS; i++) {
        if((thread_status = pthread_create(&consumer[i], NULL, Consumer, NULL))) {
            fprintf(stderr, "Failed to create consumer thread");
            exit(thread_status);
        }
    }
    //Create producers
    for(int i = 0; i < PRODUCERS; i++) {
        if((thread_status = pthread_create(&producer[i], NULL, Producer, NULL))) {
            fprintf(stderr, "Failed to create producer thread");
            exit(thread_status);
        }
    }
    
    //Wait consumers
    for(int i = 0; i < CONSUMERS; i++) {
        if((thread_status = pthread_join(consumer[i], (void *) &return_value))) fprintf(stderr, "Error %d in pthread_join\n", thread_status);
        printf("Consumer thread %lu has finished with value %d\n", consumer[i], *return_value);
    }
    //Wait producers
    for(int i = 0; i < PRODUCERS; i++) {
        if((thread_status = pthread_join(producer[i], (void *) &return_value))) fprintf(stderr, "Error %d in pthread_join\n", thread_status);
        printf("Producer thread %lu has finished with value %d\n", producer[i], *return_value);
    }

    //Final results
    printf("Global producers addition = %d\n", producer_addition);
    printf("Global consumers addition = %d\n", consumer_addition);
}

//Producer thread
void * Producer()
{
    extern int buffer[TAMBUFFER], producer_addition, producer_index;
    extern sem_t mutex, full, empty;
    int number;
    int *to_return;

    /*To check that the implementation is working properly, iterations
    must be >> TAMBUFFER to fill and empy the buffer multiple times*/
    for(int i = 0; i < PPP; i++) {
        number = ((rand() % 1000) + 1);
        sem_wait(&empty);
        sem_wait(&mutex);
        producer_index++;
        buffer[producer_index % TAMBUFFER] = number;
        producer_addition += number;
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
    extern int buffer[TAMBUFFER], consumer_addition, consumer_index;
    extern sem_t mutex, full, empty;
    int *to_return;

    /*Consumers have to consume all products produced (producers * products per 
    producer). So each consumer have to consume: all products / number of consumers*/
    for(int i = 0; i < ((PRODUCERS * PPP) / CONSUMERS); i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        consumer_index++;
        consumer_addition += buffer[consumer_index % TAMBUFFER];
        //Sets to 0 for easier debugging (if necessary)
        buffer[consumer_index % TAMBUFFER] = 0;
        sem_post(&mutex);
        sem_post(&empty);
    }
    //Return process
    to_return = malloc(sizeof(int));
    *to_return = consumer_addition;
    pthread_exit((void *)to_return);
}