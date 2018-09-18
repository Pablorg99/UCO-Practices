#include<iostream>
#include<string>
using namespace std;
int espacios(string cad){
		int nesp=0;
		for(int i=0; i<cad.size(); i++){
			if(cad[i]==' ') nesp++;
		}
		return nesp;
}
int main(){
		string cad;
		getline(cin, cad);
		cout<<"La cadena tiene "<<espacios(cad)<<" espacios."<<endl;
}