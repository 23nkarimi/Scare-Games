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
