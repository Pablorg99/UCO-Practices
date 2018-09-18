#include <iostream>
#include <string>
using namespace std;
bool palindromo(string cad){
		for(int i=0; i<cad.size()/2; i++){
			if(cad[i]!=cad[cad.size()-i-1]) return false;
		}
		return true;
}
int main(){
		string s;
		cout<<"Introduzca una cadena de caracteres"<<endl;
		getline(cin, s);
		if(palindromo(s)) cout<<s<<" es palindromo"<<endl;
		else cout<<s<<" no es palindromo"<<endl;
}