#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std; 

//cree aqui su funcion
int max(float h[], int n){
	int maxv=h[0];
	for(int i=1;i<n;i++){
		if(maxv<h[i]){
			maxv=h[i];
		}
	}
	return maxv;
}
//// 
int test();//indica que la funcion test esta mas abajo
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
//funcion de test
int test(){
	int errors=0;


	//test 1(all positive)
	float vec[6]={1,2,30,4,5,6};
	if(  max(vec,6)!=30 ) errors++;

	//test 2(all negative)
	float vec2[6]={-1,-2,-30,-4,-5,-6};
	if(  max(vec2,6)!=-1 ) errors++;

	//test 3 bigger
	float vec3[11]={-1,-2,-30,-4,-5,-6,1,2,5,6,10};
	if(  max(vec3,11)!=10 ) errors++;

	return errors;
}	
