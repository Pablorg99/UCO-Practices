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
  #include <string.h> //Permite usar strcpy()

  /*----------------------------------------------------------------------------
  Genera un número aleatorio usando rand() entre los valores min y max que
  vienen dados como argumentos en la línea de ordenes
  ----------------------------------------------------------------------------*/
  int randomNumber(int min, int max);

  /*----------------------------------------------------------------------------
  Crea un vector dinámico con el tamaño de nEle (especificado en un argumento en
  la línea de órdenes), pone srand(time) a NULL y recorre el vector, asignandole
  a cada uno de sus elementos el entero devuelto por randomNumber(). Por último
  devuelve un puntero al vector.
  ----------------------------------------------------------------------------*/
  int * vectorDeAleatorios (int nEle, int min, int max);

  /*----------------------------------------------------------------------------
  Esta función imprime el vector pasado como argumento (se debe especificar el
  tamaño del mismo) con un formato tal que: Vector = {u1, u2,...,up} siendo u1
  cada uno de los elementos del vector.
  ----------------------------------------------------------------------------*/
  void printVector (int * vector, int nEle);

  /*----------------------------------------------------------------------------
  Crea un fichero con el nombre especificado en la línea de órdenes, y si no se
  produce ningún error, escribe el vector de aleatorios creado durante la
  ejecución del programa en el fichero binario usando fwrite.
  ----------------------------------------------------------------------------*/
  void writeInFile (char *file, int* vector, int nEle);

  /*----------------------------------------------------------------------------
  Esta función lee los datos del fichero binario creado en writeInFile() y los
  guarda en un vector dinamico (usando fread()) que devuelve al main.
  ----------------------------------------------------------------------------*/
  int * readFile (char* file, int*  vector, int nEle);


#endif
