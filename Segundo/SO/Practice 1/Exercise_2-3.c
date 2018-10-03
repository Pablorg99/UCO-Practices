/*------------------------------------------------------------------------------

------------------------------------------------------------------------------*/

#include <sys/ipc.h> //ftok()
#include <sys/types.h> //key_t and pid_t
#include <unistd.h> //fork(), getpid() and sleep()
#include <sys/shm.h> //shared memory functions
#include <stdlib.h> //exit(), rand() and srand()
#include <time.h> //time()
#include <wait.h> //wait()
#include <stdio.h> //printf()

void arrayFilling (int *array) {
  for (int i = 0; i < 100; i++) {
    array[i] = (rand() % 100) + 1;
  }
}

void askUser (int *array) {
  int index;
  int value;
  //Index asking
  printf("Introduce an index of the array (from 0 to 99): ");
  scanf("%d", index);
  while (index < 0 || index > 99) {
    printf("That value was not between 0 and 99, introduce a correct one: ");
    scanf("%d", index);
  }
  //Value asking
  printf("Introduce a number to save in position %d: \n", index);
  scanf("%d", value);
  //Assignment
  array[index] = value;
}

void changeValues (int *array) {
  int randomIndex = rand() %100;
  int randomValue = (rand() %100) + 1;
  array[randomIndex] = randomValue;
  sleep(1); //Pauses program during the number of seconds passed as parameter
}

void addValuesAndPrint ()

int main () {

  //Fill the array with random values from 1 to 100
  void arrayFilling (int *array);
  void askUser (int *array);
  void changeValues (int *array);
  void addValuesAndPrint (int *array);

  int shmid, status;
  int *array;
  key_t key;

  //Assignment of shared shmemory

    key = ftok ("Exercise_2-3.c", 1); //Obtaining memory key

    //Create shared memory space
    shmid = shmget(key, sizeof(int) * 100, IPC_CREAT | 0777)
    if (shmid == -1) {
      printf("Error while creating shared memory space\n");
      exit(-1);
    }

    //Connection between object and shared memory space
    array = (int *) shmat(shmid, NULL, 0)
    if (array == NULL) {
      printf("Error while connecting 'array' with the shared memory space\n");
      exit -1;
    }

  srand(time(NULL));
  arrayFilling(array); //Only executed by parent process

  //Creation of child processes
    if (! fork()) {
      printf("PID Child 1 = %d\n", getpid());
      for (int i = 0; i < 10; i++) askUser(array);
      exit(0);
    }

    if (! fork()) {
      printf("PID Child 2 = %d\n", getpid());
      for (int i = 0; i < 100; i++) changeValues(array);
      exit(0);
    }

    if (! fork()) {
      printf("PID Child 3 = %d\n", getpid());
      for (int i = 0; i < 5; i++) addValuesAndPrint(array);
      exit(0);
    }

  //Parent process wait children ones to finish
  for (int i = 0; i < 3; i++) {
    pid_t pid = wait(&status);
    printf("Child with PID = %d finished with status: %d\n", pid, WEXITSTATUS(status));
  }

return 0;
}
