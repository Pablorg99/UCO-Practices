#include<iostream>
#include<string>
using namespace std;
string concatena(string a, string b){
		string c;
		c=a+b;
		return c;
}
int main(){
		string a, b;
		cout<<"Introduce la primera cadena:"<<endl;
		getline(cin, a);
		cout<<"Introduce la segunda cadena:"<<endl;
		getline(cin, b);
		cout<<"La cadena resultante es: "	<<concatena(a,b)<<endl;
}