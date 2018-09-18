#include <iostream>
using namespace std;
int main(){
	int i=1, n;	
	cout<<"Introduzca un numero para obtener sus divisores:"<<endl;
	cin>>n;
	while(i<=n){
		if((n%i)==0){
			cout<<i<<endl;		
		}
	i++;
	}
	cout<<"Pulse Intro para cerrar el programa."<<endl;
cin.ignore();
cin.get();
}