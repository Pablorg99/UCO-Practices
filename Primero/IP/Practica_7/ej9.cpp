#include<iostream>
#include<string>
using namespace std;
int find(string a, string b){
		string aux=b; 
		//Creo una cadena auxiliar y la igualo a b para que tenga el mismo rango que esta.
		int j;
		//Declaro j aqui para poder usarla en el if.
		for(int i=0; i<(a.size()-b.size()); i++){
		 //Pongo a.size-b.size para no cometer violacion del segmento en el segundo for.
			for(j=0; j<b.size(); j++){
				aux[j]=a[j+i]; 
				//Cada vez que recorro el segundo for, guardo en aux un trozo de la cadena a (de rango b) distinto cada vez.
			}
		if(aux==b) return(j+i-b.size()); 
		//Compruebo si ese trozo de la cadena a son iguales a b, si es asi retorno la posicion de inicio de dicho trozo en a.
		}
		return -1;	
}
int main(){
		string a, b;
		cout<<"Introduzca la cadena 1: "<<endl;
		getline(cin,a);
		cout<<"Introduzca la cadena 2: "<<endl;
		getline(cin,b);
		cout<<find(a,b)<<endl;
}