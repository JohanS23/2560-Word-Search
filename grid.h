#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

class grid {
public:
    matrix<char> m;

    grid(string file_name, int r, int c) : m(r, c, 0) {
        ifstream inputFile(file_name);
        if (!inputFile)
            cout << "Error: could not open file" << endl;
        int rows, cols;
        inputFile >> rows >> cols;  // skip the first line (dimensions)

        for (int i = 0; i < m.rows(); i++)
            for (int j = 0; j < m.cols(); j++)
                inputFile >> m[i][j];
    }
};
