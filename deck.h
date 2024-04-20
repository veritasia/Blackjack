//setting up what's in the deck
#ifndef __DECK_H__
#define __DECK_H__

#include <iostream>
#include <vector>

class Deck
{
private:
    std::vector<std::string> currentDeck;

public:
    Deck() : currentDeck() {}
    void resetDeck();
    void displayDeck();
    std::string removeCard();
    bool isEmpty() { return currentDeck.empty(); }
};

#endif