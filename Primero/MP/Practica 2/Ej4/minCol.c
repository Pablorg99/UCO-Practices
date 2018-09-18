#include "ej4_funciones.h"

int * minCol (int **matriz, int nFil, int nCol) {
  int *vMins;
  vMins = (int *) calloc (nCol, sizeof(int));
  for (int i = 0; i < nCol; i++) {
    vMins[i] = matriz[0][i];
    for (int j = 1; j < nFil; j++) {
      if(vMins[i] > matriz[j][i]) vMins[i] = matriz[j][i];
    }
  }
  return vMins;
}
