#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std; 
 int sum_even(int v[], int n){
	int sum=0;
	for(int i=0; i<n; i++){
		if(v[i]%2==0) sum+=v[i];
	} 
	return sum;
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
	int v1[10]={1,2,2,3,1,2,2,3,4,5};//crea el vector
	if ( sum_even(v1,10)!=12) errors++;
	 
	int v2[12]={1,2,2,3,1,2,2,3,4,5,10,11};//crea el vector
	if ( sum_even(v2,12)!=22) errors++;
 
	int v3[12]={10,2,2,3,1,2,2,3,4,5,10,11};//crea el vector
	if ( sum_even(v3,12)!=32) errors++;

	int v4[1]={10};//crea el vector
	if ( sum_even(v4,1)!=10) errors++;
	int v5[1]={1};//crea el vector
	if ( sum_even(v5,1)!=0) errors++;
	int v6[12]={1,1,1,3,1,1,1,3,1,5,1,11};//crea el vector
	if ( sum_even(v6,12)!=0) errors++;
 return errors;
}	


