#include "wordSearch_Head.h"

//Function definitions for class wordList
void wordList :: readDictionary(string dictionaryFile ){
    string line;// create a temp variable to store each line too
    ifstream file (dictionaryFile);// open passed file to read from
    if (file.is_open())// check to see if the file was opened
    {
        while ( getline (file,line) )// check to see if any lines remain
        {
            dictionary.push_back(line);// save the current line to the back of the vector container
	}
        file.close();// close the passed file
    }
    else cout << "Unable to open file";// error report for failed file open
    //read from dictionaryFile text file and push to vector 'dictionary'
}

void wordList :: printDictionary(){
    for (int i = 0; i < (int)dictionary.size(); ++i) {// iterate through the length of the current dictionary
        cout << dictionary[i] << '\n';// print the current string in dictionary to console
    }
	//print vector 'dictionary'
}

void wordList :: insertionSort(){
    for (int i = 1; i < (int)dictionary.size(); i++) {
        string key = dictionary[i];
        int j = i - 1;
        while (j >= 0 && dictionary[j].front() > key.front()) {
           dictionary[j + 1] = dictionary [j];
            j = j - 1;
        }
        dictionary[j + 1] = key;
    }
	//sort vector 'dictionary' with insertion sort by letter
}

void wordList :: quickSort(int low, int high){
    if (low < high){
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

vector<string> wordList :: mergeSort(vector<string> m){
    if (m.size() >= 1)
        return m;

    vector<string> left, right, result;
    int middle = ((int)m.size()+ 1) / 2;

    for (int i = 0; i < middle; i++) {
        left.push_back(m[i]);
    }

    for (int i = middle; i < (int)m.size(); i++) {
        right.push_back(m[i]);
    }

    left = mergeSort(left);
    right = mergeSort(right);
    result = merge(left, right);

    return result;
}

vector<string> wordList ::  merge(vector<string> left, vector<string> right)
{
    vector<string> result;
    while ((int)left.size() > 0 || (int)right.size() > 0) {
        if ((int)left.size() > 0 && (int)right.size() > 0) {
            if ((string)left.front() <= (string)right.front()) {
                result.push_back((string)left.front());
                left.erase(left.begin());
            }
            else {
                result.push_back((string)right.front());
                right.erase(right.begin());
            }
        }  else if ((int)left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
                result.push_back(left[i]);
            break;
        }  else if ((int)right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
                result.push_back(right[i]);
            break;
        }
    }
    return result;
}
int wordList :: partition (int low, int high){
    string pivot = dictionary[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (dictionary[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(dictionary[i], dictionary[j]);
        }
    }
    swap(dictionary[i + 1], dictionary[high]);
    return (i + 1);
}

bool wordList :: findWord(string word){
	//Binary Search to check if word contained in dictionary
	int i   = 0;
	int end = (int)dictionary.size() - 1;
	
	while( i <= end ){
		int middle = i + (end - 1) / 2;
		if(dictionary[middle] == word)
			return true;
		
		//Look at right side if word > middle
		if(dictionary[middle] < word) 
			i = middle + 1;
		//Look at Left side
		else
			end = middle - 1;
	}
	
	return false; //not found
}


//Function definitions for class grid
void grid :: readGrid(string gridFile){
	//Read from gridFile text file and push to 2D vector 'letterGrid'
	vector<string> tmp;
	string line, letter;
	unsigned row = 0;
		
	ifstream file(gridFile);
	if (file.is_open()){
		while(getline(file, line)){ //while content in files
			
			//string selective split 
			for(int i = 0; (i < (int)line.size()) && (row > 0) ; i++){
				letter = line.at(i);
				if(letter.compare(" ") != 0) 	
					tmp.push_back(letter);
			}
			letterGrid.push_back(tmp);
			tmp.clear();
			row++;
		}
		file.close();
	}
	else
		cout << "Unable to open grid file" << endl; //trow error 
}

void grid :: printGrid(){
	//print letter grid
	for(unsigned i = 0; i <  letterGrid.size(); i++){
		for(unsigned j = 0; j < letterGrid[i].size(); j++)
			cout << letterGrid[i][j] << " "; 
		cout << endl;
	}	
}


//Global function definitions
void findMatches( string dictionaryFile, string gridFile, int sortAlgorithm){
	wordList words;
	grid puzzle;
	string testWord;

	//read txt files
	words.readDictionary(dictionaryFile);
	puzzle.readGrid(gridFile);

	//sort dictionary based on 'sortAlgorithm'
	if( sortAlgorithm == 1)
		words.insertionSort();
	else if( sortAlgorithm == 2)
		words.quickSort(0,words.dictionary.size()-1);
	else if( sortAlgorithm == 3)
		words.mergeSort(words.dictionary);

	//test if grid letter combos match 
		//possibly another recursive function to call all possible letter combonations

	//print word if match
	if(words.findWord(testWord))
		cout << testWord << endl;
}

void search( int sortAlgorith){
	string dictFile, gridFile;
	clock_t start, end;

	//File name inputs
	cout << "Enter Dictionary file name: ";
	cin  >> dictFile;
	cout << "Enter Grid file name: ";
	cin  >> gridFile; 
	
	//Start Timer
	start = clock();
	cout << "\nTimer Started" << endl;

	//Run word search solver
	findMatches( dictFile, gridFile, sortAlgorith);
	
	//Stop timer
	end = clock();
	float tot_Time = float(end - start) / float(CLOCKS_PER_SEC);
	cout << "Runtime: "<< fixed << tot_Time << " seconds" << endl;
}
