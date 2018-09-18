#include <iostream>
using namespace std;
int main(){
	int num,par;
	cout<<"Introduzca un numero entero"<<endl;
	cin>>num;
	par=num%2;
	switch(par){
		case 0:{
			cout<<"El numero es par"<<endl;		
		}break;
		default:{
			cout<<"El numero es impar"<<endl;
		}
	}
cin.ignore();
cin.get();
}