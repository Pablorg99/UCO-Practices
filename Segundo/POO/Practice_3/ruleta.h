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
        //Methods for bets
        string getColor_();
        string getParImpar_();
        string getAltoBajo_();
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
        //Methods for "players_" list
        /*returns true if string passed as parameter, is the DNI of any player of the list "players_"
        if any of the players have this DNI, it returns false*/
        bool DNIplayerInList(string); //Extra method, not asked in practice
        /*Add player passed as paremeter to the list and if not exists, creates DNI.txt file
        if player is already in the list, does not add it and returns false*/
        bool addJugador(const Jugador &player);
        /*returns -1 if players_ is empty
        returns -2 if player/DNI passed as parameter is not in the list
        returns 1 if the player is removed of the list */
        int deleteJugador(const string &DNI);
        int deleteJugador(const Jugador &player);
        //Methods for "jugadores.txt" file with all data from list "players_"
        /*create an empty file "jugadores.txt" and prints on it all content from players_
        each line is data from one player of the list*/
        void escribeJugadores();
        //clears the list players_ and puts on it all data from "jugadores.txt"
        void leeJugadores();
        //Methods for roulette working
        //roll the roulette and set ball_ to the number obtained (0-36)
        void giraRuleta() {setBola(rand() % 37);}
        //updates player's and bank's money depending on player's bets and ball_'s value
        void getPremios();
};

#endif