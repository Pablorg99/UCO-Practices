#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std; 
  int divisores(int val, int div[], int n){
	int ndiv=0, i=1;
	while((i<=val)&&(ndiv<n)){
		if(val%i==0){
			div[ndiv]=i;
			ndiv++;
		}
	i++;
	}
	return ndiv;
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
	int vsize=5;
	int div[vsize];//crea el vector
	//llama a la funcion para el valor 10 
	int nd= divisores(10,div,vsize);
	//comprueba validez del resultado
	if (nd!=4 || div[0]!=1 || div[1]!=2 || div[2]!=5 || div[3]!=10) errors++;
	
	//ahora el 1
	nd= divisores(1,div,vsize);
	if (nd!=1 || div[0]!=1)  errors=0;
	
	//ahora el 1
	nd= divisores(2,div,vsize);
	if (nd!=2 || div[0]!=1   || div[1]!=2   ) errors++;

	//ahora el 32824, tiene 16 divisores, pero no deberian calcularse mas de 5
	nd= divisores(32824,div,vsize);
	if (nd!=vsize || div[0]!=1   || div[1]!=2 || div[2]!=4 || div[3]!=8 || div[4]!=11    ) errors++;
 
 
 return errors;
}	


