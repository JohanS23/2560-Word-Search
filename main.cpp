#include <string>
#include <iostream>
#include <fstream>
#include <algorithm> // needed for safety if used later
#include "Dictionary.h"
#include "grid.h"
using namespace std;

void findMatches(const Dictionary& dict, const grid& g)
{
    int imax = g.m.rows();
    int jmax = g.m.cols();

    cout << "word \t start point (i, j) \t found_index" << endl;

    for (int i = 0; i < imax; i++)
    {
        for (int j = 0; j < jmax; j++)
        {

            // → WRAP RIGHT
            {
                string wordMaybe = "";
                for (int k = 0; k < jmax; k++)
                {
                    int col = (j + k) % jmax;
                    wordMaybe += g.m[i][col];

                    if (wordMaybe.length() >= 5)
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1)
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t " << found_index << endl;
                        }
                    }
                }
            }

            // ↓ WRAP DOWN
            {
                string wordMaybe = "";
                for (int k = 0; k < imax; k++)
                {
                    int row = (i + k) % imax;
                    wordMaybe += g.m[row][j];

                    if (wordMaybe.length() >= 5)
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1)
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t " << found_index << endl;
                        }
                    }
                }
            }

            // ↘ WRAP DIAGONAL DOWN RIGHT
            {
                string wordMaybe = "";
                int row = i, col = j;

                for (int k = 0; k < imax; k++) // FIXED
                {
                    int wrappedRow = (row + imax) % imax;
                    int wrappedCol = (col + jmax) % jmax;

                    wordMaybe += g.m[wrappedRow][wrappedCol];

                    if (wordMaybe.length() >= 5)
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1)
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t " << found_index << endl;
                        }
                    }

                    row++;
                    col++;
                }
            }

            // ← WRAP LEFT
            {
                string wordMaybe = "";
                for (int k = 0; k < jmax; k++)
                {
                    int col = (j - k + jmax) % jmax;
                    wordMaybe += g.m[i][col];

                    if (wordMaybe.length() >= 5)
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1)
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t " << found_index << endl;
                        }
                    }
                }
            }

            // ↑ WRAP UP
            {
                string wordMaybe = "";
                for (int k = 0; k < imax; k++)
                {
                    int row = (i - k + imax) % imax;
                    wordMaybe += g.m[row][j];

                    if (wordMaybe.length() >= 5)
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1)
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t " << found_index << endl;
                        }
                    }
                }
            }

            // ↖ WRAP DIAGONAL UP LEFT
            {
                string wordMaybe = "";
                int row = i, col = j;

                for (int k = 0; k < imax; k++) // FIXED
                {
                    int wrappedRow = (row + imax) % imax;
                    int wrappedCol = (col + jmax) % jmax;

                    wordMaybe += g.m[wrappedRow][wrappedCol];

                    if (wordMaybe.length() >= 5)
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1)
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t " << found_index << endl;
                        }
                    }

                    row--;
                    col--;
                }
            }

            // ↗ WRAP DIAGONAL UP RIGHT
            {
                string wordMaybe = "";
                int row = i, col = j;

                for (int k = 0; k < imax; k++) // FIXED
                {
                    int wrappedRow = (row + imax) % imax;
                    int wrappedCol = (col + jmax) % jmax;

                    wordMaybe += g.m[wrappedRow][wrappedCol];

                    if (wordMaybe.length() >= 5)
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1)
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t " << found_index << endl;
                        }
                    }

                    row--;
                    col++;
                }
            }

            // ↙ WRAP DIAGONAL DOWN LEFT
            {
                string wordMaybe = "";
                int row = i, col = j;

                for (int k = 0; k < imax; k++) // FIXED
                {
                    int wrappedRow = (row + imax) % imax;
                    int wrappedCol = (col + jmax) % jmax;

                    wordMaybe += g.m[wrappedRow][wrappedCol];

                    if (wordMaybe.length() >= 5)
                    {
                        int found_index = dict.binarySearch(wordMaybe);
                        if (found_index != -1)
                        {
                            cout << wordMaybe << "\t (" << i << "," << j << ") \t " << found_index << endl;
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
