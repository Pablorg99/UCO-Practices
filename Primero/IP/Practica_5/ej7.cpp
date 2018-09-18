#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std; 
void suma(float v1[], float v2[], float v3[], int n){
	for(int i=0; i<n; i++){
		v3[i]=v1[i]+v2[i];
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


	//test 1(all positive)
	float vec[6]={1,2,30,4,5,6};
	float vec2[6]={1,2,30,4,5,6};
	float vec3[6]; 

	suma(vec,vec2,vec3,6);
	if (vec3[0]!=2 || vec3[1]!=4 || vec3[2]!=60 || vec3[3]!=8 || vec3[4]!=10 || vec3[5]!=12 )  errors++;

	return errors;
}	


