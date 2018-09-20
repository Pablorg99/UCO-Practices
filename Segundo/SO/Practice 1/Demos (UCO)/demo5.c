#include <stdio.h> 
#include <stdlib.h>

int main(void) 
{
    char *home = NULL;
    home = getenv("HOME"); 
    if (home == NULL)
        printf("$HOME no se encuentra definida\n"); 
    else
        printf("El valor de $HOME es %s\n", home); 
}