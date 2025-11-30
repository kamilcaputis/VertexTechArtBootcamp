#include "phone.h"
#include <iostream>

std::string Phone::getName() { return name; }

int Phone::getSerialNumber() { return serialNumber; }

int Phone::getBatteryLife() { return batteryLife; }
 
void Phone::setName(std::string newName) {
    name = newName;
    std::cout << "Name succesfully changed to " << name << std::endl;
}

void Phone::setSerialNumber(int newSerialNumber) {
    std::cout << "Changing serial number " << serialNumber << " to " << newSerialNumber << std::endl;
    serialNumber = newSerialNumber;
    std::cout << "Serial number succesfully changed to " << serialNumber << std::endl;
}

void Phone::chargeBattery(int amount) {
    batteryLife += amount;
    if (batteryLife > 100) {
        batteryLife = 100;
    } 
    std::cout << "charge succesful, current battery life: " << batteryLife << std::endl;
}

void Phone::makeCall() {
    if (batteryLife >= 5) {
        std::cout << "Making call ... current battery life: " << batteryLife << std::endl;
        batteryLife -= 5;
        std::cout << "Call successful\nremaining battery: " << batteryLife << std::endl;
    } 
    else {
        std::cout << "Low battery, please charge your phone before making a call." << std::endl;
    }
}
