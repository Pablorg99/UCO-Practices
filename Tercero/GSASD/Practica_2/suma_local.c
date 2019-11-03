#include <stdio.h>
#include <stdlib.h>

void add(int number1, int number2);

int main(int argc, char const *argv[]) {
    int number1, number2;

    if(argc != 3) {
        fprintf(stderr, "uso: %s <NÚMERO 1> <NÚMERO 2>\n", argv[0]);
        exit(1);
    }
    number1 = atoi(argv[1]);
    number2 = atoi(argv[2]);
    add(number1, number2);
    return 0;
}

void add(int number1, int number2) {
    int result = number1 + number2;
    printf("El resultado de la suma es %d\n", result);
}
