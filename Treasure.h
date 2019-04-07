#ifndef TREASURE_H
#define TREASURE_H
#include "Item.h"
#include "Player.h"

class Treasure: public Item{
    int goldVal;
public:
    Treasure(int x, int y, int goldVal);
    virtual void useItem(Player &p);
    virtual void print();
    bool isTreasure();
    virtual string actionPrint();
};

class BarrierSuit: public Treasure{
public:
    BarrierSuit(int x, int y);
    void print();
    void useItem(Player &p);
    string actionPrint();
};
#endif
