#ifndef EJ10_H
#define EJ10_H

/*------------------------------------------------------------------------------
10. Codifica un programa en C que, utilizando funciones, cree un fichero binario
con números enteros generados aleatoriamente en un intervalo especificado por el
usuario. El programa guardará los números en un vector dinámico antes de
volcarlo a disco. El programa recibirá 4 parámetros como argumentos en la línea
de órdenes: nombre del fichero a crear, número de elementos que contendrá el
fichero y los extremos superior e inferior del intervalo.
------------------------------------------------------------------------------*/

  #include <stdio.h>
  #include <stdlib.h> //Permite usar srand() y rand()
  #include <time.h>   //Permite usar time()

  /*----------------------------------------------------------------------------
  Genera un número aleatorio usando rand() entre los valores min y max que
  también son pedidos por teclado en ej7_main.c
  ----------------------------------------------------------------------------*/
  int randomNumber(int min, int max);

  /*----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  void writeInFile (char *file, int* vector, int nEle);

  /*----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  int * vectorDeAleatorios (int nEle, int min, int max);

#endif
