#include "Item.h"
#include "Player.h"

class Potion: public Item{
    std::string name;

public:
    Potion(std::string name);
    virtual void useItem(Player &p) = 0;
};

class RH: public Potion{
public:
    RH();
    void useItem(Player &p);
};

class BA: public Potion{
public:
    BA();
    void useItem(Player &p);
};

class BD: public Potion{
public:
    BD();
    void useItem(Player &p);
};

class PH: public Potion{
public:
    PH();
    void useItem(Player &p);
};

class WA: public Potion{
public:
    WA();
    void useItem(Player &p);
};

class WD: public Potion{
public:
    WD();
    void useItem(Player &p);
};
