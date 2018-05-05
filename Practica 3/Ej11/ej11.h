#ifndef EJ11_H
#define EJ11_H

/*------------------------------------------------------------------------------
11. Codifica un programa en C que, utilizando funciones, lea números enteros
desde un fichero binario generado en el ejercicio anterior, almacene sus valores
en un vector dinámico y, a continuación, calcule la media de los números pares.
El nombre del fichero se le preguntará al usuario.
------------------------------------------------------------------------------*/

  #define CHAR_NAME 30 //Nº máximo de caracteres del nombre del fichero
  #include <stdio.h>
  #include <stdlib.h> //Permite usar calloc()
  #include <string.h> //Permite usar strlen(), strcpy() y strcat()

  /*----------------------------------------------------------------------------
  Como el fichero que nos interesa está en la carpeta /Ej10/, para acceder a esta
  ruta debemos escribir el directorio que corresponde a esa carpeta desde la
  carpeta /Ej11/ en la que se encuentra el programa.
  En linux, para acceder a la carpeta anterior (Practica 3 en este caso) usamos
  ".." de manera que la ruta que buscamos es "../Ej10/" + "nombreFichero".
  En esta función se concatenan los 2 char * en la cadena dinámica aux. Se
  utiliza strcpy() y strcat() porque no funciona de otro modo con char * (por
  lo que he leído en foros).
  Devuelve un char * que apunta a la cadena concatenada "../Ej10/nombreFichero"
  ----------------------------------------------------------------------------*/
  char* fileInPath (char* file, char* file_path);

  /*----------------------------------------------------------------------------
  Pide al usuario un nombre de fichero por teclado mediante fgets() y cambia el
  '\n' que esta función añade a la cadena por un '\0'
  ----------------------------------------------------------------------------*/
  void pedirNombre (char *file, int nchar);

  /*----------------------------------------------------------------------------
  Esta función reserva memoria para un vector dinámico de enteros con el tamaño
  pasado como argumento y devuelve un puntero a entero que apunta a la dirección
  de memoria reservada.
  ----------------------------------------------------------------------------*/
  int * reservaVectorDinamico (int nEle);

  /*----------------------------------------------------------------------------
  Esta función abre el fichero indicado por el usuario en la carpeta del
  ejercicio 10 y guarda sus datos en un vector. Para ello:
    - Abre el archivo y comprueba que no ha habido errores.
    - Cuenta el numero de elementos del fichero usando fread con un buffer
      auxiliar y tamaño de buffer 1, y guarda dicho valor en nEle.
    - Llama a reservaVectorDinamico() pasando nEle como argumento.
    - Coloca el cursor del fichero en el inicio mediante fseek() (al recorrer el
      fichero con el primer fread(), dicho cursor se coloca al final).
    - Guarda todos los datos del fichero en el vector mediante fread().
    - Cierra el fichero y devuelve el puntero al vector.
  ----------------------------------------------------------------------------*/
  int * getArrayFromFile (char *file, int *nEle);

  /*----------------------------------------------------------------------------
  Esta función recorre el vector devuelto por getArrayFromFile() comprobando si
  el numero de cada posición es divisible entre 2. Si se da el caso, se suma
  el numero a media y aumenta nPar. Una vez recorrido el vector se divide media
  entre nPar, obteniendo así la media de los pares del vector. Por útlimo
  devuelve este dato (de tipo float).
    - Si no hay número pares en el vector devuelve 0.
    - nPar se declara como float para dividir float entre float y que no hayan
      errores.
  ----------------------------------------------------------------------------*/
  float mediaParesVector(int *vector, int nEle);

  /*----------------------------------------------------------------------------
  Esta función imprime el vector pasado como argumento (se debe especificar el
  tamaño del mismo) con un formato tal que: Vector = {u1, u2,...,up} siendo u1
  cada uno de los elementos del vector.
  ----------------------------------------------------------------------------*/
  void printVector (int * vector, int nEle);

#endif
