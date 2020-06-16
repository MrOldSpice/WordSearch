#ifndef WORDSEARCH_SEARCH_H
#define WORDSEARCH_SEARCH_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;

class grid {
public:
    vector<vector<string>> letterGrid;
    void readGrid();
};

class hashDictionary{
public:
    int index;
    string word;
    hashDictionary(int , string);
};

class hashMapTable{
private:
    hashDictionary **wordlist;
    const int tableSize;
public:
    hashMapTable();

    int hashFunct(int);
    void insert();
    int searchkey(int);
    void remove(int);

    ~hashMapTable();
};

//Heap classes (insert here)

void readDictionary(); //read dictionary file and assign to hash table

void completeWordSearch(); //execute word search and print runtime

#endif //WORDSEARCH_SEARCH_H
