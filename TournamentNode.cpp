/*
Full name: Nima Karimi and Julia Beroud
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 5: Scare Games
*/

#include "TournamentNode.h"
#include <iostream> 

// default constructor
TournamentNode::TournamentNode(){
    left = nullptr;
    right = nullptr;
    winner = nullptr;
}

// parameterized constructor
TournamentNode::TournamentNode(Monster m){
    winner = new Monster(m);
    left = nullptr;
    right = nullptr;
}

// parameterized constructor
TournamentNode::TournamentNode(TournamentNode* l, TournamentNode* r){
    left = l;
    right = r;
    determineWinner();
}

// destructor
TournamentNode::~TournamentNode(){
    delete winner;
}

// calculates winner
void TournamentNode::determineWinner() {
    
    if (*left->getWinner() > *right->getWinner()) {
        winner = new Monster(*left->getWinner());
    } else {
        winner = new Monster(*right->getWinner());
    }

    // printing out the match and the results of said match
    std::cout << "Match: " << left->getWinner()->getName() << " (" << left->getWinner()->getScreamLevel()
              << ") vs " << right->getWinner()->getName() << " (" << right->getWinner()->getScreamLevel()
              << ") → Winner: " << winner->getName() << std::endl;
}

// getters
Monster* TournamentNode::getWinner(){
    return winner;
}

TournamentNode* TournamentNode::getLeft(){
    return left;
}

TournamentNode* TournamentNode::getRight(){
    return right;
}
