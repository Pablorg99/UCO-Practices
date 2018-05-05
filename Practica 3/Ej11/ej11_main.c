#include "ej11.h"

int main () {
  char file[CHAR_NAME];
  char *file_path = "../Ej10/";
  int *vector;
  int nEle = 0;
  float media;

  printf("Indique el nombre del fichero que busca:\n");
  pedirNombre(file, CHAR_NAME);
  file_path = fileInPath(file, file_path);

  vector = getArrayFromFile(file_path, &nEle);
  printf("El vector obtenido del fichero binario es:\n");
  printVector(vector, nEle);
  media = mediaParesVector(vector, nEle);
  printf("La media de los numeros pares del fichero es: %f\n", media);

  free(vector);
  free (file_path);
  return 0;
}
