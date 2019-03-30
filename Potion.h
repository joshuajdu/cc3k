#ifndef POTION_H
#define POTION_H
#include "Item.h"
#include "Player.h"

class Potion: public Item{

public:
    Potion(int x, int y, std::string name);
    virtual void useItem(Player &p) = 0;
    virtual bool foundItem() = 0;
};

class RH: public Potion{
    static bool found;
public:
    RH(int x, int y);
    void useItem(Player &p);
    bool foundItem();
};

class BA: public Potion{
    static bool found;
public:
    BA(int x, int y);
    void useItem(Player &p);
    bool foundItem();
};

class BD: public Potion{
    static bool found;
public:
    BD(int x, int y);
    void useItem(Player &p);
    bool foundItem();
};

class PH: public Potion{
    static bool found;
public:
    PH(int x, int y);
    void useItem(Player &p);
    bool foundItem();
};

class WA: public Potion{
    static bool found;
public:
    WA(int x, int y);
    void useItem(Player &p);
    bool foundItem();
};

class WD: public Potion{
    static bool found;
public:
    WD(int x, int y);
    void useItem(Player &p);
    bool foundItem();
};
#endif
