#include <stdio.h>

int minimo(int num1, int num2){
  if(num1<num2) return num1;
  else return num2;
}

void minimo_referencia(int *num1, int *num2){
  if(*num1<*num2) *num2 = *num1;
}

int main(int argc, char const *argv[]) {
  int num1, num2, resultado;
  printf("Introduzca dos numeros enteros\n");
  scanf("%i", &num1);
  scanf("%i", &num2);
  printf("Funcion minimo: %i\n", minimo(num1, num2));
  minimo_referencia(&num1, &num2);
  printf("Funcion minimo_referencia: %i\n", num2);
  return 0;
}
