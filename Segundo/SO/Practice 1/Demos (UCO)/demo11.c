//
//	Programa 2 para demostración de Memoria compartida.
//
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define Clave (key_t) 234
#define MAX 10

int main()
{
	int Id_Memoria;
	int *Memoria = NULL;
	int i,j;
    
	//	Igual que en demo10.c, obtenemos el id de la memoria. Al no poner
	//	el flag IPC_CREAT, estamos suponiendo que dicha memoria ya está
	//	creada.
	//
	Id_Memoria = shmget (Clave, sizeof(int)*100, 0777 );
	if (Id_Memoria == -1)
	{
		printf("No consigo Id para Memoria compartida\n");
		exit (0);
	}
    
	//
	//	Igual que en demo10.c, obtenemos un puntero a la memoria compartida
	//
	Memoria = (int *)shmat (Id_Memoria, (char *)0, 0);
	if (Memoria == NULL)
	{
		printf("No consigo Memoria compartida");
		exit (0);
	}
    
	//
	//	Vamos leyendo el valor de la memoria con esperas de un segundo
	//	y mostramos en pantalla dicho valor. Debería ir cambiando según
	//	p1 lo va modificando.
	//
	for (i=0; i<10; i++)
	{
		printf("Leido %d\n",Memoria[i]);
		sleep (3);
	}
    
	//
	//	Desasociamos nuestro puntero de la memoria compartida. Suponemos
	//	que p1 (el proceso que la ha creado), la liberará.
	//
	if (Id_Memoria != -1)
	{
		shmdt ((char *)Memoria);
	}
}
