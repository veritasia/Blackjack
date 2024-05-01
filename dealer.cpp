#include "dealer.h"

void Dealer::displayHand()
{
    std::cout << "----------------" << std::endl;
    std::cout << "Dealer's current hand\n";
    int i = 0;
    for (auto elem : currHand)
    {
        std::cout << elem;
        i++;
        if (i != currHand.size())
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << "Dealer's current total with dealer's cards:\n";
    std::cout << currTotal << std::endl;

    if (hasAce)
    {
        std::cout << "Dealer has an ace!\n";
        std::cout << "Dealer's current total with dealer's cards with ace as 1:\n";
        std::cout << currTotalwithAce << std::endl;
    }
}

void Dealer::hit() {
    // grab a card from the deck
    std::string chosenCard = blackjackDeck.removeCard();
    if (chosenCard == "")
    {
        throw std::invalid_argument("Dealer got an empty card in Hand::hit()");
    }

    // put it in your hand
    std::cout << "Dealer pulled a " << chosenCard << std::endl;
    currHand.push_back(chosenCard);
    countCards();
}