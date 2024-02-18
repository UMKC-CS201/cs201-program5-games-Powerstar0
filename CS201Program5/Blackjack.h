//
// Created by Johnny Diep on 2/1/24.
//

#ifndef CS201_PROGRAM5_GAMES_POWERSTAR0_BLACKJACK_H
#define CS201_PROGRAM5_GAMES_POWERSTAR0_BLACKJACK_H

#include <vector>
using namespace std;

struct Card{
    int suit;
    int value;
};

void createDeck(vector<Card> &deck);

Card dealCard(vector<Card> &deck);
//PRE: the deck has cards and is shuffled
//Post: returns the "top" card and removes from deck


void blackJack();
//Pre: none
//Post: play the game: create deck,
//             shuffle deck, deal 2 cards to player
//             calc hand total, loop till player says stop
//             deal cards to dealer as long total <= 17
//             compare totals - determine winner
//             loop to play another game

#endif //CS201_PROGRAM5_GAMES_POWERSTAR0_BLACKJACK_H
