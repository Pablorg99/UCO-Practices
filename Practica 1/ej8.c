#include <stdio.h>
#include <ctype.h>

void estadisticasCadena(char *cad, int *ndigit, int *nmayus, int *nminus, int *nespacios){
  for (int i = 0; cad[i] != '\0'; i++) {
    if(isdigit(cad[i])) (*ndigit)++;
    if(islower(cad[i])) (*nminus)++;
    if(isupper(cad[i])) (*nmayus)++;
    if(isspace(cad[i])) (*nespacios)++;
  }
  printf("La cadena tiene %i digitos\n", *ndigit);
  printf("La cadena tiene %i minusculas\n", *nminus);
  printf("La cadena tiene %i mayusculas\n", *nmayus);
  printf("La cadena tiene %i espacios\n", *nespacios);
}

int main(int argc, char const *argv[]) {
  int ndigit = 0, nmayus = 0, nminus = 0, nespacios = 0;
  char *cad;
  printf("Introduzca una cadena de caracteres:\n");
  gets(cad);
  estadisticasCadena(cad, &ndigit, &nmayus, &nminus, &nespacios);
  return 0;
}
