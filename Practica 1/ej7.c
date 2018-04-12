#include <stdio.h>
#include <math.h>

void leerVector(int *x, int *v){
  printf("Introduzca el numero de elementos del vector\n");
  scanf("%i", x);
  for (int i = 0; i < *x; i++) {
    printf("Introduzca el elemento numero %i: ", i);
    scanf("%i", v+i);
  }
}

void imprimeVector(int *x, int *v){
  printf("\nEl vector tiene %i elementos\n", *x);
  for (int i = 0; i < *x; i++) {
    printf("El elemento %i es: %i\n", i, *(v+i));
  }
}

void estadisticasVector(int *x, int *v, float *media, float *varianza, float *desvt){
  for (int i = 0; i < *x; i++) {
    *media += v[i];
    *varianza += v[i]*v[i];
  }
  *media /= *x;
  *varianza /= *x;
  *varianza -= (*media)*(*media);
  *desvt = sqrt(*varianza);
}

void imprimeEstadisticas(int *x, int *v, float *media, float *varianza, float *desvt){
  printf("\nLa media de los elementos del vector es: %f\n", *media);
  printf("La varianza de los elementos del vector es: %f\n", *varianza);
  printf("La desviacion tipica de los elementos del vector es: %f\n", *desvt);
}

int main(void) {
  int x = 1;
  int v[x];
  float  media = 0, varianza = 0, desvt = 0;
  leerVector(&x, v);
  imprimeVector(&x, v);
  estadisticasVector(&x, v, &media, &varianza, &desvt);
  imprimeEstadisticas(&x, v, &media, &varianza, &desvt);
  return 0;
}
