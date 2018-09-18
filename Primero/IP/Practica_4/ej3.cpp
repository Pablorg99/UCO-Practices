#include <iostream>
using namespace std;
float media(int n){
	float media, total=0, val;
	int i=0;
	cout<<"Introduzca los valores:"<<endl;
	while(i<n){
		cin>>val;
		total=total+val;
		i++;
	}
	media=total/n;
	return media;		
}
int main(){
	cout<<"Introduzca el numero de valores a los que desea calcular la media:"<<endl;
	int n;
	cin>>n;
	cout<<"La media de los datos introducidos es "<<media(n)<<endl;
}