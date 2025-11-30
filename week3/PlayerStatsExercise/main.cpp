#include "player.h"
#include <iostream>
#include <limits>

int main() {
    std::string name;
    std::cout << "Welcome Player 1! What is your name? ";
    getline(std::cin, name);
    Player player(name);
    int choice;

    while (choice != 5) {
        std::cout << "\nHello " << player.getName() << "! What would you like to do? \n\n1. Get my stats \n2. Set XP \n3. Set HP \n4. Change my name \n5. Exit" << std::endl;
        std::cin >> choice;

        while (std::cin.fail()) {
            std::cin.clear(); // clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a number: ";
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
                player.displayStats();
                break;
            case 2:
                std::cout << "Insert XP amount: ";
                int xp;
                std::cin >> xp;

                if (xp < 0 ){
                        std::cin.setstate(std::ios_base::failbit); //fails on the condition of out of bounds
                }

                while (std::cin.fail()) {
                    std::cin.clear(); // clear the fail state
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                    std::cout << "Invalid input. Please enter a positive integer: ";
                    std::cin >> xp;
                    if (xp < 0 ){
                        std::cin.setstate(std::ios_base::failbit); //fails on the condition of out of bounds
                    }
                }

                player.setXP(xp);
                break;
            case 3: {
                std::cout << "Insert HP amount: ";
                int hp;
                std::cin >> hp;
                
                if (hp < 0 ){
                    std::cin.setstate(std::ios_base::failbit); //fails on the condition of out of bounds
                }

                while (std::cin.fail()) {
                    std::cin.clear(); // clear the fail state
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                    std::cout << "Invalid input. Please enter a positive integer: ";
                    std::cin >> hp;
                    if (hp < 0 ){
                        std::cin.setstate(std::ios_base::failbit); //fails on the condition of out of bounds
                    }
                }

                player.setHP(hp);
                break;
            }
            case 4: {
                std::string newName;
                std::cout << "Enter new name: ";
                getline(std::cin >> std::ws, newName);
                player.setName(newName);
                break;
            }
            case 5: {
                std::cout << "Exiting program." << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Try again" << std::endl;
                break;
        }
    }

    return 0;
}