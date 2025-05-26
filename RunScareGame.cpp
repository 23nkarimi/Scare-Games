/*
Full name: Nima Karimi and Julia Beroud
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 5: Scare Games
*/
#include "RunScareGame.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "TournamentTree.h"

RunScareGame::RunScareGame() {}

RunScareGame::~RunScareGame() {}

void RunScareGame::runTournament(std::string inputFile, std::string mode) {
    // handles errors when opening the input file
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Error opening input file.\n";
        return;
    }

    std::vector<Monster> monsters;
    std::string line;
    // reading the input file
    while (getline(inFile, line)) {
        std::stringstream ss(line);
        std::string name;
        int scream;
        if (getline(ss, name, ',') && ss >> scream) {
            monsters.push_back(Monster(name, scream));
        }
    }
    inFile.close();

    // winner's bracket
    TournamentTree winnersTree;
    winnersTree.buildSingleElimination(monsters);
    Monster* winner = winnersTree.getRoot()->getWinner();

    // case if is single elimination
    if (mode == "single") {
        std::cout << "Champion: " << winner->getName() << " with scream level " << winner->getScreamLevel() << std::endl;
        winnersTree.saveTreeAsDot("single_elim_bracket.dot", winnersTree.getRoot());
        return;
    }

    // losers vector
    std::vector<Monster> losers;
    for (const Monster& m : monsters) {
        if (!(m == *winner)) {
            losers.push_back(m);
        }
    }

    // losers bracket
    TournamentTree losersTree;
    TournamentNode* loserRoot = losersTree.buildTreeFromMonstersPublic(losers);
    Monster* loserBracketWinner = loserRoot->getWinner();

    // printing results
    std::cout << "\n Winner of Winners' Bracket: " << winner->getName() << std::endl;
    std::cout << " Winner of Losers' Bracket: " << loserBracketWinner->getName() << std::endl;

    // final match
    TournamentNode* finalMatch = new TournamentNode(winnersTree.getRoot(), loserRoot);
    Monster* finalWinner = finalMatch->getWinner();  // trigger the match and console output

    // printing results
    std::cout << "\n FINAL CHAMPION: " << finalWinner->getName()
              << " with scream level " << finalWinner->getScreamLevel() << std::endl;
    
    TournamentTree finalTree;
    finalTree.saveTreeAsDot("double_elim_bracket.dot", finalMatch);

}
