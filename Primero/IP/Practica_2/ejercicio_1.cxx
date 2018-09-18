#include <iostream>
using namespace std;
int main(){
	float i=0, media, nval, val, val_tot=0;
	cout<<"Introduzca el numero de valores a los que les quiere hacer la media:"<<endl;
	cin>>nval;
	while(i<nval){
		cout<<"Introduzca un valor: "<<endl;
		cin>>val;
		val_tot=val_tot+val;
		i++;
	}
	media=val_tot/nval;
	cout<<"La media es "<<media<<endl;	
	cout<<"Pulse Intro para cerrar el programa."<<endl;
cin.ignore();
cin.get();
}