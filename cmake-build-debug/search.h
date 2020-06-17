#ifndef WORDSEARCH_SEARCH_H
#define WORDSEARCH_SEARCH_H

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include <vector>
#include <fstream>


using namespace std;
const int tableSize = 2311;

/*
class grid {
public:
    vector<vector<string>> letterGrid;
    void readGrid();
};
*/
class hashDictionary{
public:
    //vector <pair <int,string>> Dictionary;
    int index;
    string word;
    bool isNULL;
    hashDictionary(int);
    hashDictionary(int , string);
};

class hashMapTable{
public:
    vector <hashDictionary> wardlist;
    hashDictionary **wordlist;
public:
    hashMapTable();

    int hash(int);
    void addItem(int, string);
    string inList(int);
    void deleteItem(int);
    void read2hash(string);
    void hash2print();
    vector<hashDictionary> send2vect();
    ~hashMapTable();
};

//Heap classes (insert here)

void readDictionary(); //read dictionary file and assign to hash table

void completeWordSearch(); //execute word search and print runtime

#endif //WORDSEARCH_SEARCH_H
