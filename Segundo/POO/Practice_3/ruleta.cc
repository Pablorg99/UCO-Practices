#include "ruleta.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

//Private methods 
string Ruleta::getColor_() {
    if(getBola() == 0) return "0";
    else {
        int red[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
        for(int i = 0; i < 18; i++) {
            if(getBola() == red[i]) return "rojo";
        }
        return "negro";
    }
}

string Ruleta::getParImpar_() {
    if(getBola() == 0) return "0";
    else {
        if((getBola() % 2) == 0) return "par";
        else return "impar";
    }
}

string Ruleta::getAltoBajo_() {
    if(getBola() == 0) return "0";
    else {
        if(getBola() < 18) return "bajo";
        else return "alto";
    }
}

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

bool Ruleta::setBola(const int number) {    
    if (number >= 0 && number <= 36) {
        ball_ = number;
        return true;
    }
    else return false;
}


//Extra method 
bool Ruleta::DNIplayerInList(string DNI) {
    list <Jugador> :: iterator it;
    Jugador player(DNI, "identifier");
    //go all over the list checking if dni from the player
    //passed as parameter is in the list players_
    for(it = players_.begin(); it != players_.end(); it++) {        
        if (it->getDNI() == player.getDNI()) return true;
    }
    return false;
}

bool Ruleta::addJugador(const Jugador &player) {
    if(DNIplayerInList(player.getDNI())) return false;
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
    else if (DNIplayerInList(player.getDNI())) { 
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
    else if (DNIplayerInList(DNI)) {
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
        player.setEdad(stoi(value));
        getline(psfile, value, ',');
        player.setDireccion(value);
        getline(psfile, value, ',');
        player.setLocalidad(value);
        getline(psfile, value, ',');
        player.setProvincia(value);
        getline(psfile, value, ',');
        player.setPais(value);
        getline(psfile, value, '\n');
        player.setDinero(stoi(value));
        //push to the list values in object player
        players_.push_back(player);
    }
    psfile.close();
}

void Ruleta::getPremios() {

    list <Jugador> :: iterator player;
    //Auxiliar variables used in each player iteration
    list <Apuesta> bets;
    list <Apuesta> :: iterator bet;
    
    for(player = players_.begin(); player != players_.end(); player++) {
        //Update bets_ (list of object player) with the bets on the player file (DNI.txt)
        player->setApuestas();
        //Copy bets_ in the auxiliar list bets to work with it
        bets = player->getApuestas();
        //Each line from DNI.txt (each bet) is one element of the list
        for(bet = bets.begin(); bet != bets.end(); bet++) {

            switch (bet->tipo) {

                case 1: //Apuesta sencilla
                    if(stoi(bet->valor) == getBola()) {
                        int profit = 35 * (bet->cantidad);
                        player->setDinero(player->getDinero() + profit);
                        setBanca(getBanca() - profit);
                    }
                    else {
                        player->setDinero(player->getDinero() - bet->cantidad);
                        setBanca(getBanca() + bet->cantidad);
                    }
                    break;

                case 2: //Apuesta rojo/negro
                    if(bet->valor == getColor_()) {
                        player->setDinero(player->getDinero() + bet->cantidad);
                        setBanca(getBanca() - bet->cantidad);
                    }
                    else {
                        player->setDinero(player->getDinero() - bet->cantidad);
                        setBanca(getBanca() + bet->cantidad);
                    }
                    break;

                case 3: //Apuesta par/impar
                    if(bet->valor == getParImpar_()) {
                        player->setDinero(player->getDinero() + bet->cantidad);
                        setBanca(getBanca() - bet->cantidad);
                    }
                    else {
                        player->setDinero(player->getDinero() - bet->cantidad);
                        setBanca(getBanca() + bet->cantidad);
                    }
                    break;

                case 4: //Apuesta alto/bajo
                    if(bet->valor == getAltoBajo_()) {
                        player->setDinero(player->getDinero() + bet->cantidad);
                        setBanca(getBanca() - bet->cantidad);
                    }
                    else {
                        player->setDinero(player->getDinero() - bet->cantidad);
                        setBanca(getBanca() + bet->cantidad);
                    }
                    break;
            }
        }
    }
}

