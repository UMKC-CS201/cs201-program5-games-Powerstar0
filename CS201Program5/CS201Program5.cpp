// CS201Program5.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "Blackjack.h"
#include <iostream>
#include "Hangman.h"
using namespace std;
//Function Delcarations
int rollDice(int &die1, int &die2);
//Pre: None
//Post: die1, die2, are generated and sum is returned

int rollDice(int &die1, int &die2, int &die3);
//Pre: None
//Post: die1, die2, die3 are generated and sum is returned

void playCraps();
//Pre: None
//Post: Play 1 round of craps

/* sum = rollDice(d1, d2, d3);
  cout << "You Rolled: " << d1 << " and " << d2 << " and " << d3 << " = " << sum << endl; */

int main() {
    //srand(time(0));
    //playCraps();
    vector<string> words;
    readFile(words);

    for (auto i : words)
        cout << i << " ";
    cout << endl;
}

//Function Definition
int rollDice(int &die1, int &die2) {
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    cout << "  IN FUNCTION: " << die1 << " : " << die2 << endl;
    return die1 + die2;
}

int rollDice(int &die1, int &die2, int &die3) {
    die1 = rand() % 8 + 1;
    die2 = rand() % 8 + 1;
    die3 = rand() % 8 + 1;
    cout << "  IN FUNCTION: " << die1 << " : " << die2 << " : " << die3 << endl;
    return die1 + die2 + die3;
}

void playCraps(){
    int d1 = 0, d2 = 0, sum = 0;
    sum = rollDice(d1, d2);
    cout << "You Rolled: " << d1 << " and " << d2 << " = " << sum << endl;
    if (sum == 7 || sum == 11){
        cout << "You Win!" << endl;
    }
    else if (sum == 2 || sum == 3 || sum == 12){
        cout << "You Lose!" << endl;
    }
    else{
        int point_value = sum;
        sum = rollDice(d1, d2);
        cout << "You Rolled: " << d1 << " and " << d2 << " = " << sum << endl;
        while (sum != point_value && sum != 7){
            sum = rollDice(d1, d2);
            cout << "You Rolled: " << d1 << " and " << d2 << " = " << sum << endl;
        }
        if (sum == point_value){
            cout << "You Win!" << endl;
        }
        else{
            cout << "You Lose!" << endl;
        }

    }

    /* IF 7 or 11 - you win
      ELSE if 2,3 or 12 - you lose
      Else
          SET point value
          ROLL Dice
          WHILE (sum != point && sum != 7)
              ROLL dice
          TEST sum for WIN or LOSE */

}

 