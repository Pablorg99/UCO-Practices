#include <iostream>
using namespace std;
bool esprimo(int n){
	bool primo;
	int ndiv, i=1;
	while(i<=n){
		if(n%i==0){ndiv++;}
			i++;
		}
	if(ndiv<=2){primo=true;}
	else{primo=false;}
 return primo;
}
int main(){
	cout<<"Introduzca un numero:"<<endl;
	int n;
	cin>>n;
	if(esprimo(n)==true){cout<<n<<" es primo"<<endl;}
	else{cout<<n<<" no es primo"<<endl;}
}