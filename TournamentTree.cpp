/*
Full name: Nima Karimi and Julia Beroud
Student ID: 2485949
Chapman Email: nikarimi@chapman.edu
Course number and section: CPSC-350-02
Assignment number: PA 5: Scare Games
*/

#include "TournamentTree.h"
#include <iostream>

// default constructor
TournamentTree::TournamentTree() {
    root = nullptr;
}

// destructor
TournamentTree::~TournamentTree() {
    delete root;
}

// getters
TournamentNode* TournamentTree::getRoot() {
    return root;
}

// double elimination helper
TournamentNode* TournamentTree::buildTreeFromMonsters(std::vector<Monster>& monsters) {
    std::vector<TournamentNode*> currentRound;

    for (Monster& m : monsters) {
        currentRound.push_back(new TournamentNode(m));
    }

    // building tournament tree
    while (currentRound.size() > 1) {
        std::vector<TournamentNode*> nextRound;
        for (size_t i = 0; i < currentRound.size(); i += 2) {
            if (i + 1 < currentRound.size()) {
                nextRound.push_back(new TournamentNode(currentRound[i], currentRound[i + 1]));
            } else {
                nextRound.push_back(currentRound[i]);
            }
        }
        currentRound = nextRound;
    }

    return currentRound[0];
}

void TournamentTree::buildSingleElimination(std::vector<Monster>& monsters) {
    root = buildTreeFromMonsters(monsters);
}

// NEW: expose internal method so RunScareGame can use it for losers
TournamentNode* TournamentTree::buildTreeFromMonstersPublic(std::vector<Monster>& monsters) {
    return buildTreeFromMonsters(monsters);
}

// dot file creation
void TournamentTree::saveTreeAsDot(const std::string& filename, TournamentNode* rootNode) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for DOT output: " << filename << "\n";
        return;
    }

    file << "digraph TournamentTree {\n";
    int nodeID = 0;
    saveTreeAsDotHelper(rootNode, file, nodeID);
    file << "}\n";
    file.close();
}


int TournamentTree::saveTreeAsDotHelper(TournamentNode* node, std::ofstream& file, int& nodeID) {
    if (node == nullptr) return -1;

    int currentID = nodeID++;
    file << "    node" << currentID << " [label=\"" << node->getWinner()->getName()
         << " (Power: " << node->getWinner()->getScreamLevel() << ")\"];\n";

    if (node->getLeft()) {
        int leftID = saveTreeAsDotHelper(node->getLeft(), file, nodeID);
        file << "    node" << currentID << " -> node" << leftID << ";\n";
    }

    if (node->getRight()) {
        int rightID = saveTreeAsDotHelper(node->getRight(), file, nodeID);
        file << "    node" << currentID << " -> node" << rightID << ";\n";
    }

    return currentID;
}



