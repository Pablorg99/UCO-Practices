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
        //If DNI.txt does not exists, create it
        //DNI is the dni from the player passed as parameter
        if(!ifstream(name)) ofstream(name);
        return true;
    }
}

int Ruleta::deleteJugador(Jugador player) {
    
}

bool Ruleta::playerInList_(Jugador player) {
    list <Jugador> :: iterator it;
    //go all over the list checking if dni from the player
    //passed as parameter is in the list players_
    for(it = players_.begin(); it != players_.end(); it++) 
    {        
        if ((*it).getDNI() == player.getDNI()) return true;
    }
    return false;
}
