#include <iostream>
using namespace std;
int factorial(int n){
	int fact=1, i=0;
	while(i<n){
		fact=fact*(n-i);
		i++;
	}
	return fact;
}
int main(){
	int v;
	cout<<"Introduzca el numero del cual desea calcular el factorial:"<<endl;
	cin>>v;
	cout<<"El factorial es "<<factorial(v)<<endl;
}