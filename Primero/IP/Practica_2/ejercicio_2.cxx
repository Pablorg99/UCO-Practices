#include <iostream>
using namespace std;
int main(){
	int i=0, n, s=0;
	cout<<"Dada la serie 1+2+3+4+...+n, introduzca el termino n"<<endl;
	cin>>n;
	while(i<=n){
		s=s+i;
		i=i+1;
	}
	cout<<"La suma de la serie hasta el termino introducido es "<<s<<endl;
	cout<<"Pulse Intro para cerrar el programa."<<endl;
cin.ignore();
cin.get();
}