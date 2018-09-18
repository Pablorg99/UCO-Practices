#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std; 
void invierte(float v1[], float v2[], int n){
	for(int i=0; i<n; i++){
		v2[n-1-i]=v1[i];
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
	float vec2[6];
	
	invierte(vec,vec2,6);
	for(int i=0;i<6;i++) 
		cout<<vec2[i]<<endl;
	if (vec2[0]!=6 || vec2[1]!=5 || vec2[2]!=4 || vec2[3]!=30 || vec2[4]!=2 || vec2[5]!=1 )  errors++;

	return errors;
}	


