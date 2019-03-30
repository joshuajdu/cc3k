#include <iostream>
#include <string>
#include "Treasure.h"

Treasure::Treasure(int x, int y, int goldVal): Item(x, y, "G"), goldVal{goldVal}{
    if (goldVal == 0) setName("B");
}

void Treasure::useItem(Player &p){
    int* gold = p.get_gold();
    (*gold) = (*gold) + goldVal;
}

BarrierSuit::BarrierSuit(int x, int y): Treasure(x, y, 0) {}

void BarrierSuit::useItem(Player &p){
    p.switch_barrier();
}
