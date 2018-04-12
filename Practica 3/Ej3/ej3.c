#include <stdio.h>

int divEntera (int D, int d, int c) {
  if (D <º d) {
    return c;
  }
  else  {
    c++;
    return divEntera (D-d, d, c);
  }
}

int main (void) {
  int Dividendo, divisor, cociente;
  printf("Introduzca el dividendo\n");
  scanf("%i", &Dividendo);
  printf("Introduzca el divisor\n");
  scanf("%i", &divisor);
  cociente = divEntera (Dividendo, divisor, 0);
  printf("%i\n", cociente);
  return 0;
}
