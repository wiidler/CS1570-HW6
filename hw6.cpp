// Programmer: Will Weidler
// ID: wawq97
// Date: 3/19/22
// File: hw6.cpp
// Assignment: HW6
// Purpose: This file contains a program that observes a bee outbreak.

#include "infestation.h"
#include "constants.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string infestationMap[ROWS][COLUMNS];
    initializeMap(infestationMap, ROWS, COLUMNS);
    /*
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){ //USED FOR TESTING LATER?
            cout << infestationMap[i][j];
        }
        cout << endl;
    }
    */
    beginInfestation(infestationMap, ROWS, COLUMNS);
    return 0;
}