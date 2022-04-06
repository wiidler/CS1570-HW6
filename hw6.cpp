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
    cout << "Initializing map from input file..." << endl;
    initializeMap(infestationMap, ROWS, COLUMNS);
    cout << "Beginning infestation." << endl;
    beginInfestation(infestationMap);
    cout << "Reporting results to output file..." << endl;
    exportMap(infestationMap, ROWS, COLUMNS);
    return 0;
}  