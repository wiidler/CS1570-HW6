#include "infestation.h"
#include "constants.h"
#include <iostream>
#include <fstream>

using namespace std;

/***********************FUNCTION DEFINITIONS***********************/
void initializeMap(string array[][COLUMNS], const int ROWS, const int COLUMNS){
    ifstream fin;
    fin.open("input.txt");
    for(int i = 0; i < ROWS; i++){
        string inputLine = "";
        getline(fin, inputLine);
        for(int j = 0; j < COLUMNS; j++){
            array[i][j] = inputLine[j];
        }
    } //NOT CLOSING BECAUSE THIS WILL NEVER BE THE LAST FUNCTION USING THIS TEXT FILE!
    return;
}
void beginInfestation(string array[][COLUMNS], const int ROWS, const int COLUMNS){
    ifstream fin;
    int inputRow, inputColumn = -1;
    do{
        fin >> inputRow;
        fin >> inputColumn;
        if(array[inputRow][inputColumn] == "B" || array[inputRow][inputColumn] == "W" || array[inputRow][inputColumn] == "T"){
            if(inputRow == 0){
                if(inputColumn == 0){
                    if(array[inputRow][inputColumn] == "B"){
                        array[inputRow][inputColumn] = "W";
                    }
                }
            }
        }
    }while(fin);
}