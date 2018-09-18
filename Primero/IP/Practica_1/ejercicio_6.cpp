#include <iostream>
using namespace std;
int main(){
	float a,b,c,d,med;
	cout<<"Introduzca un primer numero"<<endl;
	cin>>a;
	cout<<"Introduzca un segundo numero"<<endl;
	cin>>b;
	cout<<"Introduzca un tercer numero"<<endl;
	cin>>c;
	cout<<"Introduzca un cuarto numero"<<endl;
	cin>>d;
	med=(a+b+c+d)/4;
	cout<<"La media de los numeros introducidos es "<<med<<endl;
cin.ignore();
cin.get();
}