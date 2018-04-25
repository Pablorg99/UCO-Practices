#include "ej10.h"

int main(int argc, char const *argv[]) {
  if (argc != 5) {
    printf("Introduce únicamente estos argumentos separados por espacios: \
    nombreFichero numeroElementosFichero numeroMáximo númeroMínimo\n");
    exit(-1);
  }
  char *file = argv[1];
  char *ptr;
  int nEle = strtol(argv[2], &ptr, 10);
  int max = strtol(argv[3], &ptr, 10);
  int min = strtol(argv[4], &ptr, 10);
  int *vector;

  vector = vectorDeAleatorios(nEle, min, max);
  writeInFile(file, vector, nEle);

  free(vector);
  return 0;
}
