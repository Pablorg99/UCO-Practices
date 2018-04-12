#include <stdio.h>
#include <string.h>

int es_prefijo(char *cadena, char *prefijo){
  if(cadena == (strstr(cadena, prefijo))) return 1;
  else return 0;
}

int es_sufijo(char *cadena, char *sufijo){
  if((cadena + (strlen(cadena)) - (strlen(sufijo))) == strstr(cadena, sufijo)) return 1;
  else return 0;
}

int main(int argc, char const *argv[]) {
  char cadena[15];
  char morfema[10];
  printf("Introduce una palabra con un sufijo o un prefijo\n");
  scanf("%s", cadena);
  printf("Introduce uncamente el sufijo o prefijo utilizado\n");
  scanf("%s", morfema);

  if((es_prefijo(cadena, morfema)) == 1) printf("%s es un prefijo\n", morfema);
  if((es_sufijo(cadena, morfema)) == 1) printf("%s es un sufijo\n", morfema);
  else printf("%s no es ni sufijo ni prefijo\n", morfema);
  return 0;
}
