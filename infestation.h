#ifndef INFESTATION_H
#define INFESTATION_H

#include "constants.h"
#include <iostream>
#include <fstream>

using namespace std;

/***********************FUNCTION PROTOTYPES***********************/
// Definition: Takes in info line by line in the input.txt file and assigns them to a 2d array
// Pre: An array must be initialized with size COLUMNS and there must be a file named input.txt
// Post: A fully defined array is created
void initializeMap(string array[][COLUMNS], const int ROWS, const int COLUMNS);
// Definition: Info from the input.txt changes the array based on various instances, all covering airdropping bees and mutating insects
// Pre: An array must be initialized with size COLUMNS and there must be a file named input.txt
// Post: The array is appended based on input.txt input
void beginInfestation(string array[][COLUMNS]);
// Definition: Exports the array to an output file called output.txt
// Pre: An array must be initialized with size COLUMNS
// Post: An output.txt file is made if not already made, and the contents share the array's contents
void exportMap(string array[][COLUMNS], const int ROWS, const int COLUMNS);
#endif