#include "Hangman.h"

using namespace std;

//PRE vector is empty
//POST vector will be loaded with words from wordlist.txt
void readFile(vector<string> &wordList) {
    //name file
    ifstream inFile;
    //open file
    inFile.open(R"(C:\Users\Johnny\CLionProjects\cs201-program5-games-Powerstar0\CS201Program5\wordList.txt)");
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

//Randomly choose a word

void playHangman(const vector<string> &wordlist) {
//choose random word from wordlist (0-size()-1) and store as string
//create a string of ? the length of the word chosen
//set number of guesses to 6

//Used CHATGPT to help draft the code for this section
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


    string randomWord = wordlist[rand() % wordlist.size()];
    string displayWord(randomWord.length(), '?'); // Inspired by CHATGPT
    int numGuesses = 6;

    cout << "HANGMAN - your word is: " << displayWord << endl;
    while ((displayWord != randomWord) && (numGuesses > 0)) {
        // Guess a letter
        char guess;
        cout << "Enter your guess: ";
        cin >> guess;
        guess = tolower(guess);
        bool found = false;
        //Checks if there are any matches
        for (int i = 0; i < randomWord.size(); i++) {
            if (guess == randomWord[i]) {
                displayWord[i] = guess;
                found = true;
            }
        }
        //Tells user if the guess was successful and updates the word
        if (displayWord == randomWord) {
            cout << "Nice Guess! You WIN!!!! The word was " << displayWord << endl;
            return;
        }
        if (found) {
            cout << "Nice Guess! You have " << numGuesses << " guesses left. Your current word: " << displayWord;
        }
        else {
            numGuesses -= 1;
            if (numGuesses == 0) {
                cout << "Sorry! Guess is not valid and you are out of guesses. You lose! The word was " << randomWord << endl;
                return;
            }
            cout << "Sorry! Guess is not valid. You have " << numGuesses << " left. Your current word: " << displayWord;
        }
        cout << endl;
    }




};
