#include "wordSearch_Head.h"
//#include "search.h"
//#include "cmake-build-debug/search.h"

int main(){
	int choosenSort;
	int insertionSort(1), quickSort(2), mergeSort(3);

	cout << "Choose Sorting Algorithm Number: \n 1.InsertionSort \n 2.QuckSort \n 3.MergeSort" <<endl;
	cout << "Input: ";
	cin >> choosenSort;

	if( choosenSort == insertionSort )
		search(insertionSort);
	else if( choosenSort == quickSort ) 
		search(quickSort);
	else
		search(mergeSort); 
}
