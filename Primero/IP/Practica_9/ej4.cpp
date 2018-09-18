#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main(int argc, char** argv){
		if(argc<3){cout<<"Introduzca almenos una operacion"<<endl; return EXIT_FAILURE;}
		float res=stof(argv[1]);
		for(int i=1; i<argc; i+=2){
				if(string(argv[i+1])=="-sum") res+=stof(argv[i+2]);
				if(string(argv[i+1])=="-mult") res*=stof(argv[i+2]);
				if(string(argv[i+1])=="-div") res/=stof(argv[i+2]);
				if(string(argv[i+1])=="-sqrt") res=sqrt(res);
		}
		cout<<res<<endl;
		return EXIT_SUCCESS;
}