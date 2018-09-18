#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void factoriales(int fact[], int n){
	int f=1;
	for(int i=0; i<n; i++){
		if(i==0) fact[i]=f;
		else	{
			f=f*i;
			fact[i]=f;
		}
	}
}
//// 
int test();
int main(){ 
		int nerrors=test();
		if (nerrors==0){
			cout<<"Correcto "<<endl;
		}
		else{
			cout<<"Hay "<<nerrors<<" errores en el test"<<endl;
		}
		system("pause");
}

int test(){
	int errors=0;
	//llama a la funcion para el valor 10 
	int fact[10]={0,0,0,0,0,0,0,0,0,0};//crea el vector
	factoriales( fact,1);	
	//comprueba validez del resultado y que no se ha escrito fuera de la zona esperada
	if ( fact[0]!=1  || fact[1]!=0 ||   fact[2]!=0 ||  fact[3]!=0 ||   fact[4]!=0 ||  fact[5]!=0 ||  fact[6]!=0 ||  fact[7]!=0 ||  fact[8]!=0 ||  fact[9]!=0   ) errors++;
	factoriales( fact,2);	
	//comprueba validez del resultado y que no se ha escrito fuera de la zona esperada
	if ( fact[0]!=1  || fact[1]!=1 ||   fact[2]!=0 ||  fact[3]!=0 ||   fact[4]!=0 ||  fact[5]!=0 ||  fact[6]!=0 ||  fact[7]!=0 ||  fact[8]!=0 ||  fact[9]!=0   ) errors++;
	factoriales( fact,3);	
	//comprueba validez del resultado y que no se ha escrito fuera de la zona esperada
	if ( fact[0]!=1  || fact[1]!=1 ||   fact[2]!=2 ||  fact[3]!=0 ||   fact[4]!=0 ||  fact[5]!=0 ||  fact[6]!=0 ||  fact[7]!=0 ||  fact[8]!=0 ||  fact[9]!=0   ) errors++;
	factoriales( fact,4);	
	//comprueba validez del resultado y que no se ha escrito fuera de la zona esperada
	if ( fact[0]!=1  || fact[1]!=1 ||   fact[2]!=2 ||  fact[3]!=6 ||   fact[4]!=0 ||  fact[5]!=0 ||  fact[6]!=0 ||  fact[7]!=0 ||  fact[8]!=0 ||  fact[9]!=0   ) errors++;
	factoriales( fact,5);	
	//comprueba validez del resultado y que no se ha escrito fuera de la zona esperada
	if ( fact[0]!=1  || fact[1]!=1 ||   fact[2]!=2 ||  fact[3]!=6 ||   fact[4]!=24 ||  fact[5]!=0 ||  fact[6]!=0 ||  fact[7]!=0 ||  fact[8]!=0 ||  fact[9]!=0   ) errors++;
	factoriales( fact,10);	
 	//comprueba validez del resultado y que no se ha escrito fuera de la zona esperada
	if ( fact[0]!=1  || fact[1]!=1 ||   fact[2]!=2 ||  fact[3]!=6 ||   fact[4]!=24 ||  fact[5]!=120 ||  fact[6]!=720 ||  fact[7]!=5040 ||  fact[8]!=40320 ||  fact[9]!=362880   ) errors++;

 return errors;
}	


