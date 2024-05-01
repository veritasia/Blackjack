//this is straight up where all the game should be
#include <iostream>
#include <string>
#include "deck.h"
#include "hand.h"
#include "dealer.h"

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

int dealerStand(Dealer handy) {
    int dealerCount = handy.getCurrTotal();

    if ((dealerCount == 21) || (dealerCount == 20) || (dealerCount == 19) || (dealerCount == 18) || (dealerCount == 17))
    {
        return 1;
    }
    else if (handy.getCurrTotal() > 21) {
        return -1;
    }
    else {
        return 0;
    }
}

int winCondition(Hand handy, Dealer dealer)
{
    if (handy.getCurrTotal() == 21)
    {
        return 1;//win condition
    }
    else if ((handy.getCurrTotal() < 21) && (handy.getCurrTotal() > dealer.getCurrTotal())) {
        return 3; //another win condition
    }
    else if ((handy.getCurrTotal() < 21) && (dealer.getCurrTotal() > 21)) {
        return 3;
    }
    else if ((handy.getCurrTotal() > 21) && (dealer.getCurrTotal() > 21 && (dealer.getCurrTotal() == handy.getCurrTotal()))) {
        return 2; //tie condition
    }
    else if (handy.getCurrTotal() == (dealer.getCurrTotal())) {
        return 2; // another tie condition;
    }
    else if (handy.getCurrTotal() > 21)
    {
        return -1; //lose condition
    }
    else
    {
        return 0; //continue condition
    }
}

void startBlackjack() {
    int choice;
    std::string response;

    //loop to keep doing the intro
    do
    {
        std::cout << "Would you like to play a round of Blackjack? (y/n)" << std::endl;
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

    Hand handy;
    Dealer dealer;
    handy.restartBlackjackDeck();
    dealer.restartBlackjackDeck();
    // dealer.restartBlackjackDeck();

    std::cout << "Let us begin!" << std::endl;
    
    handy.hit();
    handy.hit();
    handy.displayHand();
    std::cout << std::endl;

    dealer.hit();
    dealer.hit();
    dealer.displayHand();
    std::cout << std::endl;

    while ((winCondition(handy, dealer) == 0) || (winCondition(handy, dealer) == 3)) {

        handy.displayHand();
        std::cout << "do you want to hit? (y/n)\n";
        std::cin >> response;

        choice = ynInputValidation(response);

        if (choice == 1) {
            handy.hit();
            std::cout << std::endl;
        }
        else if (choice == 0) {
            std::cout << "you stayed your hand\n";
            break;
        }
        else {
            std::cout << "not a valid response, try again. \n";
        }
    }

    //only have dealer pull if the player's hand has less than 21 points
    if ((handy.getCurrTotal() < 21)) {
        while (dealerStand(dealer) == 0) {
            dealer.hit();
            std::cout << std::endl;
        }
    }

    dealer.displayHand();

    std::cout << "Let's see if you've won something\n\n";

    if (winCondition(handy, dealer) == -1) {
        std::cout << "You busted\n";
    }
    else if (winCondition(handy, dealer) == 1) {
        std::cout << "You got exactly 21!\n";
    }
    else if (winCondition(handy, dealer) == 3) {
        std::cout << "you won!\n";
    }
    else if (winCondition(handy, dealer) == 2) {
        std::cout << "You and the dealer tied!\n";
    }
    else {
        std::cout << "Something may have gone wrong\n";
    }

    handy.displayHand();

    //handy.displayBlackjackDeck();
}
