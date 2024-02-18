#include "Hangman.h"

using namespace std;

//PRE vector is empty
//POST vector will be loaded with words from wordlist.txt
void readFile(vector<string> &wordList) {
    //name file
    ifstream inFile;
    //open file
    inFile.open("wordList.txt");
    //verify it is open
    if (!inFile.is_open()) {
        cout << "Could not open the file\n";
        return;
    }
    //read file
    string tempWord;
    getline(inFile, tempWord);
    while (inFile.good()) {
        wordList.push_back(tempWord);
        getline(inFile, tempWord);
    }
    //close file
    inFile.close();
};

//PRE: vector has words to choose
//POST: play hangman

//Randomly choo

void playHangman(const vector<string> &wordlist) {
//choose random word from wordlist (0-size()-1) and store as string
//create a string of ? the length of the word chosen
//set number of guesses to 6

//while (word != ?word && number of guesses > 0)
    //guess a letter
    //is letter in the word? if so, update ???? word
    //if (word == ?word)
        //message to user "you win"
    //else
        //if not, reduce number og guesses
        //message to user ?? word & number of guesses left
        //if at 0 number of guesses - they lost
            //break




};
