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
    } 
    fin.close();
    return;
}
void beginInfestation(string array[][COLUMNS], const int ROWS, const int COLUMNS){
    ifstream fin;
    fin.open("input.txt");
    int inputRow = -1;
    int inputColumn = -1;
    int lineNum = 0;
    string inputBuffer;
    while(lineNum != 10){
        fin >> inputBuffer;
        lineNum++;
    }
    do{
        fin >> inputRow;
        fin >> inputColumn;
        cout << inputRow << " " << inputColumn << endl;
        if((inputRow != 0 || inputRow != 9) && (inputColumn != 0 || inputColumn != 9)){
            if(array[inputRow][inputColumn] == "_"){
                array[inputRow][inputColumn] == "B";
            }
            else if(array[inputRow][inputColumn] == "B" || array[inputRow][inputColumn] == "W" || array[inputRow][inputColumn] == "T"){
                if(array[inputRow][inputColumn] == "B"){
                    if(array[inputRow - 1][inputColumn - 1] == "_"){
                        array[inputRow - 1][inputColumn - 1] = "B";
                    }                                                       // COVERS (-1,-1)
                    else if(array[inputRow - 1][inputColumn - 1] == "B"){
                        array[inputRow - 1][inputColumn - 1] = "W";
                    }
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "B";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "B"){
                        array[inputRow - 1][inputColumn] = "W";
                    }
                    if(array[inputRow - 1][inputColumn + 1] == "_"){
                        array[inputRow - 1][inputColumn + 1] = "B";
                    }                                                       // COVERS (-1,1)
                    else if(array[inputRow - 1][inputColumn + 1] == "B"){
                        array[inputRow - 1][inputColumn + 1] = "W";
                    }
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "B";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "B"){
                        array[inputRow][inputColumn - 1] = "W";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "B";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "B"){
                        array[inputRow][inputColumn + 1] = "W";
                    }
                    if(array[inputRow + 1][inputColumn - 1] == "_"){
                        array[inputRow + 1][inputColumn - 1] = "B";
                    }                                                       // COVERS (1,-1)
                    else if(array[inputRow + 1][inputColumn - 1] == "B"){
                        array[inputRow + 1][inputColumn - 1] = "W";
                    }
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "B";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "B"){
                        array[inputRow + 1][inputColumn] = "W";
                    }
                    if(array[inputRow + 1][inputColumn + 1] == "_"){
                        array[inputRow + 1][inputColumn + 1] = "B";
                    }                                                       // COVERS (1,1)
                    else if(array[inputRow + 1][inputColumn + 1] == "B"){
                        array[inputRow + 1][inputColumn + 1] = "W";
                    }
                }
                else if(array[inputRow][inputColumn] == "W"){
                    if(array[inputRow - 1][inputColumn - 1] == "_"){
                        array[inputRow - 1][inputColumn - 1] = "W";
                    }                                                       // COVERS (-1,-1)
                    else if(array[inputRow - 1][inputColumn - 1] == "W"){
                        array[inputRow - 1][inputColumn - 1] = "T";
                    }
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "W";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "W"){
                        array[inputRow - 1][inputColumn] = "T";
                    }
                    if(array[inputRow - 1][inputColumn + 1] == "_"){
                        array[inputRow - 1][inputColumn + 1] = "W";
                    }                                                       // COVERS (-1,1)
                    else if(array[inputRow - 1][inputColumn + 1] == "W"){
                        array[inputRow - 1][inputColumn + 1] = "T";
                    }
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "W";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "W"){
                        array[inputRow][inputColumn - 1] = "T";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "W";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "W"){
                        array[inputRow][inputColumn + 1] = "T";
                    }
                    if(array[inputRow + 1][inputColumn - 1] == "_"){
                        array[inputRow + 1][inputColumn - 1] = "W";
                    }                                                       // COVERS (1,-1)
                    else if(array[inputRow + 1][inputColumn - 1] == "W"){
                        array[inputRow + 1][inputColumn - 1] = "T";
                    }
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "W";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "W"){
                        array[inputRow + 1][inputColumn] = "T";
                    }
                    if(array[inputRow + 1][inputColumn + 1] == "_"){
                        array[inputRow + 1][inputColumn + 1] = "W";
                    }                                                       // COVERS (1,1)
                    else if(array[inputRow + 1][inputColumn + 1] == "W"){
                        array[inputRow + 1][inputColumn + 1] = "T";
                    }
                }
                else if(array[inputRow][inputColumn] == "T"){
                    array[inputRow - 1][inputColumn - 1] = "T"; // COVERS (-1,-1)
                    array[inputRow - 1][inputColumn] = "T";     // COVERS (-1,0)
                    array[inputRow - 1][inputColumn + 1] = "T"; // COVERS (-1,1)
                    array[inputRow][inputColumn - 1] = "T";     // COVERS (0,-1)
                    array[inputRow][inputColumn + 1] = "T";     // COVERS (0,1)
                    array[inputRow + 1][inputColumn - 1] = "T"; // COVERS (1,-1)
                    array[inputRow + 1][inputColumn] = "T";     // COVERS (1,0)
                    array[inputRow + 1][inputColumn + 1] = "T"; // COVERS (1,1)
                }
            }
        }
        else{
            if(array[inputRow][inputColumn] == "_"){
                array[inputRow][inputColumn] == "B";
            }
            else if(inputRow == 0 && inputColumn == 0){
                if(array[inputRow][inputColumn] == "B"){
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "B";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "B"){
                        array[inputRow + 1][inputColumn] = "W";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "B";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "B"){
                        array[inputRow][inputColumn + 1] = "W";
                    }
                    if(array[inputRow + 1][inputColumn + 1] == "_"){
                        array[inputRow + 1][inputColumn + 1] = "B";
                    }                                                       // COVERS (1,1)
                    else if(array[inputRow + 1][inputColumn + 1] == "B"){
                        array[inputRow + 1][inputColumn + 1] = "W";
                    }
                }
                else if(array[inputRow][inputColumn] == "W"){
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "W";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "W"){
                        array[inputRow + 1][inputColumn] = "T";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "W";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "W"){
                        array[inputRow][inputColumn + 1] = "T";
                    }
                    if(array[inputRow + 1][inputColumn + 1] == "_"){
                        array[inputRow + 1][inputColumn + 1] = "W";
                    }                                                       // COVERS (1,1)
                    else if(array[inputRow + 1][inputColumn + 1] == "W"){
                        array[inputRow + 1][inputColumn + 1] = "T";
                    }
                }
                else if(array[inputRow][inputColumn] == "T"){
                    array[inputRow + 1][inputColumn] = "T";
                    array[inputRow][inputColumn + 1] = "T";
                    array[inputRow + 1][inputColumn + 1] = "T";
                }
            }
            else if(inputRow == 0 && inputColumn == 9){
                if(array[inputRow][inputColumn] == "B"){
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "B";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "B"){
                        array[inputRow][inputColumn - 1] = "W";
                    }
                    if(array[inputRow + 1][inputColumn - 1] == "_"){
                        array[inputRow + 1][inputColumn - 1] = "B";
                    }                                                       // COVERS (1,-1)
                    else if(array[inputRow + 1][inputColumn - 1] == "B"){
                        array[inputRow + 1][inputColumn - 1] = "W";
                    }
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "B";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "B"){
                        array[inputRow + 1][inputColumn] = "W";
                    }
                }
                else if(array[inputRow][inputColumn] == "W"){
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "W";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "W"){
                        array[inputRow][inputColumn - 1] = "T";
                    }
                    if(array[inputRow + 1][inputColumn - 1] == "_"){
                        array[inputRow + 1][inputColumn - 1] = "W";
                    }                                                       // COVERS (1,-1)
                    else if(array[inputRow + 1][inputColumn - 1] == "W"){
                        array[inputRow + 1][inputColumn - 1] = "T";
                    }
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "W";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "W"){
                        array[inputRow + 1][inputColumn] = "T";
                    }
                }
                else if(array[inputRow][inputColumn] == "T"){
                    array[inputRow][inputColumn - 1] = "T";
                    array[inputRow + 1][inputColumn - 1] = "T";
                    array[inputRow + 1][inputColumn] = "T";

                }
            }
            else if(inputRow == 9 && inputColumn == 0){
                if(array[inputRow][inputColumn] == "B"){
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "B";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "B"){
                        array[inputRow - 1][inputColumn] = "W";
                    }
                    if(array[inputRow - 1][inputColumn + 1] == "_"){
                        array[inputRow - 1][inputColumn + 1] = "B";
                    }                                                       // COVERS (-1,1)
                    else if(array[inputRow - 1][inputColumn + 1] == "B"){
                        array[inputRow - 1][inputColumn + 1] = "W";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "B";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "B"){
                        array[inputRow][inputColumn + 1] = "W";
                    }
                }
                else if(array[inputRow][inputColumn] == "W"){
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "W";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "W"){
                        array[inputRow - 1][inputColumn] = "T";
                    }
                    if(array[inputRow - 1][inputColumn + 1] == "_"){
                        array[inputRow - 1][inputColumn + 1] = "W";
                    }                                                       // COVERS (-1,1)
                    else if(array[inputRow - 1][inputColumn + 1] == "W"){
                        array[inputRow - 1][inputColumn + 1] = "T";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "W";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "W"){
                        array[inputRow][inputColumn + 1] = "T";
                    }
                }
                else if(array[inputRow][inputColumn] == "T"){
                    array[inputRow - 1][inputColumn] = "T";
                    array[inputRow - 1][inputColumn + 1] = "T";
                    array[inputRow][inputColumn + 1] = "T";
                }
            }
            else if(inputRow == 9 && inputColumn == 9){
                if(array[inputRow][inputColumn] == "B"){
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "B";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "B"){
                        array[inputRow][inputColumn - 1] = "W";
                    }
                    if(array[inputRow - 1][inputColumn - 1] == "_"){
                        array[inputRow - 1][inputColumn - 1] = "B";
                    }                                                       // COVERS (-1,-1)
                    else if(array[inputRow - 1][inputColumn - 1] == "B"){
                        array[inputRow - 1][inputColumn - 1] = "W";
                    }
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "B";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "B"){
                        array[inputRow - 1][inputColumn] = "W";
                    }
                }
                else if(array[inputRow][inputColumn] == "W"){
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "W";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "W"){
                        array[inputRow][inputColumn - 1] = "T";
                    }
                    if(array[inputRow - 1][inputColumn - 1] == "_"){
                        array[inputRow - 1][inputColumn - 1] = "W";
                    }                                                       // COVERS (-1,-1)
                    else if(array[inputRow - 1][inputColumn - 1] == "W"){
                        array[inputRow - 1][inputColumn - 1] = "T";
                    }
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "W";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "W"){
                        array[inputRow - 1][inputColumn] = "T";
                    }
                }
                else if(array[inputRow][inputColumn] == "T"){
                    array[inputRow][inputColumn - 1] = "T";
                    array[inputRow - 1][inputColumn - 1] = "T";
                    array[inputRow - 1][inputColumn] = "T";;
                }
            }
            else if((inputRow > 0 && inputRow < 9) && inputColumn == 0){
                if(array[inputRow][inputColumn] == "B"){
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "B";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "B"){
                        array[inputRow - 1][inputColumn] = "W";
                    }
                    if(array[inputRow - 1][inputColumn + 1] == "_"){
                        array[inputRow - 1][inputColumn + 1] = "B";
                    }                                                       // COVERS (-1,1)
                    else if(array[inputRow - 1][inputColumn + 1] == "B"){
                        array[inputRow - 1][inputColumn + 1] = "W";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "B";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "B"){
                        array[inputRow][inputColumn + 1] = "W";
                    }
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "B";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "B"){
                        array[inputRow + 1][inputColumn] = "W";
                    }
                    if(array[inputRow + 1][inputColumn + 1] == "_"){
                        array[inputRow + 1][inputColumn + 1] = "B";
                    }                                                       // COVERS (1,1)
                    else if(array[inputRow + 1][inputColumn + 1] == "B"){
                        array[inputRow + 1][inputColumn + 1] = "W";
                    }
                }
                else if(array[inputRow][inputColumn] == "W"){
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "W";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "W"){
                        array[inputRow - 1][inputColumn] = "T";
                    }
                    if(array[inputRow - 1][inputColumn + 1] == "_"){
                        array[inputRow - 1][inputColumn + 1] = "W";
                    }                                                       // COVERS (-1,1)
                    else if(array[inputRow - 1][inputColumn + 1] == "W"){
                        array[inputRow - 1][inputColumn + 1] = "T";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "W";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "W"){
                        array[inputRow][inputColumn + 1] = "T";
                    }
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "W";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "W"){
                        array[inputRow + 1][inputColumn] = "T";
                    }
                    if(array[inputRow + 1][inputColumn + 1] == "_"){
                        array[inputRow + 1][inputColumn + 1] = "W";
                    }                                                       // COVERS (1,1)
                    else if(array[inputRow + 1][inputColumn + 1] == "W"){
                        array[inputRow + 1][inputColumn + 1] = "T";
                    }
                }
                else if(array[inputRow][inputColumn] == "T"){
                    array[inputRow - 1][inputColumn] = "T";
                    array[inputRow - 1][inputColumn + 1] = "T";
                    array[inputRow][inputColumn + 1] = "T";
                    array[inputRow + 1][inputColumn] = "T";
                    array[inputRow + 1][inputColumn + 1] = "T";
                }
            }
            else if((inputRow > 0 && inputRow < 9) && inputColumn == 9){
                if(array[inputRow][inputColumn] == "B"){
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "B";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "B"){
                        array[inputRow - 1][inputColumn] = "W";
                    }
                    if(array[inputRow - 1][inputColumn - 1] == "_"){
                        array[inputRow - 1][inputColumn - 1] = "B";
                    }                                                       // COVERS (-1,-1)
                    else if(array[inputRow - 1][inputColumn - 1] == "B"){
                        array[inputRow - 1][inputColumn - 1] = "W";
                    }
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "B";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "B"){
                        array[inputRow][inputColumn - 1] = "W";
                    }
                    if(array[inputRow + 1][inputColumn - 1] == "_"){
                        array[inputRow + 1][inputColumn - 1] = "B";
                    }                                                       // COVERS (1,-1)
                    else if(array[inputRow + 1][inputColumn - 1] == "B"){
                        array[inputRow + 1][inputColumn - 1] = "W";
                    }
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "B";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "B"){
                        array[inputRow + 1][inputColumn] = "W";
                    }
                }
                else if(array[inputRow][inputColumn] == "W"){
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "W";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "W"){
                        array[inputRow - 1][inputColumn] = "T";
                    }
                    if(array[inputRow - 1][inputColumn - 1] == "_"){
                        array[inputRow - 1][inputColumn - 1] = "W";
                    }                                                       // COVERS (-1,-1)
                    else if(array[inputRow - 1][inputColumn - 1] == "W"){
                        array[inputRow - 1][inputColumn - 1] = "T";
                    }
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "W";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "W"){
                        array[inputRow][inputColumn - 1] = "T";
                    }
                    if(array[inputRow + 1][inputColumn - 1] == "_"){
                        array[inputRow + 1][inputColumn - 1] = "W";
                    }                                                       // COVERS (1,-1)
                    else if(array[inputRow + 1][inputColumn - 1] == "W"){
                        array[inputRow + 1][inputColumn - 1] = "T";
                    }
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "W";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "W"){
                        array[inputRow + 1][inputColumn] = "T";
                    }
                }
                else if(array[inputRow][inputColumn] == "T"){
                    array[inputRow - 1][inputColumn] = "T";
                    array[inputRow - 1][inputColumn - 1] = "T";
                    array[inputRow][inputColumn - 1] = "T";
                    array[inputRow + 1][inputColumn - 1] = "T";
                    array[inputRow + 1][inputColumn] = "T";
                }
            }
            else if((inputColumn > 0 && inputColumn < 9) && inputRow == 0){
                if(array[inputRow][inputColumn] == "B"){
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "B";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "B"){
                        array[inputRow][inputColumn - 1] = "W";
                    }
                    if(array[inputRow + 1][inputColumn - 1] == "_"){
                        array[inputRow + 1][inputColumn - 1] = "B";
                    }                                                       // COVERS (1,-1)
                    else if(array[inputRow + 1][inputColumn - 1] == "B"){
                        array[inputRow + 1][inputColumn - 1] = "W";
                    }
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "B";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "B"){
                        array[inputRow + 1][inputColumn] = "W";
                    }
                    if(array[inputRow + 1][inputColumn + 1] == "_"){
                        array[inputRow + 1][inputColumn + 1] = "B";
                    }                                                       // COVERS (1,1)
                    else if(array[inputRow + 1][inputColumn + 1] == "B"){
                        array[inputRow + 1][inputColumn + 1] = "W";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "B";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "B"){
                        array[inputRow][inputColumn + 1] = "W";
                    }
                }
                else if(array[inputRow][inputColumn] == "W"){
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "W";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "W"){
                        array[inputRow][inputColumn - 1] = "T";
                    }
                    if(array[inputRow + 1][inputColumn - 1] == "_"){
                        array[inputRow + 1][inputColumn - 1] = "W";
                    }                                                       // COVERS (1,-1)
                    else if(array[inputRow + 1][inputColumn - 1] == "W"){
                        array[inputRow + 1][inputColumn - 1] = "T";
                    }
                    if(array[inputRow + 1][inputColumn] == "_"){
                        array[inputRow + 1][inputColumn] = "W";
                    }                                                       // COVERS (1,0)
                    else if(array[inputRow + 1][inputColumn] == "W"){
                        array[inputRow + 1][inputColumn] = "T";
                    }
                    if(array[inputRow + 1][inputColumn + 1] == "_"){
                        array[inputRow + 1][inputColumn + 1] = "W";
                    }                                                       // COVERS (1,1)
                    else if(array[inputRow + 1][inputColumn + 1] == "W"){
                        array[inputRow + 1][inputColumn + 1] = "T";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "W";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "W"){
                        array[inputRow][inputColumn + 1] = "T";
                    }
                }
                else if(array[inputRow][inputColumn] == "T"){
                    array[inputRow][inputColumn - 1] = "T";
                    array[inputRow + 1][inputColumn - 1] = "T";
                    array[inputRow + 1][inputColumn] = "T";
                    array[inputRow + 1][inputColumn + 1] = "T";
                    array[inputRow][inputColumn + 1] = "T";
                }
            }
            else if((inputColumn > 0 && inputColumn < 9) && inputRow == 9){
                if(array[inputRow][inputColumn] == "B"){
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "B";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "B"){
                        array[inputRow][inputColumn - 1] = "W";
                    }
                    if(array[inputRow - 1][inputColumn - 1] == "_"){
                        array[inputRow - 1][inputColumn - 1] = "B";
                    }                                                       // COVERS (-1,-1)
                    else if(array[inputRow - 1][inputColumn - 1] == "B"){
                        array[inputRow - 1][inputColumn - 1] = "W";
                    }
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "B";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "B"){
                        array[inputRow - 1][inputColumn] = "W";
                    }
                    if(array[inputRow - 1][inputColumn + 1] == "_"){
                        array[inputRow - 1][inputColumn + 1] = "B";
                    }                                                       // COVERS (-1,1)
                    else if(array[inputRow - 1][inputColumn + 1] == "B"){
                        array[inputRow - 1][inputColumn + 1] = "W";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "B";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "B"){
                        array[inputRow][inputColumn + 1] = "W";
                    }
                }
                else if(array[inputRow][inputColumn] == "W"){
                    if(array[inputRow][inputColumn - 1] == "_"){
                        array[inputRow][inputColumn - 1] = "W";
                    }                                                       // COVERS (0,-1)
                    else if(array[inputRow][inputColumn - 1] == "W"){
                        array[inputRow][inputColumn - 1] = "T";
                    }
                    if(array[inputRow - 1][inputColumn - 1] == "_"){
                        array[inputRow - 1][inputColumn - 1] = "W";
                    }                                                       // COVERS (-1,-1)
                    else if(array[inputRow - 1][inputColumn - 1] == "W"){
                        array[inputRow - 1][inputColumn - 1] = "T";
                    }
                    if(array[inputRow - 1][inputColumn] == "_"){
                        array[inputRow - 1][inputColumn] = "W";
                    }                                                       // COVERS (-1,0)
                    else if(array[inputRow - 1][inputColumn] == "W"){
                        array[inputRow - 1][inputColumn] = "T";
                    }
                    if(array[inputRow - 1][inputColumn + 1] == "_"){
                        array[inputRow - 1][inputColumn + 1] = "W";
                    }                                                       // COVERS (-1,1)
                    else if(array[inputRow - 1][inputColumn + 1] == "W"){
                        array[inputRow - 1][inputColumn + 1] = "T";
                    }
                    if(array[inputRow][inputColumn + 1] == "_"){
                        array[inputRow][inputColumn + 1] = "W";
                    }                                                       // COVERS (0,1)
                    else if(array[inputRow][inputColumn + 1] == "W"){
                        array[inputRow][inputColumn + 1] = "T";
                    }
                }
                else if(array[inputRow][inputColumn] == "T"){
                    array[inputRow][inputColumn - 1] = "T";
                    array[inputRow - 1][inputColumn - 1] = "T";
                    array[inputRow - 1][inputColumn] = "T";
                    array[inputRow - 1][inputColumn + 1] = "T";
                    array[inputRow][inputColumn + 1] = "T";
                }
            }
        }
    }while(fin);
    fin.close();
    return;
}
void exportMap(string array[][COLUMNS], const int ROWS, const int COLUMNS){
    ofstream fout;
    fout.open("output.txt");
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                fout << array[i][j];
            }
            fout << endl;
        }
    fout.close();
    return;
}