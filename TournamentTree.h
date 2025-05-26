#ifndef TOURNAMENTTREE_H
#define TOURNAMENTTREE_H
#include <fstream>

#include "TournamentNode.h"
#include <vector>

class TournamentTree {
private:
    TournamentNode* root;
    TournamentNode* buildTreeFromMonsters(std::vector<Monster>& monsters);

public:
    TournamentTree(); // default constructor
    ~TournamentTree(); // destructor

    // builds a single elimination bracket
    void buildSingleElimination(std::vector<Monster>& monsters); 

    // getters
    TournamentNode* getRoot(); 

    // helper for double elimination
    TournamentNode* buildTreeFromMonstersPublic(std::vector<Monster>& monsters);

    // handles creation of dot files
    void saveTreeAsDot(const std::string& filename, TournamentNode* rootNode);
    int saveTreeAsDotHelper(TournamentNode* node, std::ofstream& file, int& nodeID);
};

#endif
