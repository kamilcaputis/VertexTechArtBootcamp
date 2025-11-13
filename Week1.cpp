#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

float farenheit(float celcius) {
    return (celcius * 1.8) + 32.0;
}

float miles(float km) {
    return (km * 0.621);
}

float kilos(float lbs) {
    return (lbs / 2.205);
}

float euro(float usd) {
    return (usd / 1.6);
}

float average(vector<int> vec) {
    return (accumulate(vec.begin(), vec.end(), 0.0))/vec.size();
}

bool findVal(vector<int> vec, int target) {
    auto it = find(vec.begin(), vec.end(), target);
    return it != vec.end();
}

vector<int> doubles(vector<int> vec){
    vector<int> output;
    for (int i = 0; i < vec.size(); i++){
        if (i % 2 == 0){
            output.push_back(vec[i] * 2);
        }
    }
    return output;
}

void challenge1() {
    string name;
    int age;

    //name and age
    cout << "What is your name? ";
    getline(cin, name);
    cout << "Hi " + name + "! What is your age?: ";
    cin >> age;
    cout << age << " is a great year!\n";
}

void challenge2() {
    //celcius to farenheit 
    float temp;
    cout << "Enter a temperature in Celcius: ";
    cin >> temp;
    cout << "That's "  << round(farenheit(temp)) <<  " degrees Farenheit!\n";

    //km to miles
    float km;
    cout << "Enter a distance in km: ";
    cin >> km;
    cout << "That's " << round(miles(km)) << " miles!\n";

    //pounds to kilos 
    float lbs;
    cout << "Enter a weight in pounds: ";
    cin >> lbs;
    cout << "That's " << kilos(lbs) << " kilograms!\n"; 

    //dollar to euros
    float usd;
    cout << "Enter a dollar amount: ";
    cin >> usd;
    cout << "That's "  << euro(usd) << " euros!\n";
}

void challenge3() {
    vector<int> vec = {2, 4, 5, 7};

    //print vector contents for context + average
    cout << "For vector: "; 
    for (int element : vec) {
        cout << element << " ";
    } 
    cout << "the average is: " << average(vec) << "\n";
}

void challenge4() {
    vector<int> vec;
    int num;
    int target;
    bool found;
    string inputs;

    cout << "Please enter a series of integers separated by spaces! Press Enter when done: ";
    //ignore ws in the input buffer so getline() doesn’t immediately read an empty line and return empty string
    getline(cin >> ws, inputs); 
    stringstream ss(inputs);
 
    while (ss >> num) {
        vec.push_back(num);
    }
    
    cout << "The sum of the values you entered is: " << accumulate(vec.begin(), vec.end(), 0.0) << "\n";
    cout << "The average of the values you entered is: " << average(vec) << "\n";
    cout << "The largest value in your vector is " << *max_element(vec.begin(), vec.end()) << "\n";
    cout << "The smallest value in your vector is " << *min_element(vec.begin(), vec.end()) << "\n";
    cout << "Enter an integer to check if it is in the vector: ";
    cin >> target;
    found = findVal(vec, target);
    cout << target << (found ? " is in the vector!" : " is not in the vector :(");
}

void challenge5(){
    vector<int> vec;
    string inputs;
    int num;

    cout << "Please enter a series of integers separated by spaces! Press Enter when done: ";
    
    getline(cin >> ws, inputs); 
    stringstream ss(inputs);
 
    while (ss >> num) {
        vec.push_back(num);
    }

    cout << "Every other value doubled is: ";
    for (int element : doubles(vec)) {
        cout << element << " ";
    } 

    cout << "\nThe reverse of your values is: ";
    for (int i = vec.size() - 1; i >= 0; i--){
        cout << vec.at(i) << " ";
    }
}

int main() {
    challenge1();
    challenge2();
    challenge3();
    challenge4();
    challenge5();
    return 0;
}
