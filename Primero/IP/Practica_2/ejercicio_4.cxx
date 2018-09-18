#include <iostream>
using namespace std;
int main(){
	int i=0, n, s=0, c;
	cout<<"Dada la serie 1+2+3+4+...+n, introduzca el termino n"<<endl;
	cin>>n;
	while(i<=n){
		c=i%2;
		if(c!=0){
			s=s+i;
		}
		i=i+1;
	}
	cout<<"La suma de los numeros impares de la serie hasta el termino introducido es "<<s<<endl;
	cout<<"Pulse Intro para cerrar el programa."<<endl;
cin.ignore();
cin.get();
}