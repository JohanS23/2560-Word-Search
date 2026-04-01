/*
WordSearch part a
EECE 2560
3/24/26
Group ID + #: ROBKLISYGRE 10
Dictionary.h
This file declares the dictionary class
*/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>
#include <iostream>
#include "heap.h"



using namespace std;

class Dictionary {
private:
    vector<string> words;   // stores all dictionary words

public:
    // Reads words from a file into the vector
    void readFromFile(const string& filename);

    // Sorts the words using selection sort
    void selectionSort();

    // Binary search for a word
    // Returns index if found, -1 otherwise
    int binarySearch(const string& key) const;

    // Getter (optional but useful for debugging or later use)
    int size() const;

    // Overloaded output operator to print dictionary
    friend ostream& operator<<(ostream& os, const Dictionary& dict);

    void quickSort();
    void heapsort();
};

#endif
