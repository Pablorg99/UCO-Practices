#ifndef RULETA_H
#define RULETA_H

#include "jugador.h"
#include "crupier.h"
#include <list>

class Ruleta {
    private:
        int bank_;
        int ball_;
        list <Jugador> players_;
        Crupier crupier_;
    public:
        //Constructor
        Ruleta();
        //Getter methods
        int getBanca() const {return bank_;}
        int getBola() const {return ball_;}
        Crupier getCrupier() const {return crupier_;}
        list <Jugador> getJugadores() {return players_;}
        //Setter Methods
        bool setBanca();
        bool setBola();
        void setCrupier();
        //Other methods
        bool addJugador(Jugador player);
        int deleteJugador(Jugador player);
        void escribeJugadores();
};

#endif