/*
Full name: Nima Karimi and Julia Beroud
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 5: Scare Games
*/
#ifndef TOURNAMENTNODE_H
#define TOURNAMENTNODE_H
#include "Monster.h"

class TournamentNode{
    private:
        Monster* winner; 
        TournamentNode* left; 
        TournamentNode* right; 
    public:
        TournamentNode(); // default constructor
        TournamentNode(Monster m); // parameterized constructor
        TournamentNode(TournamentNode* l, TournamentNode* r); // parameterized constructor
        ~TournamentNode(); // destructor

        void determineWinner(); // determines the winner

        // getters
        Monster* getWinner(); 
        TournamentNode* getLeft();
        TournamentNode* getRight();
};

#endif 