#include <stdio.h>
int main(void){
	FILE *f;
	f = fopen ("./directorio/p1","a");
	if (f!=NULL)
	{
		fputs ("Tengo acceso de escritura\n",f);
		fclose (f);
	}
	else{
		printf("ERROR: NO SE PUDO ABRIR EL FICHERO!!\n");
	}
	return 0;
}
