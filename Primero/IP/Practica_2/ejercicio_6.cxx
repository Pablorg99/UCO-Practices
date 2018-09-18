#include <iostream>
using namespace std;
int main(){
	int i, n;	
	cout<<"Introduzca un numero para obtener sus divisores:"<<endl;
	cin>>n;
	i=n;
	while(i>0){
		if((n%i)==0){
			cout<<i<<endl;		
		}
	i=i-1;
	}
	cout<<"Pulse Intro para cerrar el programa."<<endl;
cin.ignore();
cin.get();
}