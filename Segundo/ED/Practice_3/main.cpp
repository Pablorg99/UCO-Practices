#include <iostream>
#include <cstdlib> //para usar srand()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"

void printMenu();
void writePersons(ed::ArbolBinarioOrdenadoEnlazado<Persona> tree);
void checkPerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> tree);
void printTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> tree);
void deletePerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> tree);
void deleteTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> tree);

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
}

void writePersons(ed::ArbolBinarioOrdenadoEnlazado<Persona> tree) {
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
}

void checkPerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> tree) {
    system("clear");
    Persona persona = generarDatosPersonales();
    if(tree.buscar(persona)) {
        cout << "Existe la persona: " << persona.mostrarPersona() << endl;
    }
    else cout << "No se ha encontrado la persona: " << persona.mostrarPersona() << endl;
}

void printTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> tree) {
    tree.recorridoPreOrden();
    tree.recorridoInOrden();
    tree.recorridoPostOrden();
}

void deleteTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> tree) {

}

void deletePerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> tree) {

}

