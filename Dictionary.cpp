/*
WordSearch part a
EECE 2560
3/24/26
Group ID + #: ROBKLISYGRE 10
Dictionary.cpp
This file defines the dictionary class
*/

#include "Dictionary.h"
#include <fstream>

// Read words from file into vector
void Dictionary::readFromFile(const string& filename) {
    ifstream file(filename);
    string word;

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (file >> word) {
        words.push_back(word);
    }

    file.close();
}

// Selection sort implementation
void Dictionary::selectionSort() {
    int n = words.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (words[j] < words[minIndex]) {
                minIndex = j;
            }
        }

        // swap
        if (minIndex != i) {
            string temp = words[i];
            words[i] = words[minIndex];
            words[minIndex] = temp;
        }
    }
}

// Binary search implementation
int Dictionary::binarySearch(const string& key) const {
    int left = 0;
    int right = words.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (words[mid] == key) {
            return mid;
        } else if (words[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // not found
}

// QuickSort Implementation 
int Dictionary::partition(vector<string> &words, int low, int high) {

    // Selecting last element as the pivot
    string pivot = words[high];

    // Index of elemment just before the last element
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (words[j] <= pivot) {
            i++;
            swap(words[i], words[j]);
        }
    }

    swap(words[i + 1], words[high]);
    return (i + 1);
}

void Dictionary::quickSort(vector<string> &words, int low, int high) {

    if (low < high) {

        int pi = partition(words, low, high);

        quickSort(words, low, pi - 1);
        quickSort(words, pi + 1, high);
    }
}
// Return size of dictionary
int Dictionary::size() const {
    return words.size();
}

// Overloaded output operator
ostream& operator<<(ostream& os, const Dictionary& dict) {
    for (const string& word : dict.words) {
        os << word << endl;
    }
    return os;
}
