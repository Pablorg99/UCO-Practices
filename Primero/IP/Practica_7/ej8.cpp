#include<iostream>
#include<string>
using namespace std;
bool ncorrecto(string dni){
		int ndig=0;
		for(int i=0; (i<8)&&(i<dni.size()); i++){
			if(isdigit(dni[i])) ndig++;
		}
		if(ndig==8) return true;
		else return false;
}
bool lcorrecta(string dni){
		if(isalpha(dni[8])) return true;
		else return false;
}
void letra(string& dni){
		string letra="TRWAGMYFPDXBNJZSQVHLCKE";
		if((dni[8])!=(letra[stoi(dni)%23])) dni[8]=letra[stoi(dni)%23];
}
int main(){
		string dni;
		cout<<"Introduzca DNI:"<<endl;
		getline(cin, dni);
		if((ncorrecto(dni))&&(lcorrecta(dni))){
			cout<<"Formato Correcto"<<endl;
			letra(dni);
			cout<<"DNI Real "<<dni<<endl;
		}
		else cout<<"No es correcto"<<endl;
}
