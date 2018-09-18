#include <iostream>
using namespace std;
void lee(float v[], int n){
	cout<<"Introduzca valores para el vector v"<<endl;
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
}
void imprime(float v[], int n){
	cout<<"Los valores introducidos son"<<endl;
	for(int i=0; i<n; i++){
		cout<<v[i]<<endl;
	}
}
int main(){
	float v[10];
	lee(v,10);
	imprime(v,10);
}