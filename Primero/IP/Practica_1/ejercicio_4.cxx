#include <iostream>
using namespace std;
int main(){
	int dia;
	cout<<"Introduzca un numero entero"<<endl;	
	cin>>dia;
	if((dia>=1)&&(dia<=5)){
		cout<<"Dia laborable"<<endl;
	}
	if((dia==6)||(dia==7)){
		cout<<"Fin de semana"<<endl;
	}
	if((dia>7)||(dia<1)){
		cout<<"Error, el numero introducido no esta en el rango"<<endl;
	}	
cin.ignore();
cin.get();
}