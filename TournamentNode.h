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
