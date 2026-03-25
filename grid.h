/*
WordSearch part a
EECE 2560
3/24/26
Group ID + #: ROBKLISYGRE 10
grid.h
This file declares the grid class
*/

#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

class grid {
public:
    matrix<char> m; // create the maxtrix

    grid(string file_name, int r, int c) : m(r, c, 0) { // pass the file name, rows and collums into the constructor
        ifstream inputFile(file_name);
        if (!inputFile) // file error handling
            cout << "Error: could not open file" << endl;
        int rows, cols;
        inputFile >> rows >> cols;  // skip the first line (dimensions)

        for (int i = 0; i < m.rows(); i++) // iterate through the matrix and add the corrisponding element to the matrix
            for (int j = 0; j < m.cols(); j++)
                inputFile >> m[i][j];
    }
};
