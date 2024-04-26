#include <iostream>
#include "gametime.h"

int main() {
    srand((unsigned)time(NULL)); //providing a random seed
    // Hand handy;
    // handy.restartBlackjackDeck();
    // handy.hit();
    // std::cout << handy.identifyCard("Jack of Hearts") << std::endl;
    // handy.hit();
    // handy.countCards();
    // handy.displayHand();
    startBlackjack();
    // Deck currDeck;
    // currDeck.displayDeck();
    // currDeck.resetDeck();
    // currDeck.displayDeck();

    // while (!currDeck.isEmpty()) {
    //     std::cout << currDeck.removeCard() << std::endl;
    //     //currDeck.displayDeck();
    // }

    return 0;
}