#include <iostream>
using namespace std;
int main(){
	int n, i=0, fact=1;
	cout<<"Introduzca el del valor del cual quiere conocer el factorial:"<<endl;
	cin>>n	;
	while(i<n){
		fact=fact*(n-i);
		i++;
	}
	cout<<"El factorial es "<<fact<<endl;	
cout<<"Pulse Intro para cerrar el programa."<<endl;
cin.ignore();
cin.get();
}