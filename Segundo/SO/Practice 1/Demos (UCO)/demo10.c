//
//	Programa 1 para demostración de Memoria compartida.
//
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//	Conseguimos una clave para la Memoria compartida. Todos los
//	procesos que quieran compartir la Memoria, deben obtener la misma
//	clave.

#define Clave (key_t) 234

//  La clave también se puede conseguir por medio de la función ftok.
//	A esta función se le pasa un fichero cualquiera que exista y este
//	accesible (todos los procesos deben pasar el mismo fichero) y un
//	entero cualquiera (todos los procesos el mismo entero). El siguiente
//  código debería colocarse al principio del main (ver código comentado)

#define MAX 10

int main()
{
	//key_t Clave;
	int Id_Memoria;
	int *Memoria = NULL;
	int i,j;
    
    /* Clave = ftok ("/bin/ls", 33);
     if (Clave == -1)
     {
     printf("No consigo clave para Memoria compartida\n");
     exit(0);
     }
     */
    
	//  Una vez tenemos la Clave:
	//	Creamos la Memoria con la clave recién conseguida. Para ello llamamos
	//	a la función shmget pasándole la clave, el tamaño de Memoria que
	//	queremos reservar (100 enteros en nuestro caso) y unos flags.
	//	Los flags son  los permisos de lectura/escritura/ejecucion 
	//	para propietario, grupo y otros (es el 777 en octal) y el 
	//	flag IPC_CREAT para indicar que cree la Memoria.
	//	La función nos devuelve un identificador para la Memoria recién
	//	creada.
	//	 
	Id_Memoria = shmget (Clave, sizeof(int)*100, 0777 | IPC_CREAT);
	if (Id_Memoria == -1)
	{
		printf("No consigo Id para Memoria compartida\n");
		exit(0);
	}

	//
	//	Una vez creada la Memoria, hacemos que uno de nuestros punteros
	//	apunte a la zona de Memoria recién creada. Para ello llamamos a
	//	shmat, pasándole el identificador obtenido anteriormente y un
	//	par de parámetros extraños, que con ceros vale.
	//
	Memoria = (int *)shmat (Id_Memoria, (char *)0, 0);
	if (Memoria == NULL)
	{
		printf("No consigo Memoria compartida");
		exit(0);
	}

	//
	//	Ya podemos utilizar la Memoria.
	//	Escribimos cosas en la Memoria. Los números de 1 a 10 esperando
	//	un segundo entre ellos. Estos datos serán los que lea el otro
	//	proceso.
	//
    
	for (i=0; i<10; i++)
	{
		Memoria[i] = i;
		printf("Escrito %d\n",i);

		sleep (1);
	}

	//
	//	Terminada de usar la Memoria compartida, la liberamos.
	//
	shmdt ((char *)Memoria);
	shmctl (Id_Memoria, IPC_RMID, (struct shmid_ds *)NULL);
}
