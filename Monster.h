#ifndef MONSTER_H
#define MONSTER_H
#include<iostream>

class Monster{
    private:
        std::string name;
        int screamLevel;
        
    public:
        Monster(); // default constructor
        Monster(std::string name, int screamLevel); // parameterized constructor
        ~Monster(); // destructor

        // getters
        std::string getName();
        int getScreamLevel();

        // operator overload functions
        bool operator<(const Monster& other) const;
        bool operator>(const Monster& other) const;
        bool operator==(const Monster& other) const;
};

#endif 
