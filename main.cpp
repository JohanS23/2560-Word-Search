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
    string gridFile;
    string dictFile = "Dictionary.txt";

    cout << "Enter grid filename: ";
    cin >> gridFile;

    ifstream in(gridFile);
    if (!in)
    {
        cout << "Error opening grid file." << endl;
        return;
    }

    int rows, cols;
    if (!(in >> rows >> cols))
    {
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

int main()
{
    search();
    return 0;
}
