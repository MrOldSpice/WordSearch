#include "wordSearch_Head.h"
int main(){
	//int insertionSort(1), quickSort(2), mergeSort(3);
	//search(3);


	//USE BELOW FOR FASTER TESTING OF SORT ALGORITHMS

	wordList test;
    test.readDictionary("C:\\Users\\cohen\\Github\\WordSearch\\wordlist.txt");
    test.printDictionary();

    test.insertionSort();
    //test.quickSort(0, test.dictionary.size()-1);
    //test.dictionary = test.mergeSort(test.dictionary);

    test.printDictionary();

}
