#include <iostream>
#include <limits>
using namespace std;
int main(){
	cout<<"Introduzca 5 numeros"<<endl;
	int n, menor=std::numeric_limits<int>::max(), i=0, mayor=std::numeric_limits<int>::min(), suma;
	while(i<5){
		cin>>n;
		if(n<menor){
			menor=n;
		}
		if(n>mayor){
			mayor=n;
		}
		i++;
	}
	suma=mayor+menor;
	cout<<"La suma del mayor y el menor de los introducidos es "<<suma<<endl;
cin.ignore();
cin.get();
}