#include "Items.h"
#include "Player.h"

class Potions: public Items{
    std::string name;

public:
    Potions(std::string name);
    virtual void useItem(Player &p) = 0;
};

class RH: public Potions{
public:
    RH();
    void useItem(Player &p);
};

class BA: public Potions{
public:
    BA();
    void useItem(Player &p);
};

class BD: public Potions{
public:
    BD();
    void useItem(Player &p);
};

class PH: public Potions{
public:
    PH();
    void useItem(Player &p);
};

class WA: public Potions{
public:
    WA();
    void useItem(Player &p);
};

class WD: public Potions{
public:
    WD();
    void useItem(Player &p);
};
