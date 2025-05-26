#include <iostream>
#include "RunScareGame.h"

int main(int argc, char** argv) {
    // handles incorrect number of arguments
    if (argc != 3) {
        std::cerr << "Usage: ./e <input_file> <mode (single/double)>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    std::string mode = argv[2];

    RunScareGame game;
    game.runTournament(inputFile, mode);

    return 0;
}
