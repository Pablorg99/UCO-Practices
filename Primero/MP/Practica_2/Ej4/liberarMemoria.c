#include "ej4_funciones.h"

void liberarMemoria (int **matriz, int nFil) {
  for (int i = 0; i < nFil; i++) {
    free (matriz[i]);
  }
  free (matriz);
}
