#include "player.h"
#include <iostream>

std::string Player::getName() { return Name; }
        
int Player::getXP() { return XP; }
        
int Player::getHP() { return HP; }

void Player::setName(std::string name) { Name = name; }
        
void Player::setXP(int xp) { XP = xp; };
        
void Player::setHP(int hp) { HP = hp; }

void Player::displayStats() {
    std::cout << "\nYour Stats\n-----------\nXP: " << XP << "\nHP: " << HP << std::endl;
}