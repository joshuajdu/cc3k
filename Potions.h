#include "Items.h"
#include "Player.h"

class Potions: public Items{
    std::string name;

public:
    Potions(std::string name);
    virtual useItem(Player &p);
};

class RH: public Potions{
public:
    RH();
    useItem(Player &p);
};

class BA: public Potions{
public:
    BA();
    useItem(Player &p);
};

class BD: public Potions{
public:
    BD();
    useItem(Player &p);
};

class PH: public Potions{
public:
    PH();
    useItem(Player &p);
};

class WA: public Potions{
public:
    WA();
    useItem(Player &p);
};

class WD: public Potions{
public:
    WD();
    useItem(Player &p);
};
