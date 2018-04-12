#include "ej4_funciones.h"

void imprimeMatriz (int **matriz, int nFil, int nCol) {
  for (int i = 0; i < nFil; i++) {
    printf("\n");
    for (int j = 0; j < nCol; j++) {
      printf("%i\t", *(*(matriz+i)+j));
    }
  }
}
