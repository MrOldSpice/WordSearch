//
// Created by cohen on 6/16/2020.
//

#ifndef WORDSEARCH_HEAP_H
#define WORDSEARCH_HEAP_H
#include <vector>
#include <iostream>

using namespace std;

template <typename T>

class Heap {
private:
    vector<T> worldList;
public:
    Heap();

    void initializeMaxHeap(vector<T> worldList2);
    void initializeMinHeap(vector<T> worldList2);

    void maxHeapify(int i, int heapSize);
    void buildMaxHeap(int heapSize);

    void minHeapify(int i, int heapSize);
    void buildMinHeap(int heapSize);
    void heapSort(int heapSize);

    int parent(int i) {return (i+1)/2-1;}
    int left(int i) {return 2*(i+1)-1;}
    int right(int i) {return 2*(i+1);}
    T &getItem(int i) {return list[i];}

    T getMaxHeapMaximum();
    T getMinHeapMinimum();
    int getIndex(T &key)
};

template <typename T>
int Heap<T>::getIndex(T &key) {
    for (int i = 0; i < size(); i++)
        if (getItem(i) == key)
            return i;
}

template <typename T>
Heap<T>::Heap(){

}

template <typename T>
void Heap<T>::initializeMaxHeap(vector<T> worldList2) {
    for (int i = 0; i < worldList2.size(); i++)
        worldList.push_back(worldList2[i]);

    buildMaxHeap(size());
}

template <typename T>
void Heap<T>::initializeMinHeap(vector<T> worldList2) {
    for (int i = 0; i < worldList2.size(); i++)
        worldList.push_back(worldList2[i]);

    buildMinHeap(size());
}

template <typename T>
void Heap<T>::maxHeapify(int i, int heapSize) {
    int l = left(i);
    int r = right(i);
    int largest;

    if (l <= heapSize-1 && list.at(l) > list.at(i))
        largest = l;
    else
        largest = i;

    if (r <= heapSize-1 && list.at(r) > list.at(largest))
        largest = r;

    if (largest != i) {
        swap(worldList[i],worldList[largest]);
        maxHeapify(largest, heapSize);
    }
}

template <typename T>
void Heap<T>::minHeapify(int i, int heapSize){

    int l = left(i);
    int r = right(i);
    int smallest;

    if (l <= heapSize-1 && worldList.at(l) < worldList.at(i))
        smallest = l;
    else
        smallest = i;

    if (r <= heapSize-1 && worldList.at(r) < worldList.at(smallest))
        smallest = r;

    if (smallest != i) {
        swap(worldList[i],worldList[smallest]);
        minHeapify(smallest, heapSize);
    }
}

template <typename T>
void Heap<T>::buildMaxHeap(int heapSize) {
    for (int i = (size()+1)/2; i >= 0; i--)
        maxHeapify(i, heapSize);
}

template <typename T>
void Heap<T>::buildMinHeap(int heapSize) {
    for (int i = (size()+1)/2; i >= 0; i--)
        minHeapify(i, heapSize);
}

template <typename T>
T Heap<T>::getMinHeapMinimum() {
    return worldList[0];
}

template <typename T>
T Heap<T>::getMaxHeapMaximum() {
    return worldList[0];
}

template <typename T>
void Heap<T>::heapSort(int heapSize) {
    buildMaxHeap(heapSize);

    for (int i = size()-1; i >= 0; i--) {
        swap(worldList[0],worldList[i]);
        heapSize--;
        maxHeapify(0,heapSize);
    }
}
#endif //WORDSEARCH_HEAP_H
