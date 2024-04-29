#ifndef __DEALER_H__
#define __DEALER_H__

#include <iostream>
#include "hand.h"

class Dealer: public Hand {
    private:
    public:
        void displayHand() override;
};

#endif