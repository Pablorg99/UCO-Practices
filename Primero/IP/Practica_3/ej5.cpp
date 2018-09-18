#include <iostream>
using namespace std;
int main(){
	int n;	
	cout<<"Introduzca un numero para obtener sus divisores:"<<endl;
	cin>>n;
	for(int i=1; i<=n; i++){
		if((n%i)==0){
			cout<<i<<endl;		
		}
	}
	cout<<"Pulse Intro para cerrar el programa."<<endl;
cin.ignore();
cin.get();
}