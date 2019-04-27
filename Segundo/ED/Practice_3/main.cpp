#include <iostream>
#include <cstdlib> // para usar srand()
#include <unistd.h> // para usar sleep()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"

void printMenu();
void writePersons(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree);
void checkPerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree);
void printTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree);
void deletePerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree);
void deleteTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree);

using namespace ed;

int main()
{
    ArbolBinarioOrdenadoEnlazado<Persona> tree;
    srand(time(NULL));
    int option = 0;

    do {
        option = 0;
        printMenu();

        cout << "Selecciona una opción: ";
        cin >> option;
        switch(option) {
            case 1:
                writePersons(tree);
                break;
            case 2:
                checkPerson(tree);
                break;
            case 3:
                printTree(tree);
                break;
            case 4:
                deletePerson(tree);
                break;
            case 5:
                deleteTree(tree);
                break;
            default:
                cout << "Introduzca una opción del menú" << endl;
                sleep(2);
                break;
        }
    } while (option != 0);
}

void printMenu() {
    system("clear");
    cout << "Menú Principal" << endl;
    cout << "\t1: Escribe un número de personas en el árbol" << endl;
    cout << "\t2: Comprueba si una persona, dados sus datos, existe en el árbol" << endl;
    cout << "\t3: Imprime el árbol usando los 3 tipos de recorridos" << endl;
    cout << "\t4: Borra a una persona, dados sus datos" << endl;
    cout << "\t5: Borra el árbol" << endl;
    cout << endl << "\t0: Salir del programa" << endl;
}

void writePersons(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree) {
    system("clear");
    int nPersons = 0;
    cout << "Introduzca un número de personas a escribir en el árbol: ";
    cin >> nPersons;
    while(nPersons < 1) {
        cout << "Introduzca un número válido: ";
        cin >> nPersons;
    }
    for(int i = 0; i < nPersons; ++i) {
        tree.insertar(generarDatosPersonales());
    }
    cout << "Se han introducido las personas" << endl;
    cout << "Pulsa intro para continuar: ";
    cin.get();
    cin.ignore();
}

void checkPerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree) {
    system("clear");
    Persona persona;
    cout << "Introduzca los datos de la persona:" << endl;
    cin >> persona;
    if(tree.buscar(persona)) {
        cout << "Existe la persona: ";
        persona.mostrarPersona();
    }
    else {
        cout << "No se ha encontrado la persona: ";
        persona.mostrarPersona();
    }
    cout << "Pulsa intro para continuar: ";
    cin.get();
    cin.ignore();
}

void printTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree) {
    system("clear");
    EscribirNodo<Persona> operador;
    cout << "Recorrido PreOrden:" << endl;
    tree.recorridoPreOrden(operador);
    cout << "Recorrido PreOrden:" << endl;
    tree.recorridoInOrden(operador);
    cout << "Recorrido PreOrden:" << endl;
    tree.recorridoPostOrden(operador);
    cout << "Pulsa intro para continuar: ";
    cin.get();
    cin.ignore();
}

void deletePerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree) {
    system("clear");
    Persona persona;
    cout << "Introduzca los datos de la persona a borrar:" << endl;
    cin >> persona;
    // Se busca a la persona
    if(tree.buscar(persona)) {
        cout << "Se ha encontrado a la persona, se procede a borrarla" << endl;
        tree.borrar();
    }
    else cout << "No se ha encontrado a la persona" << endl;
    cout << "Pulsa intro para continuar: ";
    cin.get();
    cin.ignore();
}

void deleteTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree) {
    system("clear");
    string answer;
    cout << "Se ba a borrar el árbol, ¿está seguro? [y/n]: ";
    cin >> answer;
    while((answer != "y") || (answer != "n")) {
        cout << "Responda correctamente [y/n]: ";
        cin >> answer;
    }
    if(answer == "y") {
        tree.borrarArbol();
        cout << "Se ha borrado el árbol" << endl;
    }
    else if(answer == "n") cout << "No se ha borrado el árbol" << endl;
    cout << "Pulsa intro para continuar: ";
    cin.get();
    cin.ignore();
}