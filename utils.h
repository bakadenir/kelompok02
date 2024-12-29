#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>

using namespace std;

inline bool validateInput(int& choice) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

inline bool validateInput(double& value) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

inline bool validateInput(int& choice, int min, int max) {
    return validateInput(choice) && (choice >= min && choice <= max);
}

#endif 
