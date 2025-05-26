#include "Monster.h"

// default constructor
Monster::Monster(){
    name = "";
    screamLevel = 0;
}

// parameterized constructor
Monster::Monster(std::string name, int screamLevel){
    this->name = name;
    this->screamLevel = screamLevel;
}

// destructor
Monster::~Monster(){}

// getters
std::string Monster::getName() { 
    return name; 
}
int Monster::getScreamLevel() { 
    return screamLevel; 
}

// operator overload functions
bool Monster::operator<(const Monster& other) const{
    return this->screamLevel < other.screamLevel;
}

bool Monster::operator>(const Monster& other) const{
    return this->screamLevel > other.screamLevel;
}

bool Monster::operator==(const Monster& other) const{
    return this->screamLevel == other.screamLevel;
}
