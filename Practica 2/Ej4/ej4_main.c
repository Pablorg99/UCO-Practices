#include "ej4_funciones.h"

int main (void) {
  int **matriz;
  int nFil, nCol;
  int *vMins;
  printf("Introduzca un numero cualquiera de filas\n");
  scanf("%i", &nFil);
  printf("Introduzca un numero cualquiera de columnas\n");
  scanf("%i", &nCol);
  matriz = reservarMemoria (nFil, nCol);
  rellenaMatriz (matriz, nFil, nCol);
  imprimeMatriz (matriz, nFil, nCol);
  vMins = minCol (matriz, nFil, nCol);
  printf("\n\nMinimos: ");
  for (int i = 0; i < nCol; i++) {
    printf("%i\t", vMins[i]);
  }
  printf("\n");
  liberarMemoria (matriz, nFil);
  free (vMins);
  return 0;
}
