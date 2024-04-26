//will hold all the things needed for a blackjack hand
#ifndef __HAND_H__
#define __HAND_H__

#include <iostream>
#include <vector>
#include "deck.h"

class Hand {
    private:
        std::vector<std::string> currHand;
        int currTotal = 0;
        int currTotalwithAce = 0;
        bool hasAce = false;
        Deck blackjackDeck;

    public:
        void countCards();
        int getCurrTotal();
        void hit();
        int identifyCard(std::string);
        void displayHand();
        void restartBlackjackDeck();
        void displayBlackjackDeck();
};

#endif