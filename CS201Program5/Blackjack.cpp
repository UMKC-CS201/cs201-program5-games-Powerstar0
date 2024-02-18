//
// Created by Johnny Diep on 2/1/24.
//
#include <iostream>
#include <vector>

using namespace std;

struct Card{
    int suit;
    int value;
};

int calcHandTotal(vector<Card> hand){
    return 0;
}
//FIX LATER
//void showHand(vector<Card>){
//    for (int i = 0; )
//}

Card dealCard(vector<Card> &deck){
//PRE: the deck has cards and is shuffled
//Post: returns the "top" card and removes from deck
    Card tempCard = deck[0];
    deck.erase(deck.begin());
    return tempCard;
}

void createDeck(vector<Card> &deck){
    //Pre: deck is empty
    //Post: add all cards & shuffle
    srand(time(0));
    Card tempCard;
    for (int i = 1; i <= 13; i++){
        for (int j = 1; j <= 13; j++){
            tempCard.suit = i;
            tempCard.value = j;
            deck.push_back(tempCard);
        }
    }
    for (int i = 0; i < 52; i++){
        tempCard = deck[i];
        int idx = rand() % 52;
        deck[i] = deck[idx];
        deck[idx] = tempCard;
    }
    for (int i = 0; i < 52; i++){
        cout << deck[i].suit << " " << deck[i].value << endl;
    }
}

void blackJack() {
//Pre: none
//Post: play the game: create deck,
//             shuffle deck, deal 2 cards to player
//             calc hand total, loop till player says stop
//             deal cards to dealer as long total <= 17
//             compare totals - determine winner
//             loop to play another game
    vector <Card> theDeck, player, dealer;
    Card tempCard;
    int playerTotal = 0, dealerTotal = 0;
    createDeck(theDeck);
    tempCard = dealCard(theDeck);
    player.push_back(tempCard);
    player.push_back(dealCard(theDeck));
    //showHand(player);
}


