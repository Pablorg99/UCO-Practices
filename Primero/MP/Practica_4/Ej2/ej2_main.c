#include "ej2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printf("Uso: ./a.out <nombreBinario> <ascendente/descendente>\n");
    exit(-1);
  }

  ficha *vector;
  int nFichas = 0;
  char file[30];
  strcpy(file, argv[1]);  //strcpy() para que no de warning
  char orden[30];
  strcpy(orden, argv[2]); //strcpy() para que no de warning

  char file_path[30] = "Ficheros_Moodle/";
  sprintf (file_path, "%s%s", file_path, file);

  vector = getArrayFromFile (file_path, &nFichas);
  printf("------------VECTOR SIN ORDENAR------------\n");
  printArray(vector, nFichas);

  if (strcmp(orden, "ascendente") == 0) burbuja (vector, 0, nFichas - 1, &esMayor);
  if (strcmp(orden, "descendente") == 0) burbuja (vector, 0, nFichas - 1, &esMenor);

  printf("\n------------VECTOR ORDENADO------------\n");
  printArray(vector, nFichas);
  free (vector);
  return 0;
}
