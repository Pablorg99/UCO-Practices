#include <iostream>
#include <limits>
using namespace std;
int main(){
	cout<<"Introduzca numeros, para detener el proceso, introduzca un numero negativo"<<endl;
	int n=0, mayor=std::numeric_limits<int>::min();
	while(n>=0){
		cin>>n;
		if(n>mayor){
			mayor=n;
		}
	}
	cout<<"El numero mayor de los introducidos es "<<mayor<<endl;
cin.ignore();
cin.get();
}
