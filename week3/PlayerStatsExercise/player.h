#pragma once
#include <string>

class Player {
    public:
        Player(std::string name): Name(name), XP(0), HP(10) {} 

        //getters
        std::string getName();
        int getXP();
        int getHP();

        //setters
        void setName(std::string name);
        void setXP(int xp);
        void setHP(int hp);

        //actions
        void displayStats();
    
    private: 
        std::string Name;
        int XP;
        int HP;
};