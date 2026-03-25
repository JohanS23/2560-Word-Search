#include <string>
#include <iostream>
#include <fstream>
#include <algorithm> // needed for safety if used later
#include "Dictionary.h"
#include "grid.h"
using namespace std;

void findMatches(const Dictionary& dict, const grid& g) //global func
{
    //bounds of matrix
    int imax = g.m.rows();
    int jmax = g.m.cols();

    cout << "word \t start point (i, j) \t found_index" << endl; //formatting print

    //iterate through matrix; find all starting letters of possible words (must be 5 characters or more)
    for (int i = 0; i < imax; i++) //row iteration
    {
        for (int j = 0; j < jmax; j++) //column iteration
        {

            //check all possible words going across to the right
            {
                string wordMaybe = "";
                for (int k = 0; k < jmax; k++) //iterating across row
                {
                    int col = (j + k) % jmax;
                    wordMaybe += g.m[i][col]; //possible word

                    if (wordMaybe.length() >= 5) //check that word is 5 characters or more
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1) //is it in the dictionary?
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t\t " << found_index << endl; //print results
                        }
                    }
                }
            }

            //check all possible words going down
            {
                string wordMaybe = "";
                for (int k = 0; k < imax; k++) //iterating down columns
                {
                    int row = (i + k) % imax;
                    wordMaybe += g.m[row][j]; //possible word

                    if (wordMaybe.length() >= 5) //check the word is 5 characters or more
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1) //is it in the dictionary?
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t\t " << found_index << endl; //print results
                        }
                    }
                }
            }

            //check all possible words going diagonally (down to the right)
            {
                string wordMaybe = "";
                int row = i, col = j;

                for (int k = 0; k < imax; k++) //iterate to find diagonal words
                {
                    int wrappedRow = (row + imax) % imax;
                    int wrappedCol = (col + jmax) % jmax;

                    wordMaybe += g.m[wrappedRow][wrappedCol]; //possible word

                    if (wordMaybe.length() >= 5) //words must be 5 characters or more
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1) //is it in the dictionary?
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t\t " << found_index << endl; //print results
                        }
                    }

                    row++;
                    col++;
                }
            }

            //check all possible words going across to the left
            {
                string wordMaybe = "";
                for (int k = 0; k < jmax; k++) //iterating across row
                {
                    int col = (j - k + jmax) % jmax;
                    wordMaybe += g.m[i][col]; //possible word

                    if (wordMaybe.length() >= 5) //word must be 5 letters or more
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1) //is it in the dictionary?
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t\t " << found_index << endl; //print results
                        }
                    }
                }
            }

            //check all possible words going up 
            {
                string wordMaybe = "";
                for (int k = 0; k < imax; k++) //iterating up columns
                {
                    int row = (i - k + imax) % imax;
                    wordMaybe += g.m[row][j]; //possible word

                    if (wordMaybe.length() >= 5) //word must be 5 letters or more
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1) //is it in the dictionary?
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t\t " << found_index << endl; //print results
                        }
                    }
                }
            }

            //check all possible words going diagonally (up to the left)
            {
                string wordMaybe = "";
                int row = i, col = j;

                for (int k = 0; k < imax; k++) //iterate diagonally though matrix
                {
                    int wrappedRow = (row + imax) % imax;
                    int wrappedCol = (col + jmax) % jmax;

                    wordMaybe += g.m[wrappedRow][wrappedCol]; //possible word

                    if (wordMaybe.length() >= 5) //word must be 5 letters or more
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1) //is it in the dictionary?
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t\t " << found_index << endl; //print results
                        }
                    }

                    row--;
                    col--;
                }
            }

            //check all possible words going diagonally (up to the right)
            {
                string wordMaybe = "";
                int row = i, col = j;

                for (int k = 0; k < imax; k++) //iterate diagonally through matrix
                {
                    int wrappedRow = (row + imax) % imax;
                    int wrappedCol = (col + jmax) % jmax;

                    wordMaybe += g.m[wrappedRow][wrappedCol]; //possible word

                    if (wordMaybe.length() >= 5) //word must be 5 letters or more
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1) //is it in the dictionary?
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t\t " << found_index << endl; //print results
                        }
                    }

                    row--;
                    col++;
                }
            }

            //check all possible words going diagonally (down to the left)
            {
                string wordMaybe = "";
                int row = i, col = j;

                for (int k = 0; k < imax; k++) //iterate diagonally through matrix
                {
                    int wrappedRow = (row + imax) % imax;
                    int wrappedCol = (col + jmax) % jmax;

                    wordMaybe += g.m[wrappedRow][wrappedCol]; //possible word

                    if (wordMaybe.length() >= 5) //word must be 5 letters or more
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1) //is it in the dictionary?
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t\t " << found_index << endl; //print results
                        }
                    }

                    row++;
                    col--;
                }
            }

        }
    }
}

void search()
{
    string gridFile; // variable to store the grid file name entered by user
    string dictFile = "Dictionary.txt"; // dictionary file name (fixed)

    cout << "Enter grid filename: "; // prompt user for grid file
    cin >> gridFile; // read user input

    ifstream in(gridFile); // open the grid file
    if (!in) // check if file failed to open
    {
        cout << "Error opening grid file." << endl; // error message if file not found
        return; // exit function early
    }

    int rows, cols; // variables to store grid dimensions
    if (!(in >> rows >> cols)) // try to read dimensions from file
    {
        cout << "Error reading grid dimensions." << endl; // error if format is wrong
        return; // exit function
    }
    in.close(); // close file after reading dimensions

    Dictionary dict; // create dictionary object
    dict.readFromFile(dictFile); // load words from dictionary file
    dict.selectionSort(); // sort dictionary for binary search

    grid g(gridFile, rows, cols); // create grid object using file and dimensions

    findMatches(dict, g); // search for matching words in the grid
}
int main()
{
    search();
    return 0;
}
