#include<iostream>
#include<string>
using namespace std;
int digitos(string cad){
		int ndig=0;
		for(int i=0; i<cad.size(); i++){
			if(isdigit(cad[i])) ndig++;
		}
		return ndig;
}
int main(){
		string cad;
		cout<<"Introduzca una cadena"<<endl;
		getline(cin, cad);
		cout<<"La cadena tiene "<<digitos(cad)<<" digitos."<<endl;
}