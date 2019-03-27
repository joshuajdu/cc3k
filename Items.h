#ifndef ITEMS_H
#define ITEMS_H

#include "Posn.h"
#include "Player.h"

class Items{
    Posn p;

public: 
    Items(int x, int y);
    virtual void useItem(Player &p);
};

#endif
