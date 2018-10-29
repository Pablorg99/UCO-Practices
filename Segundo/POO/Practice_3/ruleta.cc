#include "ruleta.h"
#include <fstream>

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
    list <Jugador> :: iterator it;
    
    for(it = players_.begin(); it != players_.end(); it++) {        
        if ((*it).getDNI() == player.getDNI()) {
            return false;
        }
    }   
    //If DNI from player not find in list:
    players_.push_back(player);
    createDNItxt(player);
    return true;
}

void createDNItxt(Jugador player) {
    std::ifstream file(player.getDNI() + '.txt');
}