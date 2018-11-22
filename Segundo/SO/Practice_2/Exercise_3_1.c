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

//Buffer where producer sets data and consumer read and extract data
int buffer[TAMBUFFER];
//General semaphore for consumer, counts number of free spaces in buffer
sem_t p_empty;
//General semaphore for producer, counts number of ocupied spaces in buffer
sem_t c_full;
//Binary semaphore for mutual exclusion between consumer and producer
pthread_mutex_t binary;

#define TAMBUFFER 100

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

int main () {

    //Global variables
    extern int buffer[TAMBUFFER];
    extern sem_t c_empty, full;
    extern pthread_mutex_t mutex;
    //Initialisation of these variables
    if(pthread_mutex_init(&mutex, NULL)) frptinf(stderr, "Failed to initialise sem mutex");
    if((sem_init(&c_full, 0, 0)) == -1) frptinf(stderr, "Failed to initialise sem c_full");
    if((sem_init(&p_empty, 0, TAMBUFFER)) == -1) frptinf(stderr, "Failed to initialise sem p_empty");

    //Threads variables
    pthread_t consumer;
    pthread_t producer;
    int thread_status;

    //Create consumer
    if(thread_status = pthread_create(&consumer, NULL, &Consumer, NULL) {
        fprintf(stderr, "Failed to create consumer thread");
        exit(thread_status);
    }
    //Create producer
    if(thread_status = pthread_create(&producer, NULL, &Producer, NULL) {
        fprintf(stderr, "Failed to create producer thread");
    }

}



// Proceso o hilo productor
void Productor()
{
    extern semaforo mutex, full, empty;
    T dato;
    while (TRUE) {
        ProducirDato(dato);
        wait(empty);
        wait(mutex);
        EntrarDato(dato);
        signal(mutex);
        signal(full);
    }
}

// Proceso o hilo consumidor
void Consumer()
{
    extern semaforo mutex, full, empty;
    T dato;
    while (TRUE) {
        wait(full);
        wait(mutex);
        SacarDato(dato);
        signal(mutex);
        signal(empty);
        ConsumirDato(dato);
    }
}

