#ifndef ITEMS_H
#define ITEMS_H

#include "Posn.h"
#include "Player.h"

class Items{
    Posn p;

public: 
    Items(int x=0, int y=0);
    virtual void useItem(Player &p) = 0; 
};

#endif
