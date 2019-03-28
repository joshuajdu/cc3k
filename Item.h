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
    virtual void useItem(Player &p) = 0; 
};

#endif
