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


  /*----------------------------------------------------------------------------
  Reserva memoria para un vector de estructuras de nEle elementos (argumento) y
  devuelve un puntero al inicio del mismo.
  ----------------------------------------------------------------------------*/
  ficha * reservarMemoriaVector(int nEle);

  /*----------------------------------------------------------------------------
  Abre el archivo cuyo nombre se ha pasado como argumento. Con fseek, coloco el
  cursor del fichero al final del mismo, y como ftell() indica el número de
  bytes desde el inicio hasta la posición del cursor, dividiendo dicho número
  por sizeof(ficha), obtengo el número de structs que tiene el fichero. Este
  numero se pasa como argumento a reservarMemoriaVector().
  Después de colocar el cursor al principio del fichero de nuevo, paso el fichero
  binario al vector dinámico reservado previamente a través de fread(). La función
  devuelve un puntero al inicio del vector.
  ----------------------------------------------------------------------------*/
  ficha * getArrayFromFile (char *file, int *nEle);

  /*----------------------------------------------------------------------------
  El algoritmo de ordenación burbuja implementado de manera que mediante un
  puntero a funcion, puedo llamar a la función desde el main con esMayor o
  esMenor, para ordenar el vector de manera ascendente o descendente.
  El vector se ordena en funcion del campo DNI del struct, el primer elemento
  del vector (si se ordena de manera ascendente) será aquel cuyo número de DNI
  sea el menor
  ----------------------------------------------------------------------------*/
  void burbuja(ficha* vector, int izda, int dcha, int(*comparacion)(int, int));

  /*----------------------------------------------------------------------------
  Recibe dos números, si a > b devuelve 1. Devuelve 0 en caso contrario.
  ----------------------------------------------------------------------------*/
  int esMayor(int a, int b);

  /*----------------------------------------------------------------------------
  Recibe dos números, si a < b devuelve 1. Devuelve 0 en caso contrario.
  ----------------------------------------------------------------------------*/
  int esMenor(int a, int b);

  /*----------------------------------------------------------------------------
  Imprime por pantalla el vector de estructuras, indicando la posición de cada
  struct y los 3 campos de cada uno.
  ----------------------------------------------------------------------------*/
  void printArray (ficha *vector, int nEle);


#endif
