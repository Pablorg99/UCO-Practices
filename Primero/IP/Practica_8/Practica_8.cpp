#include <iostream>
using namespace std;
struct Alumno{
		string dni;
		int edad;
		float nota;

		void add_alumno(){
				cout<<endl;
				cout<<"Introduzca el DNI:"<<endl;
				cin>>dni;
				cout<<"Introduzca la edad:"<<endl;					
				cin>>edad;	
				cout<<"Introduzca su nota"<<endl;
				cin>>nota;
		}
		void mostrar_datos(){
				cout<<endl;
				cout<<"DNI: "<<dni<<endl;
				cout<<"Edad: "<<edad<<endl;
				cout<<"Nota: "<<nota<<endl;
		}
		void modificar_alumno(Alumno alumnos[], int &i){
				int opc_submenu=0;
				cout<<endl;
				cout<<"1. DNI"<<endl;
				cout<<"2. Edad"<<endl;
				cout<<"3. Nota"<<endl;
				cout<<"4.Todos"<<endl;
				cout<<"Indique que parametro quiere modificar: "; cin>>opc_submenu;
			
				switch(opc_submenu){
						case 1:{
								cout<<"Introduzca DNI: "; cin>>dni;
						}break;
						case 2:{
								cout<<"Introduzca Edad: "; cin>>edad;						
						}break;
						case 3:{
								cout<<"Introduzca Nota: "; cin>>nota;						
						}break;
						case 4:{
								alumnos[i].add_alumno();
						}break;
				}			
		}
		void eliminar_alumno(Alumno alumnos[], int &nmatriculados){
				dni=alumnos[nmatriculados-1].dni; 
				edad=alumnos[nmatriculados-1].edad;
				nota=alumnos[nmatriculados-1].nota;
		}
};
int main(){
		Alumno alumnos[10];
		int nmatriculados=0, opcion_menu=0, c;
		string DNI;
		while(opcion_menu!=6){
				cout<<endl;
				cout<<"1. Añadir alumno"<<endl;
				cout<<"2. Mostrar datos de un alumno"<<endl;
				cout<<"3. Mostrar datos de todos los alumnos"<<endl;
				cout<<"4. Modificar alumno"<<endl;
				cout<<"5. Eliminar alumno"<<endl;
				cout<<"6. Salir"<<endl;
				cout<<" "<<endl;
				cout<<"Seleccione una opcion: ";  cin>>opcion_menu;

				switch(opcion_menu){
						case 1:{
								if(nmatriculados>9){cout<<"Solo caben 10 alumnos en la base de datos, para añadir otro elimine uno de los guardados"<<endl;}
								else{
									alumnos[nmatriculados].add_alumno();
									nmatriculados++;
								}	
						}break;
						case 2:{
								cout<<"Introduzca el DNI del alumno que quiere consultar"<<endl;
								c=0;
								cin>>DNI;
								for(int i=0; i<nmatriculados; i++){	
									if(DNI==alumnos[i].dni){ 
										alumnos[i].mostrar_datos();		
										c++;
									}
								}
								if(c==0) cout<<"No existe ningun alumno registrado con ese DNI"<<endl;
						}break;
						case 3:{
								for(int i=0; i<nmatriculados; i++){
										alumnos[i].mostrar_datos();
								}
							}break;
						case 4:{
								cout<<"Introduzca el DNI del alumno que desea modificar"<<endl;
								c=0;
								cin>>DNI;
								for(int i=0; i<nmatriculados; i++){	
									if(DNI==alumnos[i].dni){ 
										alumnos[i].modificar_alumno(alumnos, i);		
										c++;
									}
								}
								if(c==0) cout<<"No existe ningun alumno registrado con ese DNI"<<endl;
						}break;
						case 5:{
								cout<<"Introduzca el DNI del alumno que quiere eliminar"<<endl;
								c=0;
								cin>>DNI;
								for(int i=0; i<nmatriculados; i++){
										if(DNI==alumnos[i].dni){
											alumnos[i].eliminar_alumno(alumnos, nmatriculados);
											nmatriculados--;
											c++;
										}
								}						
								if(c==0){ cout<<"No existe ningún alumno registrado con ese DNI"<<endl; }		
						}break;
				}
		}
}