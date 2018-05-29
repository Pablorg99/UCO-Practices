#ifndef EJ2_H
#define EJ2_H

//2. Dada la siguiente estructura:
typedef struct Ficha_alumno {
char nombre[50];
int DNI;
float nota;
}ficha;
/*------------------------------------------------------------------------------
• Escribe un programa que rellene un vector dinámico de tipo struct Ficha_alumno
  y lo ordene mediante el método de ordenación básico que prefieras (selección,
  inserción o burbuja).
• El vector dinámico se rellenará a partir de los datos de un fichero binario.
• La ordenación se hará usando como campo clave el DNI y podrá ser ascendente o
  descendente.
• La función de ordenación recibirá como parámetro un puntero a una función de
  comparación para realizar la ordenación en uno u otro sentido.
• El programa recibirá dos argumentos en la línea de órdenes:
  - El sentido de la ordenación (ascendente o descendente)
  - El fichero binario con los datos para rellenar el vector
Al terminar el programa, deberá liberar la memoria usada.
------------------------------------------------------------------------------*/


  /**----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  ficha * reservarMemoriaVector(int nEle);

  /*----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  ficha * getArrayFromFile (char *file, int *nEle);

  /*----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  void burbuja(ficha* vector, int izda, int dcha, int(*comparacion)(int, int));

  /*----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  int esMayor(int a, int b);

  /*----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  int esMenor(int a, int b);

  /*----------------------------------------------------------------------------

  ----------------------------------------------------------------------------*/
  void printArray (ficha *vector, int nEle);


#endif
