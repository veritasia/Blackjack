#include <iostream>
#include "deck.h"
#include <vector>
#include <cstdlib>
#include <stdexcept>

//used to reset the game, we are ading back all the cards into
//the deck
void Deck::resetDeck() {
    std::vector<std::string> newDeck = {"Ace of Spades", "2 of Spades", "3 of Spades", "4 of Spades", "5 of Spades", "6 of Spades",
                   "7 of Spades", "8 of Spades", "9 of Spades", "10 of Spades", "King of Spades", "Queen of Spades",
                   "Jack of Spades", "Ace of Hearts", "2 of Hearts", "3 of Hearts", "4 of Hearts", "5 of Hearts",
                   "6 of Hearts", "7 of Hearts", "8 of Hearts", "9 of Hearts", "10 of Hearts", "King of Hearts",
                   "Queen of Hearts", "Jack of Hearts", "Ace of Clubs", "2 of Clubs", "3 of Clubs", "4 of Clubs",
                   "5 of Clubs", "6 of Clubs", "7 of Clubs", "8 of Clubs", "9 of Clubs", "10 of Clubs", "King of Clubs",
                   "Queen of Clubs", "Jack of Clubs", "Ace of Diamonds", "1 of Diamonds", "2 of Diamonds", "3 of Diamonds",
                   "4 of Diamonds", "5 of Diamonds", "6 of Diamonds", "7 of Diamonds", "8 of Diamonds", "9 of Diamonds",
                   "10 of Diamonds", "King of Diamonds", "Queen of Diamonds", "Jack of Diamonds"};

    currentDeck = newDeck;

    //currentDeck.push_back("crying");
    return;
}

//displays everything in the current deck
//used for testing
void Deck::displayDeck() {
    int i = 0;
    for (auto elem : currentDeck)
    {
        std::cout << elem;
        i++;
        if (i != currentDeck.size()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

//remove a card from the current deck and return that card
std::string Deck::removeCard() {
    std::string chosenCard = "";

    if (!isEmpty()) {
        int pos = -1; //if -1 then none chosen

        if (currentDeck.size() != 1) {
        pos = rand() % (currentDeck.size()-1); //this position will be from 0-(size-1) randomly chosen
        }
        else {
            pos = 0;
        }

        if (pos == -1) {
            throw std::invalid_argument("received negative value for removeCard() pos");
        }

        chosenCard = currentDeck.at(pos);
        currentDeck.erase(currentDeck.begin() + pos);
    }

    return chosenCard;
}