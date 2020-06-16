#include "wordSearch_Head.h"
#include "search.h"
#include "cmake-build-debug/search.h"

string dictionaryFile = "C:\\Users\\cohen\\Github\\WordSearch\\wordlist.txt";
string gridFile = "C:\\Users\\cohen\\Github\\WordSearch\\input15.txt";

int main(){
	//int insertionSort(1), quickSort(2), mergeSort(3);
	//search(2);

//USE BELOW FOR FASTER TESTING OF SORT ALGORITHMS

	//wordList test;
	//test.readDictionary("C:\\Users\\cohen\\Github\\WordSearch\\wordlist.txt");
    //	test.printDictionary();

    hashMapTable hash;
    hash.read2hash(dictionaryFile);
    hash.hash2print();
    cout << "end" << endl;
    return 0;

/*
    	test.insertionSort();
    	test.quickSort(0, test.dictionary.size()-1);
    	test.dictionary = test.mergeSort(test.dictionary);

    	test.printDictionary();
*/

}
