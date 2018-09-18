#include <iostream>
using namespace std;
int main(){

	int mes;
	cout<<"Introduzca un numero del 1 al 12:"<<endl;
	cin>>mes;
	switch(mes){
		case 1:{cout<<"31 dias"<<endl;
		}break;
		case 2:{cout<<"28 dias"<<endl;
		}break;
		case 3:{cout<<"31 dias"<<endl;
		}break;
		case 4:{cout<<"30 dias"<<endl;
		}break;
		case 5:{cout<<"31 dias"<<endl;
		}break;
		case 6:{cout<<"30 dias"<<endl;
		}break;
		case 7:{cout<<"31 dias"<<endl;
		}break;
		case 8:{cout<<"31 dias"<<endl;
		}break;
		case 9:{cout<<"30 dias"<<endl;
		}break;
		case 10:{cout<<"31 dias"<<endl;
		}break;
		case 11:{cout<<"30 dias"<<endl;
		}break;
		case 12:{cout<<"31 dias"<<endl;
		}break;
	}

cin.ignore();
cin.get();
}