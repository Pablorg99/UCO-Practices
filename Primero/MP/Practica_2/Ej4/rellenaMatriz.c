#include "ej4_funciones.h"

void rellenaMatriz (int** matriz, int nFil, int nCol) {
  srand(time(NULL));
  for (int i = 0; i < nFil; i++) {
    for (int j = 0; j < nCol; j++) {
      matriz[i][j] = (rand() % 20) + 1;
    }
  }
}
