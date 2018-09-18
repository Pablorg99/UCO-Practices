#include <iostream>
using namespace std;
int main(){

	float a,b,c;
	cout<<"Introduzca un numero a:"<<endl;
	cin>>a;
	cout<<"Introduzca un numero b:"<<endl;
	cin>>b;	
	cout<<"Introduzca un numero c:"<<endl;
	cin>>c;

	if((c>a)&&(c>b)){
		cout<<"El numero mayor es "<<c<<endl;	
	 }
	if((a>c)&&(a>b)){
		cout<<"El numero mayor es "<<a<<endl;	
	 }
	if((b>a)&&(b>c)){
		cout<<"El numero mayor es "<<b<<endl;	
	 }
	
cin.ignore();
cin.get();
}