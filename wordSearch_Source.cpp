#include "wordSearch_Head.h"

/* -----Function definitions for class wordList----- */
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
        while (j >= 0 && dictionary[j] > key) {
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
    if (m.size() <= 1)
        return m;

    vector<string> left, right, result;
    int middle = ((int)m.size()+ 1) / 2;

    //left side
    for (int i = 0; i < middle; i++) {
        left.push_back(m[i]);
    }

    //right side
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
	int sz  = word.size();
//word = "mot";
//cout  << word << endl;	
	while( end >= i+1 ){
		int middle = (i + (end - 1)) / 2;
//cout << dictionary[middle].substr(0,sz) << endl;
		if(dictionary[middle].substr(0,sz) == word){
			//cout << word << endl;
			if(dictionary[middle] == word){
				cout << "\n" << word << "\n" << endl;
				//add word to foundWords vector and so that while loop can stop
			}	
			return true;
		}
		//Look at right side if word > middle
		if(dictionary[middle].substr(0,sz) < word) 
			i = middle + 1;
		//Look at Left side
		else
			end = middle - 1;
	}
	
	return false; //not found
}


/* -----Function definitions for class grid----- */
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
			if (row > 0)
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


/* -----Global function definitions----- */
void findMatches(wordList words, grid puzzle){	
	string testWord1, testWord2, testWord3, testWord4, testWord5, testWord6, testWord7, testWord8;
	int dimension  = puzzle.letterGrid.size();
puzzle.printGrid();
cout << dimension <<"here  "<<puzzle.letterGrid[dimension-1][1] << endl;
	for(int i = 0; i <= dimension; i++){ //rows 
		for(int j = 0; j < dimension; j++){ //columns
 
			testWord1  = puzzle.letterGrid[i][j];
			testWord2  = puzzle.letterGrid[i][j];
			testWord3  = puzzle.letterGrid[i][j];
			testWord4  = puzzle.letterGrid[i][j];
			testWord5  = puzzle.letterGrid[i][j];
			testWord6  = puzzle.letterGrid[i][j];
			testWord7  = puzzle.letterGrid[i][j];
			testWord8  = puzzle.letterGrid[i][j];
			
			int mvD(i), mvU(i), mvR(j), mvL(j);
			bool p1(true), p2(true), p3(true), p4(true);
			cout << "Source point: (" << j << ", " << i << ")"<< endl; 
			for( int l = 1; l < dimension ; l++){
				mvD++;
				mvU--;
				mvR++;
				mvL--;
//cout<< mvU << endl;
				//Grid wrapping
				if(mvU < 1) //reaches top end
					mvU  = dimension-1; //go to bottom
				
				if(mvD == dimension) //reaches bottom end
					mvD  = 0; //go to top
				
				if(mvR == dimension) //reaches right end
					mvR = 0; //go to left end
				
				if(mvL < 0) //reaches left end
					mvL = dimension-1; //go to right end
				//if (positive diagonal UP direction where (mvU < 0 and mvR) || (mvR > size() and mnU))
					//swap i and j
				//if (positive diagonal DOWN direction where mvL < 0 || mvD > size() and mvD)
					//swap i and j
				//if (negative diagonal UP direction where mvL < 0
//cout<< mvU << " " << mvU << " " << mvU<< " " << mvU << endl;

//				testWord1 = testWord1 + puzzle.letterGrid[mvU][j];
//				cout << testWord1 << endl;
//				words.findWord(testWord1);


				//Expanding testWord_ in 8 directions
				bool result;
				//Horizontal and Verticle
				testWord1 = testWord1 + puzzle.letterGrid[mvU][j];
				result = words.findWord(testWord1);
					
				testWord2 = testWord2 + puzzle.letterGrid[i][mvR];
				result = words.findWord(testWord2);
				
				testWord3 = testWord3 + puzzle.letterGrid[mvD][j];
				result = words.findWord(testWord3);
		
				testWord4 = testWord4 + puzzle.letterGrid[i][mvL];
				result = words.findWord(testWord4);
				
				
//cout << "Good Until Here" <<endl; //must account for diagonal issue add possible counter to solve issue
				int tempX, tempY;
				if( mvU == (dimension-1) || mvR == 0){
					tempY = mvR;
					tempX = mvU;
				}
				else{
					tempY = mvU;
					tempX = mvR;
				}
			 	if( !(mvR == 0 && mvU == 0) || !(mvR == dimension-1 && mvU == dimension-1)){
					testWord5 = testWord5 + puzzle.letterGrid[tempY][tempX];				
					result = words.findWord(testWord5);
					cout << testWord5 << endl;
				}
/*			   	if (words.findWord(testWord5 + puzzle.letterGrid[mvU][mvR])) 
					testWord1 = testWord1 + puzzle.letterGrid[mvU][mvR];

				if (words.findWord(testWord6 + puzzle.letterGrid[mvD][mvR])) 
					testWord1 = testWord1 + puzzle.letterGrid[mvD][mvR];

			   	if (words.findWord(testWord7 + puzzle.letterGrid[mvU][mvL])) 
					testWord1 = testWord1 + puzzle.letterGrid[mvU][mvL];

				if (words.findWord(testWord8 + puzzle.letterGrid[mvD][mvL])) 
					testWord1 = testWord1 + puzzle.letterGrid[mvD][mvL];
*/
			}
		}
	} 
}

void search( int sortAlgorithm){
	wordList words;
	grid puzzle;
	string dictFile, gridFile;
	clock_t start, sortTime, end;

	//File name inputs
	cout << "Enter Dictionary file name: ";
//	cin  >> dictFile;
	cout << "Enter Grid file name: ";
//	cin  >> gridFile; 
dictFile = "wordlist2.txt";
gridFile = "input15.txt";	
	//read txt files
	words.readDictionary(dictFile);
	puzzle.readGrid(gridFile);

	//Start Timer
	start = clock();
	cout << "\nTimer Started" << endl;

	//sort dictionary based on 'sortAlgorithm'
	if( sortAlgorithm == 1)
		words.insertionSort();
	else if( sortAlgorithm == 2)
		words.quickSort(0,words.dictionary.size()-1);
	else if( sortAlgorithm == 3)
		words.dictionary = words.mergeSort(words.dictionary);
	
	//Take time to sort
	sortTime = clock();

	//Run word search solver
	findMatches(words, puzzle);

	//Stop timer
	end = clock();
	float tot_sortTime = float(sortTime - start) / float(CLOCKS_PER_SEC);
	float tot_Time     = float(end - start) / float(CLOCKS_PER_SEC);
	cout << "SortTime: " << fixed << tot_sortTime << " seconds" << endl;
	cout << "Runtime: "  << fixed << tot_Time << " seconds" << endl;
}
