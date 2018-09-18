#include <iostream>
using namespace std;
int main(){
	cout<<"Introduzca un numero entero"<<endl;
	int num;
	cin>>num;
	if(num==0){
		cout<<"El numero es 0"<<endl;
	}
	if(num>0){
		cout<<"El numero es mayor que 0"<<endl;
	}
	if(num<0){
		cout<<"El numero es menor que 0"<<endl;
	}
cin.ignore();
cin.get();
}