#include<iostream>
#include<string>
using namespace std;
void replace(string& cad, char a, char b){
		for(int i=0; i<cad.size(); i++){
			if(cad[i]==a) cad[i]=b;
		}
}
int main(){
		string cad;
		cout<<"Introduzca una cadena"<<endl;
		getline(cin, cad);
		char a, b;
		cout<<"Elige un caracter a remplazar: "<<endl;
		cin>>a;
		cout<<"Elige el caracter por el que se va a remplazar"<<endl;
		cin>>b;
		replace(cad, a, b);
		cout<<"La cadena resultante es "<<cad<<endl;
}