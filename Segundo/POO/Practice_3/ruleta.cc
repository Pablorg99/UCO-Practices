#include "ruleta.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

Ruleta::Ruleta(const Crupier &crupier) : crupier_(crupier) {
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

//Private method 
bool Ruleta::DNIplayerInList_(string DNI) {
    list <Jugador> :: iterator it;
    Jugador player(DNI, "identifier");
    //go all over the list checking if dni from the player
    //passed as parameter is in the list players_
    for(it = players_.begin(); it != players_.end(); it++) {        
        if (it->getDNI() == player.getDNI()) return true;
    }
    return false;
}

bool Ruleta::setBola(const int number) {    
    if (number >= 0 && number <= 36) {
        ball_ = number;
        return true;
    }
    else return false;
}

bool Ruleta::addJugador(const Jugador &player) {
    if(DNIplayerInList_(player.getDNI())) return false;
    else {
        players_.push_back(player);
        string name = player.getDNI() + ".txt";
        //DNI is the dni from the player passed as parameter
        //If DNI.txt does not exists, create it
        if(!ifstream(name)) ofstream(name);
        return true;
    }
}

int Ruleta::deleteJugador(string DNI) {
    if (players_.empty()) return -2;
    else if (DNIplayerInList_(DNI)) {
        //DNI passed, is the DNI of a player of "players_"
        list <Jugador> :: iterator it;
        //Iterates until find this player, and remove it.
        for(it = players_.begin(); it != players_.end(); it++) {
            if (it -> getDNI() == DNI) players_.erase(it);
        }
        return 1;
    }
    else return -1;
}


int Ruleta::deleteJugador(const Jugador &player) {
    if (players_.empty()) return -2;
    else if (DNIplayerInList_(player.getDNI())) {
        players_.remove(player);
        return 1;
    }
    else return -1;
}

void Ruleta::escribeJugadores() {
    ofstream pfile("jugadores.txt");
    list <Jugador> :: iterator it;
    
    for(it = players_.begin(); it != players_.end() ; it++) {
        pfile << it->getDNI() << ',' << it->getCodigo() << ',' <<
        it->getNombre() << ',' << it->getApellidos()  << ',' <<
        it->getEdad() << ',' << it->getDireccion() << ',' << 
        it->getLocalidad() << ',' << it->getProvincia() << ','
        << it->getPais() << ',' << it->getDinero() << std::endl;
    }
    
    pfile.close();
}

void Ruleta::leeJugadores() {
    //clear list
    players_.clear();
    //auxiliar variables
    //initialisation player's values will be replaced from the ones in the file
    Jugador player("DNI", "Identifier");
    string value;
    //open file
    ifstream pfile("jugadores.txt");
    //iterates until there is no any ',' left (getline returns false)
    //in each iteration save in object "player" parameters saved in file
    //(if a parameter is not in the file, it will store in "player" as "")
    while(getline(pfile, value, ',')) {
        player.setDNI(value);
        getline(pfile, value, ',');
        player.setCodigo(value);
        getline(pfile, value, ',');
        player.setNombre(value);
        getline(pfile, value, ',');
        player.setApellidos(value);
        getline(pfile, value, ',');
        player.setEdad(stoi(value));
        getline(pfile, value, ',');
        player.setDireccion(value);
        getline(pfile, value, ',');
        player.setLocalidad(value);
        getline(pfile, value, ',');
        player.setProvincia(value);
        getline(pfile, value, ',');
        player.setPais(value);
        getline(pfile, value, ',');
        player.setDinero(stoi(value));
        //push to the list values in object player
        players_.push_back(player);
    }
    pfile.close();
}

