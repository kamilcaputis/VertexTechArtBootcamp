#include "phone.h"
#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::string name;
    std::cout << "Name Phone: ";
    getline(std::cin, name);
    Phone myPhone(name, 2386754);
    int choice;
    
    while (choice != 6) {
        std::cout << "Choose an action for phone " << myPhone.getName() << ": \n1. Make Call \n2. Charge Battery \n3. Change Name \n4. Change Serial Number \n5. See My Phones \n6. Exit\n";
        std::cin >> choice;

        while (std::cin.fail()) {
            std::cin.clear(); // clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a number: ";
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
                myPhone.makeCall();
                break;
            case 2:
                std::cout << "Insert charge amount: ";
                int chargeAmount;
                std::cin >> chargeAmount;
                
                while (std::cin.fail()) {
                    std::cin.clear(); // clear the fail state
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                    std::cout << "Invalid input. Please enter a number: ";
                    std::cin >> chargeAmount;
                }

                myPhone.chargeBattery(chargeAmount);
                break;
            case 3: {
                std::string newName;
                std::cout << "Enter new name: ";
                getline(std::cin >> std::ws, newName);
                myPhone.setName(newName);
                break;
            }
            case 4: {
                std::cout << "Enter new serial number: ";
                int sNum;
                std::cin >> sNum;

                while (std::cin.fail()) {
                    std::cin.clear(); // clear the fail state
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                    std::cout << "Invalid input. Please enter a number: ";
                    std::cin >> sNum;
                    if (sNum < 0){
                        continue;
                    }
                }

                myPhone.setSerialNumber(sNum);
                break;
            }
            case 5: {
                std::vector<Phone> phones;
                phones.push_back(Phone("Galaxy", 12345));
                phones.push_back(Phone("Iphone", 12344));
                phones.push_back(Phone("Pixel", 12445));

                std::cout << "Your phone data:\n-----------------" << std::endl;
                for(Phone phones : phones) { // 'objects' is a copy of each element
                    std::cout << "Phone Name: " << phones.getName() << std::endl;
                    std::cout << "Serial Number: " << phones.getSerialNumber() << std::endl;
                    std::cout << "Battery Life: " << phones.getBatteryLife() << "\n" << std::endl;
                }
                break;
            }
            case 6: {
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
