#include <string>
#include <iostream>
#include <fstream>
#include "Dictionary.h"
#include "grid.h"
using namespace std;

void findMatches(const Dictionary& dict, const grid& g) //global func
{
  int imax = g.m.rows(), jmax = g.m.cols(); //bounds of matrix
  cout << "word \t start point (i, j) \t found_index" << endl; //formatting print
  
  //iterate through matrix; find all starting letters of possible words (must be 5 characters or more)
  for (int i = 0; i < imax; i++) //row iteration
  {
      for (int j = 0; j < jmax; j++) //column iteration
      {
        //check all possible words going across
        if ((jmax - j) >= 5)
        {
            string wordMaybe = "";
            for (int col = j; col < jmax; col++) //iterating across row to find possible letters of word
            {
                wordMaybe += g.m[i][col]; //possible word
                
                if (wordMaybe.length() >= 5) //check that word is 5 characters or more
                {
                    int found_index = dict.binarySearch(wordMaybe);
                    if (found_index != -1) //is it in the dictionary?
                    {
                        cout << wordMaybe << "\t (" << i << "," << j << ") \t" << found_index; //print results
                    }
                }
            }
        }

       //check all possible words going down
       if ((imax - j) >= 5)
       {
           string wordMaybe = "";
           for (int row = i; row < imax; row++) //iterating down columns to find possible letters of word
           {
               wordMaybe += g.m[row][j]; //possible word
               
               if (wordMaybe.length() >= 5) //words must be 5 characters or more
               {
                   int found_index = dict.binarySearch(wordMaybe);
                   if (found_index != -1) //is it in the dictionary?
                   {
                       cout << wordMaybe << "\t (" << i << "," << j << ") \t" << found_index; //print results
                   }
               }
           }
       }

       //check all possible words going diagonally
       if ((jmax - j) >= 5)
       {
           string wordMaybe = "";
           int row = i, col = j;
           
           while (row < imax && col < jmax) //iterating through matrix to find words on the diagonal
           {
               wordMaybe += g.m[row][col]; //possible word
               
               if (wordMaybe.length() >= 5) //words must be 5 characters or more
               {
                   int found_index = dict.binarySearch(wordMaybe);
                   if (found_index != -1) //is it in the dictionary?
                   {
                       cout << wordMaybe << "\t (" << i << "," << j << ") \t" << found_index; //print results
                   }
               }
               row++;
               col++;
          }
       }
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
