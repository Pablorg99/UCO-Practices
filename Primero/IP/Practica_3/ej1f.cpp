#include <iostream>
#include <limits>
using namespace std;
int main(){
	cout<<"Introduzca 5 numeros"<<endl;
	int n, menor=std::numeric_limits<int>::max(), i=0;
	for(;i<5; i++){
		cin>>n;
		if(n<menor){
			menor=n;
		}
	}
	cout<<"El numero menor de los introducidos es "<<menor<<endl;
cin.ignore();
cin.get();
}