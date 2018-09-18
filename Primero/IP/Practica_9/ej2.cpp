#include <iostream>
using namespace std;
int main(int argc, char **argv){
		if(argc<2){
				cout<<"Introduzca algun dato para realizar su media"<<endl;
				return EXIT_FAILURE;
		}
		float sum=0;
		for(int i=1; i<argc; i++){
				sum+=stof(argv[i]);
		}
		cout<<"La media de los datos introducidos es: "<<sum/(argc-1)<<endl;
		return EXIT_SUCCESS;
}