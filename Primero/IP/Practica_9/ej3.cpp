#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv){
		if(argc!=2){
				cout<<"Introduzca unicamente la fecha"<<endl;
				return EXIT_FAILURE;
		}

		string fecha=argv[1];
		string dia, mes, year;
		dia[0]=fecha[0];
		dia[1]=fecha[1];
		mes[0]=fecha[3];
		mes[1]=fecha[4];
		year[0]=fecha[6];
		year[1]=fecha[7];
		year[2]=fecha[8];
		year[3]=fecha[9];

		//Comprueba si tras el dia y el mes hay '/', si los dias, meses y años son digitos y posibles, y que la fecha ocupa el espacio que debe.
		if( (fecha[2]=='/') && (fecha[5]=='/') && (isdigit(dia[0])) && (isdigit(dia[1])) && (isdigit(mes[0])) && (isdigit(mes[1])) && (isdigit(year[0])) && (isdigit(year[1])) && (isdigit(year[2])) && (isdigit(year[3])) && ( (fecha.size())==10) && ( (stoi(dia))<32 ) && ( (stoi(mes))<13 ) && ( (stoi(year))>0) ){
				if((stoi(year)%4)==0){
						cout<<"El año es bisiesto."<<endl;
						return EXIT_SUCCESS;
				}
				cout<<"El año no es bisiesto."<<endl;
				return EXIT_SUCCESS;
		}
		cout<<"Introduzca una fecha real en formato en dd/mm/aaaa"<<endl;
		return EXIT_FAILURE;
}
