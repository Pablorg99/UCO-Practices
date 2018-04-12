#include <stdio.h>

int howManyLetters (char *string, char *character, int ntimes, int counter) {
  if (string[counter] == '\n') return ntimes;
  else {
    if (string[counter] == *character) {
      ntimes++;
      counter++;
      return howManyLetters (string, character, ntimes, counter);
    }
    else {
      counter++;
      return howManyLetters (string, character, ntimes, counter);
    }
  }
}

int main(void) {
  char string[50], character[2];
  int ntimes = 0;
  printf("Introduce una cadena\n");
  fgets (string, 50, stdin);
  printf("Introduce una sola letra\n");
  scanf("%s", character);
  printf("%s\n", character);
  ntimes = howManyLetters (string, character, ntimes, 0);
  printf("La letra %s se repite %d veces en %s", character, ntimes, string);
  return 0;
}
