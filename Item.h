#ifndef ITEM_H
#define ITEM_H

#include "Posn.h"
#include "Player.h"

class Item{
    Posn p;
    std::string name;

public: 
    Item(int x=0, int y=0, string name = "");
    std::string getName();
    Posn getPosn();
    void setName(std::string name);
    virtual void useItem(Player &p) = 0;
    virtual void print() = 0;
    virtual bool isTreasure() = 0;
    virtual std::string actionPrint() = 0;
};

#endif