#include <stdio.h>

int mcd (int x, int y) {
  if (x == 0) return y;
  if (y == 0) return x;
  if (x >= y && y > 0) {
    return mcd (y, x%y);
  }
  if (y >= x && x > 0) {
    return mcd (x, y%x);
  }
}

int main(void) {
  int x, y, MCD;
  printf("Introduzca un valor para x: ");
  scanf("%d", &x);
  printf("Introduzca un valor para y: ");
  scanf("%d", &y);
  MCD = mcd (x,y);
  printf("El MCD de %d y %d es %d\n", x, y, MCD);
  return 0;
}
