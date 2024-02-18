

#ifndef CS201_PROGRAM5_GAMES_POWERSTAR0_HANGMAN_H
#define CS201_PROGRAM5_GAMES_POWERSTAR0_HANGMAN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//PRE vector is empty
//POST vector will be loaded with words from wordlist.txt
void readFile(vector<string> &wordList);

//PRE: vector has words to choose
//POST: play hangman
void playHangman(const vector<string> &wordlist);
#endif //CS201_PROGRAM5_GAMES_POWERSTAR0_HANGMAN_H


