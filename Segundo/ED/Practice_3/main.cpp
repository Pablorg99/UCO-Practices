#include <iostream>
#include <cstdlib> // para usar srand()
#include <unistd.h> // para usar sleep()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"
#include "macros.hpp"

void printMenu();
void writePersons(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree);
void checkPerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree);
void printTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree);
void deletePerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree);
void deleteTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree);

using namespace ed;

int main()
{
    srand(time(NULL));
    ArbolBinarioOrdenadoEnlazado<Persona> tree;
    writePersons(tree);

    int option = 0;

    do {
        printMenu();
        PLACE(11, 3);
        cout << BIYELLOW;
        cout << "Seleccione una opción: ";
        cout << RESET;
        cin >> option;
        cout << endl;

        switch(option) {
            case 1:
                printTree(tree);
                break;
            case 2:
                checkPerson(tree);
                break;
            case 3:
                deletePerson(tree);
                break;
            case 4:
                deleteTree(tree);
                break;
            case 0:
                break;
            default:
                system("clear");
                cout << "Introduzca una opción válida" << endl;
                sleep(2);
                break;
        }
    } while (option != 0);
}

void printMenu() {

    cout << CLEAR_SCREEN;
    PLACE(2, 3);
    cout << BIBLUE;
    cout << "MENÚ PRINCIPAL" << endl ;
    cout << RESET;

    PLACE(4, 5);
    cout << "[1] Imprime el árbol usando los 3 tipos de recorridos" << endl;
    PLACE(5, 5);
    cout << "[2] Comprueba si una persona, dados sus datos, existe en el árbol" << endl;
    PLACE(6, 5);
    cout << "[3] Borra a una persona, dados sus datos" << endl;
    PLACE(7, 5);
    cout << "[4] Borra el árbol" << endl;

    PLACE(9, 5);
    cout << BIRED;
    cout << "[0] Salir del programa" << endl;
    cout << RESET;
}

void writePersons(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree) {
    cout << CLEAR_SCREEN;
    int nPersons = 0;
    int x = 2;
    PLACE(x, 3);
    cout << BIGREEN;
    cout << "Introduzca un número de personas a escribir en el árbol: ";
    cout << RESET;
    cin >> nPersons;
    x++;
    while(nPersons < 1) {
        PLACE(++x, 4);
        cout << BIGREEN;
        cout << "Introduzca un número válido: ";
        cout << RESET;
        cin >> nPersons;
    }
    for(int i = 0; i < nPersons; ++i) {
        tree.insertar(generarDatosPersonales());
    }
    PLACE(++x, 3);
    cout << BIBLUE;
    cout << "Pulse intro para pasar al menú principal: ";
    cout << RESET;
    cin.get();
    cin.ignore();
}

void printTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree) {
    system("clear");
    EscribirNodo<Persona> operador;
    cout << BIGREEN;
    cout << "Recorrido PreOrden:" << endl;
    cout << RESET;
    tree.recorridoPreOrden(operador);
    cout << BIGREEN;
    cout << "Recorrido InOrden:" << endl;
    cout << RESET;
    tree.recorridoInOrden(operador);
    cout << BIGREEN;
    cout << "Recorrido PostOrden:" << endl;
    cout << RESET;
    tree.recorridoPostOrden(operador);
    cout << BIBLUE;
    cout << endl << "Pulse intro para volver al menú principal:  ";
    cout << RESET;
    cin.get();
    cin.ignore();
}

void checkPerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree) {
    cout << CLEAR_SCREEN;
    Persona persona;
    PLACE(2, 3);
    cout << BIGREEN;
    cout << "Introduzca los datos de la persona:" << endl << endl;
    cout << RESET;
    cin >> persona;
    if(tree.buscar(persona)) {
        PLACE(8, 3);
        cout << BIGREEN;
        cout << "Existe la persona: ";
        cout << RESET;
        persona.mostrarPersona();
    }
    else {
        PLACE(8, 3);
        cout << BIGREEN;
        cout << "No se ha encontrado la persona: ";
        cout << RESET;
        persona.mostrarPersona();
    }
    PLACE(10, 3);
    cout << BIBLUE;
    cout << "Pulse intro para volver al menú principal: ";
    cout << RESET;
    cin.get();
    cin.ignore();
}


void deletePerson(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree) {
    cout << CLEAR_SCREEN;
    Persona persona;
    PLACE(2, 3);
    cout << BIGREEN;
    cout << "Introduzca los datos de la persona a borrar:" << endl << endl;
    cout << RESET;
    cin >> persona;
    // Se busca a la persona
    if(tree.buscar(persona)) {
        PLACE(8, 3);
        cout << BIGREEN;
        cout << "Se ha encontrado a la persona, se procede a borrarla..." << endl;
        cout << RESET;
        tree.borrar();
    }
    else {
        PLACE(8, 3);
        cout << BIGREEN;
        cout << "No se ha encontrado a la persona" << endl;
        cout << RESET;
    }
    PLACE(10, 3);
    cout << BIBLUE;
    cout << "Pulse intro para volver al menú principal: ";
    cout << RESET;
    cin.get();
    cin.ignore();
}

void deleteTree(ed::ArbolBinarioOrdenadoEnlazado<Persona> &tree) {
    system("clear");
    string answer;
    PLACE(2, 3);
    cout << BIGREEN;
    cout << "Se ba a borrar el árbol, ¿está seguro? [si/no]: ";
    cout << RESET;
    cin >> answer;
    if(answer == "si") {
        tree.borrarArbol();
        PLACE(4, 4);
        cout << BIGREEN;
        cout << "Se ha borrado el árbol" << endl;
        cout << RESET;
    }
    else {
        PLACE(4, 4);
        cout << BIGREEN;
        cout << "No se ha borrado el árbol" << endl;
        cout << RESET;
    }
    PLACE(6, 3);
    cout << BIBLUE;
    cout << "Pulse intro para volver al menú principal: ";
    cout << RESET;
    cin.get();
    cin.ignore();
}