#include "wordSearch_Head.h"

/* -----Function definitions for class wordList----- */
void wordList :: readDictionary(string dictionaryFile ){
//read from dictionaryFile text file and push to vector 'dictionary'
	string line;
    	ifstream file (dictionaryFile); //open file
    	if (file.is_open()){

        	while ( getline (file,line) ){ //while lines exist
			dictionary.push_back(line);	
		}

        	file.close();    
	}
    else cout << "Unable to open file";
}

void wordList :: printDictionary(){
	for (int i = 0; i < (int)dictionary.size(); ++i){
        	cout << dictionary[i] << '\n';
    	}
}

void wordList :: insertionSort(){
//sort vector 'dictionary' with insertion sort by letter
	for (int i = 1; i < (int)dictionary.size(); i++) {
        	string key = dictionary[i];
        	int j = i - 1;
        	while (j >= 0 && dictionary[j] > key) {
           		dictionary[j + 1] = dictionary [j];
            		j = j - 1;
        	}
        	dictionary[j + 1] = key;
    	}
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

vector<string> wordList ::  merge(vector<string> left, vector<string> right){
    
	vector<string> result;
    	while ((int)left.size() > 0 || (int)right.size() > 0) {
        if ((int)left.size() > 0 && (int)right.size() > 0) {
            	if ((string)left.front() <= (string)right.front()) {
                	result.push_back((string)left.front());
                	left.erase(left.begin());
            	}
            	else{
                	result.push_back((string)right.front());
                	right.erase(right.begin());
            	}
        }
	else if ((int)left.size() > 0) {
            	for (int i = 0; i < (int)left.size(); i++)
                	result.push_back(left[i]);
            	break;
        }  
	else if ((int)right.size() > 0) {
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
        	if (dictionary[j] <= pivot){
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
	int end = (int)dictionary.size() -1;
	int sz  = word.size();

//cout  << " word : " << word  << endl;
	
	//if word is contained in dictionary
	while( end >= i+1 ){
		int middle = (i + end) / 2;
		
		if(dictionary[middle] == word)	
			cout << "\nFound: " << word << endl;

		//Look at right side if word > middle
		if(dictionary[middle] < word) 
			i = middle + 1;
		//Look at Left side
		else
			end = middle - 1;
	}


	//if word is contained in part of a dictionary word
	i   = 0;
	end = (int)dictionary.size() -1;
	while( end >= i+1 ){
		int middle = (i + end) / 2;
	
		if(dictionary[middle].substr(0,sz) == word){	
//			cout << "Contained" << endl;
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

	int dimension  = puzzle.letterGrid.size();
	string testWord1, testWord2, testWord3, testWord4, testWord5, testWord6, testWord7, testWord8;

	//cycle through all grid points
	for(int i = 0; i < dimension; i++){ //rows
		for(int j = 0; j < dimension; j++){ //columns
// 			cout << "Source point: (" << j << ", " << i << ")"<< endl; //print location

		//Assign initial locations to all 8 travel directions
			testWord1  = puzzle.letterGrid[i][j];
			testWord2  = puzzle.letterGrid[i][j];
			testWord3  = puzzle.letterGrid[i][j];
			testWord4  = puzzle.letterGrid[i][j];
			testWord5  = puzzle.letterGrid[i][j];
			testWord6  = puzzle.letterGrid[i][j];
			testWord7  = puzzle.letterGrid[i][j];
			testWord8  = puzzle.letterGrid[i][j];

			
		//Horizontal and Verticle test
			int mvD(i), mvU(i), mvR(j), mvL(j);
			for( int l = 1; l < dimension ; l++){
				mvD++;	mvU--; //verticle movements
				mvR++;  mvL--; //horizontal movements

				//Grid wrapping Edge Cases
				if(mvU < 1) //reaches top end, go to bottom
					mvU  = dimension-1;
				
				if(mvD == dimension) //reaches bottom end, go to top
					mvD  = 0;
				
				if(mvR == dimension) //reaches right end, go to left end
					mvR = 0;
				
				if(mvL < 0) //reaches left end, go to right end
					mvL = dimension-1;

				//compound testWords and test if valid
				testWord1 = testWord1 + puzzle.letterGrid[mvU][j];
				words.findWord(testWord1);
					
				testWord2 = testWord2 + puzzle.letterGrid[i][mvR];
				words.findWord(testWord2);
				
				testWord3 = testWord3 + puzzle.letterGrid[mvD][j];
				words.findWord(testWord3);
		
				testWord4 = testWord4 + puzzle.letterGrid[i][mvL];
				words.findWord(testWord4);				
			}				


		//Positive Diagonal Checks
			mvU = i;  mvD = i;  mvR = j;  mvL = j; //ReInitialize movements
			int maxVisit = i + j;
			int count = 0;
			while (count < maxVisit ){
				int prevUp(mvU), prevDown(mvD), prevRight(mvR), prevLeft(mvL);//store previous position
				mvU--;  mvD++; //vertical movements
				mvL--;  mvR++; //horizontal movements

			//Positive diagonal UP 				
				if( mvU < 0 || mvR > (dimension-1)){ //Wrapping Edge Case
					mvU = prevRight; //swap
					mvR = prevUp;
				}
				testWord5 = testWord5 + puzzle.letterGrid[mvU][mvR];
				words.findWord(testWord5);

			//Positive diagonal Down
				if ( mvD > (dimension-1) || mvL < 0){ //Wrapping Edge Case
					mvD = prevLeft; //swap
					mvL = prevDown;
				}
				testWord6 = testWord6 + puzzle.letterGrid[mvD][mvL];			
				words.findWord(testWord6); 
				
				count++;
			}

	
		//Negative Diagonal Checks
			mvU = i;  mvD = i; mvL = j; mvR = j; //ReInitialize movements
			int moves = 0;
			while( moves < dimension ){ //Exclude corners
				int prevUp(mvU), prevDown(mvD), prevRight(mvR), prevLeft(mvL);//store previous position
				mvU--;  mvD++; //vertical movements
				mvL--;  mvR++; //horizontal movements
			
			//Negative diagonal UP
				if( mvU < 0 || mvL < 0){
					mvU = (dimension-1) - prevLeft;
					mvL = (dimension-1) - prevUp; 
				}
				testWord7 = testWord7 + puzzle.letterGrid[mvU][mvL];
				words.findWord(testWord7);

			//Negative diagonal DOWN
				if( mvD > (dimension-1) || mvR > (dimension-1)){
					mvD = (dimension-1) - prevRight;
					mvR = (dimension-1) - prevDown;
				}
				testWord8 = testWord8 + puzzle.letterGrid[mvD][mvR];
				words.findWord(testWord8);
	
				moves++;
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
	cin  >> dictFile;
	cout << "Enter Grid file name: ";
	cin  >> gridFile; 

//dictFile = "wordlist2.txt";
//gridFile = "input15.txt";
//dictFile = "C:\\Users\\cohen\\Github\\WordSearch\\15x15.txt";
//gridFile = "C:\\Users\\cohen\\Github\\WordSearch\\input15.txt";

        //read txt files
	words.readDictionary(dictFile);
	puzzle.readGrid(gridFile);
	puzzle.printGrid();

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
cout << "Here" << endl;	
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
