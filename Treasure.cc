#include <iostream>
#include <string>
#include "Treasure.h"

Treasure::Treasure(int x, int y, int goldVal): Item(x, y){
    this->goldVal = goldVal;
    if (goldVal == 1) setName("6");
    else if (goldVal == 2) setName("7");
    else if (goldVal == 4) setName("8");
    else if (goldVal == 6) setName("9");
    else if (goldVal == 0) setName("B");
}

void Treasure::useItem(Player &p){
    int* gold = p.get_gold();
    (*gold) = (*gold) + goldVal;
}

BarrierSuit::BarrierSuit(int x, int y): Treasure(x, y, 0) {}

void BarrierSuit::useItem(Player &p){
    p.switch_barrier();
}
