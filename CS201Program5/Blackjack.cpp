//
// Created by Johnny Diep on 2/1/24.
//
#include <iostream>
#include <vector>
#define RESET   "\033[0m"
#define RED     "\033[31m"


using namespace std;

struct Card{
    int suit;
    int value;
    int color;
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
    for (int i = 1; i <= 4; i++){
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
    /*for (int i = 0; i < 52; i++){
        cout << deck[i].suit << " " << deck[i].value << endl;
    }*/
}

void blackJack() {
//Pre: none
//Post: play the game: create deck,
//             shuffle deck, deal 2 cards to player
//             calc hand total, loop till player says stop
//             deal cards to dealer as long total <= 17
//             compare totals - determine winner
//             loop to play another game
    cout << "WELCOME TO BLACKJACK!" << endl;
    vector <Card> theDeck, player, dealer;
    Card tempCard;
    int playerTotal = 0, dealerTotal = 0;
    createDeck(theDeck);
    tempCard = dealCard(theDeck);
    player.push_back(tempCard);
    player.push_back(dealCard(theDeck));
    //showHand(player);
    char user_choice;
    while (user_choice != 'N') {
        playerTotal = 0;
        int num_aces = 0;
        cout << "Player has the following cards: " << endl;
        for (auto &i: player) { //Loop filled by Pycharm
            string cardValue;
            int actualValue;
            if (i.value == 1) {
                cardValue = "A";
                actualValue = 11;
                num_aces += 1;
            }
            else if (i.value == 11) {
                cardValue = "J";
                actualValue = 10;
            }
            else if (i.value == 12) {
                cardValue = "Q";
                actualValue = 10;
            }
            else if (i.value == 13) {
                cardValue =  "K";
                actualValue = 10;
            }
            else {
                cardValue = to_string(i.value); //Clion suggestion
                actualValue = i.value;
            }
            switch (i.suit) {
                case 1: //Spades
                    cout << "\u2660" << ' ' << cardValue << endl;
                    break;
                case 2: // Hearts
                    cout << RED << "\u2665" << ' ' << cardValue << RESET << endl;
                    break;
                case 3: // Diamond
                    cout << RED << "\u2666" << ' ' << cardValue << RESET << endl;
                    break;
                case 4: // Club
                    cout << "\u2663" << ' ' << cardValue << endl;
                    break;
            }
            playerTotal += actualValue;
        }
        if (playerTotal > 21) {
            for (auto &i: player) {
                while ((num_aces > 0) && (playerTotal > 21))  {
                    num_aces -= 1;
                    playerTotal -= 10;
                }
            }
            if (playerTotal > 21) {
                cout << "TOTAL: " << playerTotal << endl;
                cout << "OOPS - PLAYER went over 21. COMPUTER WINS!!" << endl;
                return;
            }
        }
        cout << "TOTAL: " << playerTotal << endl;
        cout << endl;
        cout << "Would you like to take another card? Y or N: ";
        cin >> user_choice;
        user_choice = toupper(user_choice);
        cout << endl;
        if (user_choice != 'N') {
            player.push_back(dealCard(theDeck));
        }
    }
    dealer.push_back(dealCard(theDeck));
    dealer.push_back(dealCard(theDeck));
    cout << "Computer has the following cards: " << endl;
    int num_aces = 0;
    for (auto &i: dealer) {
        string cardValue;
        int actualValue;
        if (i.value == 1) {
            cardValue = "A";
            actualValue = 11;
            num_aces += 1;
        }
        else if (i.value == 11) {
            cardValue = "J";
            actualValue = 10;
        }
        else if (i.value == 12) {
            cardValue = "Q";
            actualValue = 10;
        }
        else if (i.value == 13) {
            cardValue =  "K";
            actualValue = 10;
        }
        else {
            cardValue = to_string(i.value); //Clion suggestion
            actualValue = i.value;
        }
        dealerTotal += actualValue;
        switch (i.suit) {
            case 1: //Spades
                cout << "\u2660" << ' ' << cardValue << endl;
                break;
            case 2: // Hearts
                cout << RED << "\u2665" << ' ' << cardValue << RESET << endl;
                break;
            case 3: // Diamond
                cout << RED << "\u2666" << ' ' << cardValue << RESET << endl;
                break;
            case 4: // Club
                cout << "\u2663" << ' ' << cardValue << endl;
                break;
        }
        if (dealerTotal > 21) {
            for (auto &i: dealer) {
                while ((num_aces > 0) && (dealerTotal > 21))  {
                    num_aces -= 1;
                    dealerTotal -= 10;
                }
            }
            if (dealerTotal > 21) {
                cout << endl;
                cout << "TOTAL: " << dealerTotal << endl;
                cout << "The dealer went over 21. You Win!" << endl;
                return;
            }
        }
    }
    cout << "TOTAL: " << dealerTotal << endl;
    cout << endl;
    while (dealerTotal <= 17) {
        dealerTotal = 0;
        cout << "Computer has the following cards: " << endl;
        num_aces = 0;
        dealer.push_back(dealCard(theDeck));
        for (auto &i: dealer) {
            string cardValue;
            int actualValue;
            if (i.value == 1) {
                cardValue = "A";
                actualValue = 11;
                num_aces += 1;
            } else if (i.value == 11) {
                cardValue = "J";
                actualValue = 10;
            } else if (i.value == 12) {
                cardValue = "Q";
                actualValue = 10;
            } else if (i.value == 13) {
                cardValue = "K";
                actualValue = 10;
            } else {
                cardValue = to_string(i.value); //Clion suggestion
                actualValue = i.value;
            }
            dealerTotal += actualValue;
            switch (i.suit) {
                case 1: //Spades
                    cout << "\u2660" << ' ' << cardValue << endl;
                    break;
                case 2: // Hearts
                    cout << RED << "\u2665" << ' ' << cardValue << RESET << endl;
                    break;
                case 3: // Diamond
                    cout << RED << "\u2666" << ' ' << cardValue << RESET << endl;
                    break;
                case 4: // Club
                    cout << "\u2663" << ' ' << cardValue << endl;
                    break;
            }
        }
        if (dealerTotal > 21) {
            for (auto &i: dealer) {
                while ((num_aces > 0) && (dealerTotal > 21))  {
                    num_aces -= 1;
                    dealerTotal -= 10;
                }
            }
            if (dealerTotal > 21) {
                cout << endl;
                cout << "TOTAL: " << dealerTotal << endl;
                cout << "The dealer went over 21. You Win!" << endl;
                return;
            }
    }
        cout << "TOTAL: " << dealerTotal << endl;
        cout << endl;
    }
    if (playerTotal > dealerTotal) {
        cout << "You Win!" << endl;
        return;
    }
    else if (playerTotal == dealerTotal) {
        cout << "Push" << endl;
        return;
    }
    else {
        cout << "You lose" << endl;
        return;
    }
}


