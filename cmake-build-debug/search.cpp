//
// Created by cohen on 6/11/2020.
//

#include "search.h"
/*
void grid :: readGrid() {
    //insert
}
*/
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

//completeWordSearch()
    //start timer
    //solve wordsearch with heap sort function
    //end and print time