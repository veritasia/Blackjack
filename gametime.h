//this is straight up where all the game should be
#include <iostream>
#include <string>
#include "deck.h"
#include "hand.h"

int ynInputValidation(std::string input)
{
    if (input == "y")
    {
        return 1; // for confirming
    }
    else if (input == "n")
    {
        return 0; // for saying no
    }
    else
    {
        return -1; // for anything else
    }
}

void startBlackjack() {
    int choice;

    //loop to keep doing the intro
    do
    {
        std::cout << "Would you like to play a round of Blackjack? (y/n)" << std::endl;

        std::string response;
        std::cin >> response;

        choice = ynInputValidation(response);

        if (choice == 1) {
            std::cout << "Let's play then!";
        }
        else if (choice == 0) {
            std::cout << "Next time then!" << std::endl;
            return;
        }
        else{
            std::cout << "Not a valid input. Try again.";
        }
        std::cout << std::endl;
    } while (choice != 0 && choice != 1);

    Deck currDeck;
    currDeck.resetDeck();

    std::cout << "Let us begin!" << std::endl;

    currDeck.displayDeck();
}
