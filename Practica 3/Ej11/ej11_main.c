#include "ej11.h"

int main () {
  char file[30];
  char file_path[CHAR_NAME] = "../Ej10/";
  int *vector;
  int nEle = 0;
  float media;

  printf("Indique el nombre del fichero que busca:\n");
  pedirNombre(file, CHAR_NAME);
  /*----------------------------------------------------------------------------
  Como el fichero que nos interesa está en la carpeta /Ej10/, para acceder a esta
  ruta debemos escribir el directorio que corresponde a esa carpeta desde la
  carpeta /Ej11/ en la que se encuentra el programa.
  En linux, para acceder a la carpeta anterior (Practica 3 en este caso) usamos
  ".." de manera que la ruta que buscamos es "../Ej10/" + "nombreFichero".
  Para concatenar estas cadenas utilizo sprintf().
  ----------------------------------------------------------------------------*/
  sprintf (file_path, "%s%s", file_path, file);

  vector = getArrayFromFile(file_path, &nEle);
  printf("El vector obtenido del fichero binario es:\n");
  printVector(vector, nEle);
  media = mediaParesVector(vector, nEle);
  printf("La media de los numeros pares del fichero es: %f\n", media);

  free(vector);
  return 0;
}
