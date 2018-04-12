#include "ej4_funciones.h"

int ** reservarMemoria (int nFil, int nCol) {
  int **matriz;
  matriz = (int**) calloc (nFil, sizeof(int *));
  for (int i = 0; i < nFil; i++) {
    matriz[i] = (int *) calloc (nCol, sizeof(int));
  }
  if (matriz == NULL) printf("Fallo en la reserva de memoria\n");
  else return matriz;
}
