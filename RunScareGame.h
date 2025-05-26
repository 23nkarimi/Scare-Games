/*
Full name: Nima Karimi and Julia Beroud
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 5: Scare Games
*/

#ifndef RUNSCAREGAME_H
#define RUNSCAREGAME_H
#include <string>

class RunScareGame {
public:
    RunScareGame(); // defualt constructor
    ~RunScareGame(); // destructor

    void runTournament(std::string inputFile, std::string mode); // creates brackets
};

#endif
