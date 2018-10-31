#include "ruleta.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

Ruleta::Ruleta(const Crupier &crupier) crupier_(crupier) {
    setBanca(1000000);
    setBola(-1);
}

bool Ruleta::setBanca(const int money) {
    if (money >= 0) {
        bank_ = money;
        return true;
    }
    else return false;
}

bool Ruleta::setBola(const int number) {    
    if (number >= 0 && number <= 36) {
        ball_ = number;
        return true;
    }
    else return false;
}

bool Ruleta::addJugador(Jugador player) {
    if(playerInList_(player)) return false;
    else {
        players_.push_back(player);
        string name = player.getDNI() + ".txt";
        //DNI is the dni from the player passed as parameter
        //If DNI.txt does not exists, create it
        if(!ifstream(name)) ofstream(name);
        return true;
    }
}

int Ruleta::deleteJugador(Jugador player) {
    if (players_.empty()) return -2;
    else if (playerInList_(player)) {
        players_.remove(player);
        return 1;
    }
    else return -1;
}

void Ruleta::escribeJugadores() {
    ofstream pfile("jugadores.txt");
    list <Jugador> :: iterator it;
    
    for(it = players_.begin(); it != players_.end() ; it++) {
        pfile << it->getDNI() << "," << it->getCodigo() << "," << it->getNombre() << "," << 
        it->getApellidos() << "," << it->getDireccion() << "," << it->getLocalidad() << ","
        << it->getProvincia() << "," << it->getPais() << "," << it->getDinero() << std::endl;
    }
    
    pfile.close();
}

bool Ruleta::playerInList_(Jugador player) {
    list <Jugador> :: iterator it;
    //go all over the list checking if dni from the player
    //passed as parameter is in the list players_
    for(it = players_.begin(); it != players_.end(); it++) {        
        if (it->getDNI() == player.getDNI()) return true;
    }
    return false;
}
