#include <iostream>
#include <string>
using namespace std;
int vocales(string cad){
		int nvoc=0;
		int vocal[5]={'a','e','i','o','u'};
		for(int j=0; j<cad.size(); j++){
			for(int i=0; i<cad.size(); i++){
				if(tolower(cad[j])==vocal[i]) nvoc++;
			}
		}
		return nvoc;
}
int main(){
	string s;
	cout<<"Introduzca una cadena de caracteres"<<endl;
	getline(cin, s);
	cout<<"La cadena tiene "<<vocales(s)<<" vocales"<<endl;
	
}