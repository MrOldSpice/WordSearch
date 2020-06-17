//
// Created by cohen on 6/11/2020.
//

#include "search.h"

/* -----Function definitions for class grid----- */

void grid2 :: readGrid(string gridFile){
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

void grid2 :: printGrid(){
    //print letter grid
    for(unsigned i = 0; i <  letterGrid.size(); i++){
        for(unsigned j = 0; j < letterGrid[i].size(); j++)
            cout << letterGrid[i][j] << " ";
        cout << endl;
    }
}

hashDictionary :: hashDictionary(int index) {
    this -> index = index;
    this -> isNULL = NULL;
}


hashDictionary :: hashDictionary(int index, string word) {
    this -> index = index;
    this -> word = word;
    this -> isNULL = true;
    //this ->Dictionary.push_back(make_pair(index,word));

}

hashMapTable :: hashMapTable() {
    //wordlist = new hashDictionary *[tableSize];
    for (int i = 0; i < tableSize; i++) {
        //wordlist[i] = NULL;
        wardlist.emplace_back(i);
    }
}
int hashMapTable:: hash(int in1) {
    return  in1 % tableSize;

}
void hashMapTable :: addItem(int in1, string in2) {
    int hashed = hash(in1);
    while (wardlist[hashed].isNULL != NULL && wardlist[hashed].index != in1) {
        hashed = hash(hashed + 1);
    }
    if (wardlist[hashed].isNULL != NULL){
        wardlist.erase(wardlist.begin()+hashed);
    }
    wardlist[hashed] = hashDictionary(in1,in2);
}

string hashMapTable ::inList(int in1) {
    int hashed = hash(in1);
    while (wardlist[hashed].isNULL != NULL && wardlist[hashed].index != in1) {
        hashed = hash(hashed + 1);
    }
    if (wardlist[hashed].isNULL == NULL){
        return "X";
    }
    else
        return wardlist[hashed].word;
}
void hashMapTable::deleteItem(int in1) {
    int hashed = hash(in1);
    while (wardlist[hashed].isNULL != NULL) {
        if (wardlist[hashed].index == in1)
            break;
        hashed = hash(hashed + 1);
    }
    if (wardlist[hashed].isNULL != NULL) {
        cout<<"No Element found at key "<< in1 <<endl;
        return;
    } else {
        wardlist.erase(wardlist.begin()+hashed);
    }
    cout<<"Element Deleted"<<endl;
}
void hashMapTable :: read2hash(string dictionaryFile) {
    string line;// create a temp variable to store each line too
    int i = 0;
    ifstream file (dictionaryFile);// open passed file to read from
    if (file.is_open())// check to see if the file was opened
    {
        while (getline(file,line))// check to see if any lines remain
        {
            addItem(i, line);
            i++;
        }
        file.close();// close the passed file
    }
    else cout << "Unable to open file";// error report for failed file open
//read from dictionaryFile text file and push to vector 'dictionary'
}
void hashMapTable :: hash2print() {
    int i = 0;
    while (wardlist[i].isNULL != NULL){
        cout << inList(i) << endl;
        i++;
    }
}


hashMapTable :: ~hashMapTable() {
    int i = 0;
    while (wardlist[i].isNULL != NULL) {
        wardlist.erase(wardlist.begin()+i);
        i++;
    }
    wardlist.clear();
}


//deconstructor

/*
 *
HEAP SORT FUNCTIONS
 *
 */

//readDictionary()
    //open file
    //count and set dictionary size (number of words)
    //assign words to hashtable

bool hashMapTable :: findWord(string word){
    //Binary Search to check if word contained in dictionary
    int i   = 0;
    int end = (int)wardlist.size() -1;
    int sz  = word.size();

//cout  << " word : " << word  << endl;

    //if word is contained in dictionary
    while( end >= i+1 ){
        int middle = (i + end) / 2;

        if(wardlist[middle].word == word)
            cout << "\nFound: " << word << endl;

        //Look at right side if word > middle
        if(wardlist[middle].word < word)
            i = middle + 1;
            //Look at Left side
        else
            end = middle - 1;
    }


    //if word is contained in part of a dictionary word
    i   = 0;
    end = (int)wardlist.size() -1;
    while( end >= i+1 ){
        int middle = (i + end) / 2;

        if(wardlist[middle].word.substr(0,sz) == word){
//			cout << "Contained" << endl;
            return true;
        }

        //Look at right side if word > middle
        if(wardlist[middle].word.substr(0,sz) < word)
            i = middle + 1;
            //Look at Left side
        else
            end = middle - 1;
    }

    return false; //not found
}

void findMatches(hashMapTable words, grid2 puzzle){

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