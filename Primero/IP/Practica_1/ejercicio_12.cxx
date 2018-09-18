#include <iostream>
using namespace std;
int main(){
	int din;
	cout<<"Introduzca una cantidad de euros:"<<endl;
	cin>>din;
	cout<<din<<"Se cambia en estos billetes:"<<endl;
	int b500,b200,b100,b50,b20,b10	,b5;
	b500=din/500;
	cout<<b500<<" x500€"<<endl;
	din=din%500;
	b200=din/200;
	cout<<b200<<" x200€"<<endl;
	din=din%200;
	b100=din/100;
	cout<<b100<<" x100€"<<endl;
	din=din%100	;
	b50=din/50;
	cout<<b50<<" x50€"<<endl;
	din=din%50;
	b20=din/20;
	cout<<b20<<" x20€"<<endl;
	din=din%20;
	b10=din/10;
	cout<<b10<<" x10€"<<endl;
	din=din%10;
	b5=din/5;
	cout<<b5<<" x5€"<<endl;	
cin.ignore();
cin.get();
}