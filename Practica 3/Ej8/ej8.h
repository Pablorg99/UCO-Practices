#ifndef EJ8_H
#define EJ8_H

/*------------------------------------------------------------------------------
8. Codifica un programa en C que, utilizando funciones, calcule la media de los
elementos pares que hay en un fichero de texto generado por el ejercicio 7. El
nombre del fichero se pasará como argumento en la línea de órdenes.
------------------------------------------------------------------------------*/

  #define CHAR_FILE 30 //Nº máximo de caracteres del nombre del fichero
  #include <stdio.h>
  #include <stdlib.h> //Permite usar malloc()
  #include <string.h> //Permite usar strlen(), strcpy() y strcat()

  /*----------------------------------------------------------------------------
  Como el fichero que nos interesa está en la carpeta /Ej7/, para acceder a esta
  ruta debemos escribir el directorio que corresponde a esa carpeta desde la
  carpeta /Ej8/ en la que se encuentra el programa.
  En linux, para acceder a la carpeta anterior (Practica 3 en este caso) usamos
  ".." de manera que la ruta que buscamos es "../Ej7/" + "nombreFichero".
  En esta función se concatenan los 2 char * en la cadena dinámica aux. Se
  utiliza strcpy() y strcat() porque no funciona de otro modo con char * (por
  lo que he leído en foros).
  Devuelve un char * que apunta a la cadena concatenada "../Ej7/nombreFichero"
  ----------------------------------------------------------------------------*/
  char* fileInPath (char* file, char* file_path);

  /*----------------------------------------------------------------------------
  Esta función abre el fichero indicado en la línea de órdenes y recorre todo su
  contenido con un bucle while(). Comprueba si el numero leído en cada línea es
  par y si se da el caso, lo suma a la variable media y aumenta el contador.
  Devuelve el valor de la media.
  ----------------------------------------------------------------------------*/
  float mediaPares (char *file);

#endif
