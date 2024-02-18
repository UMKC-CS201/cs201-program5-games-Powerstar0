// CS201Program5.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "Blackjack.h"
#include <iostream>
#include "Hangman.h"
#include <iomanip>
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
    std::locale::global(std::locale(""));
    srand(time(0));

    while (true) {
        char user_game;
        cout << "Games List" << endl;
        cout << "B - Blackjack" << endl;
        cout << "C - Craps" << endl;
        cout << "H - Hangman" << endl;
        cout << "T - TicTacToe" << endl;
        cout << "W - War" << endl;
        cout << "Q - Quit" << endl;
        cout << "What game would you like to play?" << endl;
        cin >> user_game;
        user_game = toupper(user_game);
        if (user_game == 'C') {
            playCraps();
        }
        else if (user_game == 'H') {
            vector<string> words;
            readFile(words);
            playHangman(words);
        }
        else if (user_game == 'B') {
            blackJack();
        }
        else if (user_game == 'Q') {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid Choice, please select one of the options" << endl;
        }
    }


    //Check words in wordList in vector
    /*for (auto i : words)
        cout << i << " ";
    cout << endl;*/
}

//Function Definition
int rollDice(int &die1, int &die2) {
    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    //cout << "  IN FUNCTION: " << die1 << " : " << die2 << endl;
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
    /* IF 7 or 11 - you win
  ELSE if 2,3 or 12 - you lose
  Else
      SET point value
      ROLL Dice
      WHILE (sum != point && sum != 7)
          ROLL dice
      TEST sum for WIN or LOSE */

    cout << "WELCOME TO CRAPS!" << endl;
    double net_worth = 50.00;
    char user_choice = 'Y';
    while (user_choice == 'Y') {
        cout << endl;
        bool win = false;
        double user_bet;
        cout << "Your net worth is: $" << fixed << setprecision(2) << net_worth << ". Please enter your bet: ";
        cin >> user_bet;
        while (user_bet > net_worth) {
            cout << "That is more than your net worth. Please enter your bet again: ";
            cin >> user_bet;
        }
        int d1 = 0, d2 = 0, sum = 0;
        sum = rollDice(d1, d2);
        cout << "You Rolled: " << d1 << " and " << d2 << " = " << sum << endl;
        if (sum == 7 || sum == 11){
            cout << "You Win!" << endl;
            win = true;
        }
        else if (sum == 2 || sum == 3 || sum == 12){
            cout << "You Lose!" << endl;
        }
        else {
            int point_value = sum;
            cout << "Your point is: " << point_value << endl;
            cout << endl;
            sum = rollDice(d1, d2);
            cout << "You Rolled: " << d1 << " and " << d2 << " = " << sum << endl;
            while (sum != point_value && sum != 7) {
                sum = rollDice(d1, d2);
                cout << "You Rolled: " << d1 << " and " << d2 << " = " << sum << endl;
            }
            if (sum == point_value) {
                cout << "You Win!" << endl;
                win = true;
            } else {
                cout << "You Lose!" << endl;
            }
    }
        if (win) {
            net_worth += user_bet;
        }
        else {
            net_worth -= user_bet;
            if (net_worth == 0) {
                cout << "Sorry - you are out of money. Don't make us escort you out - that would be embarrassing!!" << endl;
                return;
            }
        }
        cout << "Would you like to go again? (Y or N): ";
        cin >> user_choice;
        user_choice = toupper(user_choice);

    }
    cout << "Thank you for playing. Your net worth is: $" << net_worth << endl;


}

 