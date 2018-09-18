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
	if(((c>a)&&(c<b))||((c<a)&&(c>b))){
		cout<<"El numero c esta entre a y b"<<endl;	
	}
	else{
		cout<<"El numero no esta entre a y b"<<endl;
	}		
cin.ignore();
cin.get();
}