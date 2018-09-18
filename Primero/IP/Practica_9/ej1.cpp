#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char **argv){
		if(argc<2){
				cout<<"Introduzca un valor para calcular su raiz"<<endl;
				return EXIT_FAILURE;		
		}
		if(argc>2){
				cout<<"Introduzca un unico valor"<<endl;
				return EXIT_FAILURE;
		}
		if(stof(argv[1])<0){
				cout<<"Introduzca un valor positivo"<<endl;
				return EXIT_FAILURE;
		}
		if(stof(argv[1])>0){
				cout<<"La raiz del numero introducido es: "<<sqrt(stof(argv[1]))<<endl;
				return EXIT_SUCCESS;
		}
}