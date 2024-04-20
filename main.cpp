#include <iostream>
#include "gametime.h"

int main() {
    //startBlackjack();
    Deck currDeck;
    currDeck.displayDeck();
    currDeck.resetDeck();
    currDeck.displayDeck();

    return 0;
}