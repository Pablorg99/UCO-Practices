#include "ruleta.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

Ruleta::Ruleta(const Crupier &crupier) : ball_(-1), crupier_(crupier) {
    srand(time(NULL));
    setBanca(1000000);
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
        //If DNI.txt does not exists, create it (without any content)
        if(!ifstream(name)) ofstream file(name);
        return true;
    }
}

int Ruleta::deleteJugador(const Jugador &player) {
    if (players_.empty()) return -1;
    else if (DNIplayerInList_(player.getDNI())) { 
        list <Jugador> :: iterator it;
        //Iterates until find player with same DNI than passed one, and remove it.
        for(it = players_.begin(); it != players_.end(); it++) {
            //I do "it = list.erase" to  update iterator because I keep using "it" while in for loop
            //Not doing this, will cause segmentation fault
            if ((player.getDNI()) == (it->getDNI())) it = players_.erase(it);
        }
        return 1;
    }
    else return -2;
}

int Ruleta::deleteJugador(const string &DNI) {
    if (players_.empty()) return -1;
    else if (DNIplayerInList_(DNI)) {
        //DNI passed, is the DNI of a player of "players_"
        list <Jugador> :: iterator it;
        //Iterates until find this player, and remove it.
        for(it = players_.begin(); it != players_.end(); it++) {
            //"it = erase" same reason previous function
            if (it -> getDNI() == DNI) it = players_.erase(it);
        }
        return 1;
    }
    else return -2;
}

void Ruleta::escribeJugadores() {
    ofstream psfile("jugadores.txt");
    list <Jugador> :: iterator it;
    
    for(it = players_.begin(); it != players_.end() ; it++) {
        psfile << it->getDNI() << ',' << it->getCodigo() << ',' <<
        it->getNombre() << ',' << it->getApellidos()  << ',' <<
        it->getEdad() << ',' << it->getDireccion() << ',' << 
        it->getLocalidad() << ',' << it->getProvincia() << ','
        << it->getPais() << ',' << it->getDinero() << std::endl;
    }
    
    psfile.close();
}

void Ruleta::leeJugadores() {
    //clear list
    players_.clear();
    //auxiliar variables
    //initialisation player's values will be replaced from the ones in the file
    Jugador player("DNI", "Identifier");
    string value;
    //open file
    ifstream psfile("jugadores.txt");
    //iterates until there is no any ',' left (getline returns false)
    //in each iteration save in object "player" parameters saved in file
    //(if a parameter is not in the file, it will store in "player" as "")
    while(getline(psfile, value, ',')) {
        player.setDNI(value);
        getline(psfile, value, ',');
        player.setCodigo(value);
        getline(psfile, value, ',');
        player.setNombre(value);
        getline(psfile, value, ',');
        player.setApellidos(value);
        getline(psfile, value, ',');
        player.setEdad(atoi(value.c_str()));
        getline(psfile, value, ',');
        player.setDireccion(value);
        getline(psfile, value, ',');
        player.setLocalidad(value);
        getline(psfile, value, ',');
        player.setProvincia(value);
        getline(psfile, value, ',');
        player.setPais(value);
        getline(psfile, value, '\n');
        player.setDinero(atoi(value.c_str()));
        //push to the list values in object player
        players_.push_back(player);
    }
    psfile.close();
}

void Ruleta::getPremios() {

}

