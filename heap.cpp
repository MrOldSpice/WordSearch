#include "Heap.h"
/*
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
*/
void Heapify(vector<string> hashvect, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && hashvect[l] > hashvect[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && hashvect[r] > hashvect[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(hashvect[i], hashvect[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(hashvect, n, largest);
    }
}

// main function to do heap sort
void HeapSort(vector<string> hashvect, int n) {
    // Build heap (rearrange array)

    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(hashvect, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(hashvect[0], hashvect[i]);

        // call max heapify on the reduced heap
        Heapify(hashvect, i, 0);
    }

}
