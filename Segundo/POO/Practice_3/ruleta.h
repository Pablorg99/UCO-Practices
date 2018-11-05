/*--------------------------------------------------------------------------------
ruleta.h
Pablo Rodríguez Guillén
Practice 3 Class Ruleta
Header file with declaration of class 'Ruleta' and all its methods
--------------------------------------------------------------------------------*/

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
        //returns true if string passed as parameter is the DNI of any player of the list "players_"
        //if any of the players have this DNI, it returns false
        bool DNIplayerInList_(string);
    public:
        //Constructor
        Ruleta(const Crupier &crupier);
        //Getter methods
        int getBanca() const {return bank_;}
        int getBola() const {return ball_;}
        Crupier getCrupier() const {return crupier_;}
        list <Jugador> getJugadores() {return players_;}
        //Setter Methods
        //returns true and set in bank_ if money is positive 0, if not, returns false
        bool setBanca(const int money);
        //returns true and set in ball_ if number is between 0 and 36, if not returns false
        bool setBola(const int number);
        void setCrupier(const Crupier &crupier) {crupier_ = crupier;}
        //Methods for modifying "players_" list
        bool addJugador(const Jugador &player);
        int deleteJugador(string DNI);
        int deleteJugador(const Jugador &player);
        //Methods for "jugadores.txt" file with all data from list "players_"
        void escribeJugadores();
        void leeJugadores();
        //Methods related with the roulette itself
        //Roll the roulette and set ball_ to the number obtained (0-36)
        void girarRuleta() {setBola(rand() % 37);}
        void getPremios();
};

#endif