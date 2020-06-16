//
// Created by cohen on 6/11/2020.
//

#include "search.h"
/*
void grid :: readGrid() {
    //insert
}
*/
hashDictionary :: hashDictionary(int index, string word) {
    this -> index = index;
    this -> word = word;

}

hashMapTable :: hashMapTable() {
    wordlist = new hashDictionary *[tableSize];
    for (int i = 0; i < tableSize; i++) {
        wordlist[i] = NULL;
    }}
int hashMapTable:: hash(int in1) {
    return  in1 % tableSize;

}
void hashMapTable :: addItem(int in1, string in2) {
    int hashed = hash(in1);
    while (wordlist[hashed] != NULL && wordlist[hashed]->index != in1) {
        hashed = hash(hashed + 1);
    }
    if (wordlist[hashed] != NULL)
        delete wordlist[hashed];
    wordlist[hashed] = new hashDictionary(in1, in2);
}

string hashMapTable ::inList(int in1) {
    int hashed = hash(in1);
    while (wordlist[hashed] != NULL && wordlist[hashed]->index != in1) {
        hashed = hash(hashed + 1);
    }
    if (wordlist[hashed] == NULL)
        return "X";
    else
        return wordlist[hashed]->word;
}
void hashMapTable::deleteItem(int in1) {
    int hashed = hash(in1);
    while (wordlist[hashed] != NULL) {
        if (wordlist[hashed]->index == in1)
            break;
        hashed = hash(hashed + 1);
    }
    if (wordlist[hashed] == NULL) {
        cout<<"No Element found at key "<< in1 <<endl;
        return;
    } else {
        delete wordlist[hashed];
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
    while (wordlist[i] != NULL){
        cout << inList(i) << endl;
        i++;
    }
}

hashMapTable :: ~hashMapTable() {
    int i = 0;
    while (wordlist[i] != NULL) {
        delete wordlist[i];
        i++;
    }
    delete[] wordlist;
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

//completeWordSearch()
    //start timer
    //solve wordsearch with heap sort function
    //end and print time