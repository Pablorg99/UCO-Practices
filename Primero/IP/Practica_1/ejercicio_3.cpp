#include <iostream>
#include <cmath>
using namespace std;
int main(){
	float x,raiz_x;
	cout<<"Introduzca un numero"<<endl;
	cin>>x;
	if(x<0){
		cout<<"Error, no existe un valor real para la raiz de un numero negativo"<<endl;
	}
	else{
		raiz_x=sqrt(x);
		cout<<"La raiz es "<<raiz_x<<endl;
	}
cin.ignore();
cin.get();
}