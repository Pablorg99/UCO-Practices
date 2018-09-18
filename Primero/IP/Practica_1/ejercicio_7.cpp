#include <iostream>
using namespace std;
int main(){
	float p,ep,ef,nfin;
	cout<<"Introduzca la nota de practicas"<<endl;
	cin>>p;
	cout<<"Introduzca la nota del examen parcial"<<endl;
	cin>>ep;
	cout<<"Introduzca la nota del examen final"<<endl;
	cin>>ef;
	nfin=((p*0.25)+(ep*0.25)+(ef*0.5));
	cout<<"La nota final es "<<nfin<<endl;
cin.ignore();
cin.get();
}