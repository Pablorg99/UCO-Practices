#include "ej7.h"

int main() {
  char file[CHAR_FILE];
  int nEle, min, max;

  printf("Indique el nombre del archivo a crear: ");
  pedirNombre (file, CHAR_FILE);

  printf("\nIndique el nº de elementos del archivo: ");
  scanf("%d", &nEle);

  printf("\nEl archivo se llenará con numeros aleatorios entre el rango especificado:");
  printf("\n\tIndique el máximo del intervalo: ");
  scanf("%d", &min);
  printf("\tIndique el mínimo del intervalo: ");
  scanf("%d", &max);

  rellenarFichero(file, nEle, min, max);
}
