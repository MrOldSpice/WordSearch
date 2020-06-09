#include "wordSearch_Head.h"
int main(){
	//int insertionSort(1), quickSort(2), mergeSort(3);
	//search(3);


	//USE BELOW FOR FASTER TESTING OF SORT ALGORITHMS

	wordList test;
    test.readDictionary("C:\\Users\\cohen\\Github\\WordSearch\\puzzle10-words.txt");
    test.printDictionary();
    test.insertionSort();
    test.printDictionary();

}
