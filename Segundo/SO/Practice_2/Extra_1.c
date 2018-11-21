/*----------------------------------------------------------------------------------
Pablo Rodríguez Guillén
Extra_1.c
This is the source code with the solution of the first extra exercise from the second
practice of Operative Systems.

1. Realice la multiplicación en paralelo de una matriz de 3x3 por un vector de 3x1.
Para ello cree tres hebras que se repartan las filas de la matriz y del vector.
Cada hijo debe imprimir la fila que le ha tocado y el resultado final de la 
multiplicación la cual además envía al padre. El padre debe esperar por la 
terminación de cada hijo y mostrar el vector resultante. 
----------------------------------------------------------------------------------*/

//NEED 1 THRED FOR ROW, SO EQUAL NUMBER
#define MATRIXROWS 3
#define MATRIXCOLS 3

//IF CHANGE DIMENSION, CHANGE NUMBERS HERE
int matrix[MATRIXROWS][MATRIXCOLS] = {
    {2, 1, 3},
    {3, 4, 1},
    {5, 2, 2} 
};
//AND HERE
int array[MATRIXROWS] = {1, 2, 3}; 

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void printMatrix(int matrix[MATRIXROWS][MATRIXCOLS]) {
    printf("MATRIX[%d][%d]:", MATRIXROWS, MATRIXCOLS);
    for(int i = 0; i < MATRIXROWS; i++) {
        printf("\n");
        for(int j = 0; j < MATRIXCOLS; j++) {
            printf("%d  ", matrix[i][j]);
        }
    }
    printf("\n");
}

void printArray(int * array) {
    printf("Array[%d] = ", MATRIXROWS);
    for(int i = 0; i < MATRIXROWS; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    pthread_t threads[MATRIXROWS];
    int thread_index[MATRIXROWS], results[MATRIXROWS], status, *r_value;
    //I need a function pointer as an argument of pthread_create
    void *RowMultiplication(void *);

    extern int matrix[MATRIXROWS][MATRIXCOLS];
    extern int array[MATRIXROWS];
    printMatrix(matrix);
    printArray(array);

    //Create threads
    for(int i = 0; i < MATRIXROWS; i++) {
        thread_index[i] = i;
        if((status = pthread_create(&threads[i], NULL, RowMultiplication, (void *) &thread_index[i]))) exit(status);
    }

    //Wait for thread returns
    for(int i = 0; i < MATRIXROWS; i++) {
        pthread_join(threads[i], (void **) &r_value);
        printf("Value returned by %lu thread: %d\n", threads[i], *r_value);
        results[i] = *r_value;
    }

    //Final result
    printf("Results[%d] = ", MATRIXROWS);
    for(int i = 0; i < MATRIXROWS; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");

    return 0;
}

void *RowMultiplication(void * thread_index) {
    int index;
    index = *((int *)thread_index);
    extern int matrix[MATRIXROWS][MATRIXCOLS];
    extern int array[MATRIXROWS];
    //comment
    int result = 0;
    int *to_return;    

    for(int ncols = 0; ncols < MATRIXCOLS; ncols++) {
        result += matrix[index][ncols] * array[index];
    }
    
    to_return = malloc(sizeof(int));
    *to_return = result;
    pthread_exit((void *)to_return);
}