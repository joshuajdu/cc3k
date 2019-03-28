#ifndef TREASURE_H
#define TREASURE_H
#include "Item.h"
#include "Player.h"

class Treasure: public Item{
    int goldVal;
Public:
    virtual void useItem(Player &p);
};

class BarrierSuit: public Treasure{
Public:
    void useItem(Player &p);
};
#endif
