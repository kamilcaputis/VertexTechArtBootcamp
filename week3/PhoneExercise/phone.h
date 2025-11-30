#pragma once 
#include <string>

class Phone {
    public:
        Phone(std::string name, int serialNumber): batteryLife(10), name(name), serialNumber(serialNumber) {}
        
        //getters
        std::string getName();
        int getSerialNumber();
        int getBatteryLife();;

        //setters
        void setName(std::string newName);
        void setSerialNumber(int newSerialNumber);

        //actions
        void chargeBattery(int amount);
        void makeCall();
    
    private:
        std::string name;
        int serialNumber;
        int batteryLife;
};