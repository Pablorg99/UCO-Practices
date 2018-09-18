#include <iostream>
using namespace std;
int main(){
	int a,b,save;
	cout<<"Introduzca un numero entero a:"<<endl;
	cin>>a;
	cout<<"Introduzca un numero entero b:"<<endl;
	cin>>b;
	if(b<a){
		save=a;
		a=b;
		b=save;		
	}
	cout<<"a= "<<a<<endl;
	cout<<"b= "<<b<<endl;
cin.ignore();
cin.get();
}