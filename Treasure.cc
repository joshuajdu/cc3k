#include <iostream>
#include <string>
#include "Treasure.h"

Treasure::Treasure(int x, int y, int goldVal): Item(x, y, "G"), goldVal{goldVal}{
    if (goldVal == 0) setName("B");
}

void Treasure::useItem(Player &p){
    int* gold = p.get_gold();
    if (p.get_race() == "Orc"){
	(*gold) = (*gold) + (int)goldVal*0.5;
    }
    else if (p.get_race() == "Dwarf"){
	(*gold) = (*gold) + goldVal*2;
    }
    else{
    	(*gold) = (*gold) + goldVal;
    }
}

void Treasure::print(){
    cout << "G";
}

bool Treasure::isTreasure(){ return true; }

BarrierSuit::BarrierSuit(int x, int y): Treasure(x, y, 0) {}

void BarrierSuit::useItem(Player &p){
    p.switch_barrier();
}

void BarrierSuit::print(){
    cout << "B";
}
