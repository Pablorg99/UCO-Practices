#include <iostream>
using namespace std;
int main(){
	int n, ndiv;
	cout<<"Introduzca un numero"<<endl;
	cin>>n;
	for(int i=1; i<n; i++){
		if(n%i==0){
			ndiv++;
		}
	}
	if(ndiv<=2){
		cout<<n<<" es primo."<<endl;
	}
	if(ndiv>=3){
		cout<<n<<" no es primo"<<endl;
	}
cout<<"Pulse Intro para cerrar el programa."<<endl;
cin.ignore();
cin.get();
}