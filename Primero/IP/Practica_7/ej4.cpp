#include<iostream>
#include<string>
using namespace std;
void convierte_a_mayuscula(string& cad){
		for(int i=0; i<cad.size(); i++){
			cad[i]=toupper(cad[i]);
		}
}
int main(){
		string cad;
		cout<<"Introduzca una cadena sin caracteres"<<endl;
		getline(cin, cad);
		convierte_a_mayuscula(cad);
		cout<<"La cadena en mayusculas es: "<<cad<<endl;
}