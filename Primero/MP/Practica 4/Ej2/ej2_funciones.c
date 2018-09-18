#include "ej2.h"
#include <stdio.h>
#include <stdlib.h>

ficha * reservarMemoriaVector(int nEle) {
  ficha *ptrv;
  if ((ptrv = malloc(nEle * sizeof(ficha))) == NULL) {
    printf("Error al reservar memoria\n");
    exit(-3);
  }
  return ptrv;
}


ficha * getArrayFromFile (char *file, int *nEle) {
  FILE *f;
  ficha *vector;

  if ((f = fopen(file, "rb")) == NULL) {
    printf("Error al abrir el fichero <%s>\n", file);
    exit(-2);
  }

  fseek(f, 0L, SEEK_END);
  *nEle = ftell(f) / sizeof(ficha);
  vector = reservarMemoriaVector (*nEle);

  fseek(f, 0L, SEEK_SET);
  if ((fread (vector, sizeof(ficha), *nEle, f)) != *nEle) {
    printf("Error en la lectura del fichero\n");
    exit(-4);
  }

  fclose(f);
  return vector;
}

void burbuja(ficha* vector, int izda, int dcha, int(*comparacion)(int, int)) {
  int i, j;
  ficha aux;
  for(i = izda + 1; i <= dcha; i++) {
    for(j = dcha; j >= i; j--) {
      if((*comparacion) (vector[j-1].DNI, vector[j].DNI)) {
        aux = vector[j];
        vector[j] = vector[j-1];
        vector[j-1] = aux;
      }
    }
  }
}

int esMayor(int a, int b) {
  if (a > b) return 1;
  else return 0;
}

int esMenor(int a, int b) {
  if (a < b) return 1;
  else return 0;
}

void printArray (ficha *vector, int nEle) {
  for (int i = 0; i < nEle; i++) {
    printf("\nJugador nº %d:\n", i + 1);
    printf("\tNombre: %s\n", vector[i].nombre);
    printf("\tDNI: %d\n", vector[i].DNI);
    printf("\tNota: %f\n", vector[i].nota);
  }
}
