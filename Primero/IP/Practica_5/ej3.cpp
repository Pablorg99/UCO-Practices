#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;
void fijaValorAleatorio(int v[], int n, int max){
	srand(time(0));
	for(int i=0; i<n; i++){
		int x=rand()%max;
		v[i]=x;
	}
}

int main(){
	int v[10];
	cout<<"Introduza el valor maximo aleatorio que se le pueda asignar al vector"<<endl;
	int max;
	cin>>max;
	fijaValorAleatorio(v,10, max);
	for(int i=0; i<10; i++){
		cout<<v[i]<<endl;srand(time(0));
	}
}