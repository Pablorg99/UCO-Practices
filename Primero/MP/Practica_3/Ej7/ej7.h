#ifndef EJ7_H
#define EJ7_H

/*------------------------------------------------------------------------------
7. Codifica un programa en C que, utilizando funciones, cree un fichero texto
con números enteros generados aleatoriamente en un intervalo especificado por el
usuario. El programa le preguntará al usuario el nombre del fichero a crear, el
número de elementos que contendrá el fichero y los extremos superior e inferior
del intervalo.
------------------------------------------------------------------------------*/

  #define CHAR_FILE 30 //Nº máximo de caracteres del nombre del fichero
  #include <stdio.h>
  #include <stdlib.h> //Permite usar srand() y rand()
  #include <time.h>   //Permite usar time()
  #include <string.h> //Permite usar strlen()

  /*----------------------------------------------------------------------------
  Pide al usuario un nombre de fichero por teclado mediante fgets() y cambia el
  '\n' que esta función añade a la cadena por un '\0'
  ----------------------------------------------------------------------------*/
  void pedirNombre (char *file, int nchar);

  /*----------------------------------------------------------------------------
  Genera un número aleatorio usando rand() entre los valores min y max que
  también son pedidos por teclado en ej7_main.c
  ----------------------------------------------------------------------------*/
  int randomNumber(int min, int max);

  /*----------------------------------------------------------------------------
  Crea un fichero con el nombre que el usuario ha introducido en pedirNombre().
  Lo rellena mediante fprintf metiendo un numero en cada linea, por cada numero
  que introduce se hace una llamada a randomNumber().
  ----------------------------------------------------------------------------*/
  void rellenarFichero (char *file, int nEle, int min, int max);

#endif
