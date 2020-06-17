//
// Created by cohen on 6/17/2020.
//

#ifndef WORDSEARCH_HEAP_H
#define WORDSEARCH_HEAP_H

#include <vector>
#include <string>
#include <iostream>
#include "search.h"
using namespace std;
/*
template <typename T>

class Heap {

private:
    vector<T> worldList;

public:

    Heap();

    int parent(int x) {
        return (x+1)/2-1;
    }
    int left(int x) {
        return 2*(x+1)-1;
    }
    int right(int x) {
        return 2*(x+1);
    }
    T &getItem(int x) {
        return list[x];
    }

    int getIndex(T &indexVal);
    int size() {return list.size();}

    void initializeMaxHeap(vector<T> worldList2);
    void maxHeapify(int i, int heapSize);
    void buildMaxHeap(int heapSize);

    void initializeMinHeap(vector<T> worldList2);
    void minHeapify(int i, int heapSize);
    void buildMinHeap(int heapSize);

    void heapSort(int heapSize);

    T getMaxHeapMaximum();
    T getMinHeapMinimum();
};
*/

void Heapify(vector<string>, int n, int i);
void HeapSort(vector<string>, int n);



#endif //WORDSEARCH_HEAP_H
