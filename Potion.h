#ifndef POTION_H
#define POTION_H
#include "Item.h"
#include "Player.h"

class Potion: public Item{

public:
    Potion(int x, int y, std::string name);
    virtual void useItem(Player &p) = 0;
};

class RH: public Potion{
public:
    RH(int x, int y);
    void useItem(Player &p);
};

class BA: public Potion{
public:
    BA(int x, int y);
    void useItem(Player &p);
};

class BD: public Potion{
public:
    BD(int x, int y);
    void useItem(Player &p);
};

class PH: public Potion{
public:
    PH(int x, int y);
    void useItem(Player &p);
};

class WA: public Potion{
public:
    WA(int x, int y);
    void useItem(Player &p);
};

class WD: public Potion{
public:
    WD(int x, int y);
    void useItem(Player &p);
};
#endif
