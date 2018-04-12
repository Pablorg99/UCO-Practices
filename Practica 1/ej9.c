#include <stdio.h>

struct monomio{
  int grado;
  int coeficiente;
};

void leerMonomio(struct monomio *ptrmonomio){
    printf("Introduzca el grado del monomio:\n");
    scanf("%i", &ptrmonomio->grado);
    printf("Introduzca el coeficiente del monomio:\n");
    scanf("%i", &ptrmonomio->coeficiente);
}

void imprimirMonomio(struct monomio *ptrmonomio){
  printf("grado: %i \ncoeficiente: %i\n", ptrmonomio->grado, ptrmonomio->coeficiente);
}

int main(int argc, char const *argv[]) {
  int x;
  printf("Cuantos monomios va a tener el polinomio?\n");
  scanf("%i", &x);
  struct monomio polinomio[x];
  for (int i = 0; i < x; i++) {
    printf("Datos monomio nº %i\n", i+1);
    leerMonomio(polinomio+i);
  }
  for (int i = 0; i < x; i++) {
    printf("Monomio nº %i\n", i+1);
    imprimirMonomio(polinomio+i);
  }
  return 0;
}
