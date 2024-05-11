//deals with what the blackjack hand needs
#include <iostream>
#include <vector>
#include <string>
#include "hand.h"
#include "deck.h"

//this is to restart the whole deck and game just in case
void Hand::restartBlackjackDeck() {
    blackjackDeck.resetDeck();
}

int Hand::getCurrTotal() {
    return currTotal;
}

void Hand::displayBlackjackDeck() {
    blackjackDeck.displayDeck();
}

//count the card values in the players hand
void Hand::countCards() {

    for (int i = currHand.size()-1; i < currHand.size(); i++)
    {
        currTotal += identifyCard((currHand.at(i)));
    }

    //std::cout << "output currtotal in countCards " << currTotal << std::endl;
}

//gotta get whatever is in your current Deck
void Hand::hit() {
    //grab a card from the deck
    std::string chosenCard = blackjackDeck.removeCard();
    if (chosenCard == "")
    {
        throw std::invalid_argument("you got an empty card in Hand::hit()");
    }

    //put it in your hand
    std::cout << "You pulled a " << chosenCard << std::endl;
    currHand.push_back(chosenCard);
    countCards();
}

//identify what card and the number you get
int Hand::identifyCard(std::string card) {

    int num = -1;

    //crying, there is such a better way to make this code
    if (card.find("2") != std::string::npos) {
        num = 2;
    }
    else if (card.find("3") != std::string::npos)
    {
        num = 3;
    }
    else if (card.find("4") != std::string::npos)
    {
        num = 4;
    }
    else if (card.find("5") != std::string::npos)
    {
        num = 5;
    }
    else if (card.find("6") != std::string::npos)
    {
        num = 6;
    }
    else if (card.find("7") != std::string::npos)
    {
        num = 7;
    }
    else if (card.find("8") != std::string::npos)
    {
        num = 8;
    }
    else if (card.find("9") != std::string::npos)
    {
        num = 9;
    }
    else if (card.find("10") != std::string::npos)
    {
        num = 10;
    }
    else if (card.find("K") != std::string::npos || card.find("Q") != std::string::npos || card.find("J") != std::string::npos)
    {
        num = 10;
    }
    else if (card.find("A", 0, 1) != std::string::npos)
    {
        num = 11;
        hasAce = true;
        // i need to deal with where there are two aces
    }

    return num;
}

//gotta know what is in your hand
void Hand::displayHand() {
    std::cout << "----------------" << std::endl;
    std::cout << "Your current hand\n";
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

    std::cout << "Your current total with your cards:\n";
    std::cout << currTotal << std::endl;

    if (hasAce) {
        std::cout << "You have an ace!\n";
        std::cout << "Your current total with your cards with ace as 1:\n";
        std::cout << currTotalwithAce << std::endl;
    }
}

void Hand::clearHand() {
    currHand.clear();
    currTotal = 0;
    currTotalwithAce = 0;
    hasAce = false;
}