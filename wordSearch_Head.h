#ifndef wordSearch_head
#define wordSearch_head

#include <vector>
#include <string>
#include <time.h>
#include <iostream>
#include <fstream>
#include <list>
#include <bits/stdc++.h>
using namespace std;


class wordList{
public:
	vector<string>  dictionary;		// vector to store words in dictionary

	//Getting Words from file
	void readDictionary(string); 	//read words from dictionary, IN: file name
	void printDictionary();		//print all words in the dictionary

	//Sorting Algorithms
	void insertionSort();				//sort vector 'dictionary' using Insertion Sort (1)
	
	void quickSort(int low, int high);		//sort vector 'dictionary' using Quick Sort     (2)	
	int partition ( int low, int high);
    	
	vector<string> mergeSort(vector<string> m);	//sort vector 'dictionary' using Merge Sort     (3)
    	vector<string> merge(vector<string> left, vector<string> right);

	//Searching the Dictionary (Binary Search)
	bool findWord(string);		//return TRUE if string is contained in dictionary
};

class grid{
public:
	//2D vector to contain letters in the grid
	vector<vector<string>> letterGrid;	
	
	void readGrid(string);	//Read letters from grid, IN: file name
	void printGrid();	//Print the letter grid
};
/*
template <class T>
class hashTable{
public:
    list<pair<int, string>> table[10];
    int BUCKET;
    vector<vector<T>>;
<<<<<<< HEAD

    void addItem();
    void deleteItem();
    void inList();
};

    void addItem();
    void deleteItem();
    void inList();
};
*/


//Function findMatches
// Will print words that are in dictionary and on the grid
void findMatches(wordList, grid);

//Function search
// IN: the int input determines the the sorting algotithm used
// (1)Insertion Sort, (2)Quick Sort, (3)Merge Sort
// This is the function that will be used in main.cpp
// Will measure overall runtime
// Will prompt user to enter for Grid and Dictionary file names
// findMatches() will be used to solve the grid
void search(int);

#endif
