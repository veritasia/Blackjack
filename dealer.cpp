#include "dealer.h"

void Dealer::displayHand()
{
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