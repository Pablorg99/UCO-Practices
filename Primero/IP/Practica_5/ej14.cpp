#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std; 
void ordena_vector(int v[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(v[i] > v[j]){
				int aux=v[i];
				v[i]=v[j];
				v[j]=aux;
			}
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
		//print output
		
		system("pause");
}

void fijaValoresAleatorios(int v[],int n,int max){
	for(int i=0;i<n;i++) v[i]=rand()%(max+1);
}

bool estaordenado(int v[],int n){
	for(int i=1;i<n;i++)
		if (v[i-1]>v[i]) return false;
	return true;
}
int test(){
	int errors=0;
	//llama a la funcion para el valor 10 
	
	
	//test: comprueba que los valores estan en orden ascendente
	int v[10]={4,2,24,3,15,2,62,3,4,5};//crea el vector
	cout<<"test 1"<<endl;
	ordena_vector(v,10);
	if (!estaordenado(v,1)) return 1;
		
		
	//test: comprueba que los valores estan en orden ascendente
	int v2[2]={4,2};//crea el vector
	cout<<"test 2"<<endl;
	ordena_vector(v2,2);
	if (!estaordenado(v2,2)) return 1;

		
	//test: comprueba que los valores estan en orden ascendente
	int v3[1]={2};//crea el vector
	cout<<"test 3"<<endl;
	ordena_vector(v3,1);
	if (!estaordenado(v3,1)) return 1;
	///no check needed here
	
	
	int v4[10]={-4,-2,-24,-3,-15,-2,-62,-3,-4,-5};//crea el vector
	cout<<"test 4"<<endl;
	ordena_vector(v4,10);
	if (!estaordenado(v4,10)) return 1;

   //now, a set of random tests
   srand(0);
	int vt[100];
	for(int i=0;i<1000;i++){
		fijaValoresAleatorios(vt,100,100);
		ordena_vector(vt,100);
		if (!estaordenado(vt,100)) return 999;
	}
				
 return errors;
}	


