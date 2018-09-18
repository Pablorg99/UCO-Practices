#include <iostream>
#include <cmath>
using namespace std;
int main(){

	float x1,y1,x2,y2,mod;
	cout<<"Introduzca las coordenadas de 2 puntos"<<endl;

	cout<<"Punto 1:"<<endl;
	cout<<"x1="; cin>>x1;
	cout<<"y1="; cin>>y1;

	cout<<"Punto 2:"<<endl;
	cout<<"x2="; cin>>x2;
	cout<<"y2="; cin>>y2;

	mod=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
	cout<<"La distancia entre los puntos es "<<mod<<endl;
	
cin.ignore();
cin.get();
}