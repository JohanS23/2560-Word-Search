#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include "grid.h"
using namespace std;

void findMatches(const Dictionary& dict, const Grid& grid)
{
  //read in grid and make into matrix format
  //know the matrix bounds
  string wordMaybe;
  int imax, jmax; //bounds of matrix

  int imax = g.m.rows();
  int jmax = g.m.cols();
  
  if (imax < 5 && jmax < 5)
  {
    return; //fixed
  }

  //big four loops, iterate through matrix finding all possible starting letters.
  for (int i = 0; i < imax; i++) //row iteration (imax is a matrix bound)
  {
      for (int j = 0; j < jmax; j++) //column iteration (jmax is matrix bound)
      {
        //check all possible words going down

        //check all possible words going diagonally

        //check all possible words going across
      }
  }
  
  
}

void search() {
    string gridFile;
    string dictFile = "Dictionary.txt";

    cout << "Enter grid filename: ";
    cin >> gridFile;

    ifstream in(gridFile);
    if (!in) {
        cout << "Error opening grid file." << endl;
        return;
    }

    int rows, cols;
    if (!(in >> rows >> cols)) {
        cout << "Error reading grid dimensions." << endl;
        return;
    }
    in.close();

    Dictionary dict;
    dict.readFromFile(dictFile);
    dict.selectionSort();

    grid g(gridFile, rows, cols);

    findMatches(dict, g);
}

int main ()
{
  search();
  return 0;
}
