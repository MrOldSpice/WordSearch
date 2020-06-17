#include "wordSearch_Head.h"
#include "search.h"
#include "cmake-build-debug/search.h"
#include "heap.h"
using namespace std;

int main(){
    /*
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

*/
	string dictFile, gridFile;
    clock_t start, sortTime, end;

    hashMapTable hash;
	grid2 Grid;
    cout << "Enter Dictionary file name: ";
    cin  >> dictFile;
    cout << "Enter Grid file name: ";
    cin  >> gridFile;
    hash.read2hash(dictFile);
    Grid.readGrid(gridFile);
    Grid.printGrid();
    hash.hash2print();
    vector<string> hashvect;
    for (int i = 0; i < hash.wardlist.size() ; i++) {
        hashvect.push_back(hash.wardlist[i].word);
    }
    //Start Timer
    start = clock();
    cout << "\nTimer Started" << endl;


    //sort dictionary based on 'sortAlgorithm'
    //heapsort
    HeapSort(hashvect, (int)hashvect.size()-1);
    cout << "Here" << endl;
    //Take time to sort
    sortTime = clock();

    //Run word search solver
    findMatches(hash, Grid);

    //Stop timer
    end = clock();
    float tot_sortTime = float(sortTime - start) / float(CLOCKS_PER_SEC);
    float tot_Time     = float(end - start) / float(CLOCKS_PER_SEC);
    cout << "SortTime: " << fixed << tot_sortTime << " seconds" << endl;
    cout << "Runtime: "  << fixed << tot_Time << " seconds" << endl;

    return 0;
}
