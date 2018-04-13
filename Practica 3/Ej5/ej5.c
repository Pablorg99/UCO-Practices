#include <stdio.h>
#include <string.h>

int addDigits (char* entry, int result, int counter) {
  if (entry[counter] == '\0') return result;
  else {
    result += (int) entry[counter] - 48; //48 es el valor de 0 en código ascii (decimal)
    counter++;
    addDigits (entry, result, counter);
  }
}
int main(void) {
  char entry[15];
  int result;
  printf("Introduzca un numero entero: ");
  scanf("%s", entry);
  result = addDigits (entry, result, 0);
  printf("\nLa suma de sus digitos es: %d\n", result);
  return 0;
}
