#include <iostream>
#include <limits>
using namespace std;
int main(){
	cout<<"Introduzca numeros, para detener el proceso, introduzca un numero negativo"<<endl;
	float n=0, total=0, i=0, media;
	while(n>=0){
		cin>>n;
		if(n>=0){
			total=total+n;
			i++;
		}
	}
	media=total/i;
	cout<<"La media de los valores introducidos es  "<<media<<endl;
cin.ignore();
cin.get();
}
