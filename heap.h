/*
WordSearch part b
EECE 2560
3/24/26
Group ID + #: ROBKLISYGRE 10
heap.h
This file defines a template heap class
that stores elements in a vector and
provides functions for building a max heap
and sorting using heapsort.
*/

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class heap
{
public:
    vector<T> items; //store heap elements

    //return parent index
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    //return left child index
    int left(int i)
    {
        return 2 * i + 1;
    }

    //return right child index
    int right(int i)
    {
        return 2 * i + 2;
    }

    //return item at index n
    T getItem(int n)
    {
        return items[n];
    }

    //initialize heap from vector and build max heap
    void initializeMaxHeap(const vector<T>& data)
    {
        items = data;
        buildMaxHeap();
    }

    //fix heap property starting at index i
    void maxHeapify(int i, int heapSize)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heapSize && items[l] > items[largest])
            largest = l;

        if (r < heapSize && items[r] > items[largest])
            largest = r;

        if (largest != i)
        {
            swap(items[i], items[largest]);
            maxHeapify(largest, heapSize);
        }
    }

    //build max heap from vector
    void buildMaxHeap()
    {
        for (int i = items.size() / 2 - 1; i >= 0; i--)
        {
            maxHeapify(i, items.size());
        }
    }

    //sort elements using heapsort and return sorted vector
    vector<T> heapsort()
    {
        buildMaxHeap();
        int heapSize = items.size();

        for (int i = items.size() - 1; i > 0; i--)
        {
            swap(items[0], items[i]);
            heapSize--;
            maxHeapify(0, heapSize);
        }

        return items;
    }
};

#endif