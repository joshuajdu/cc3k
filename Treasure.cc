#include <iostream>
#include <string>
#include "Treasure.h"

using namespace std;

Treasure::Treasure(int x, int y, int goldVal): Item(x, y, "G"), goldVal{goldVal}{
    if (goldVal == 0) setName("B");
}

void Treasure::useItem(Player &p){
    int* gold = p.get_gold();
    (*gold) = (*gold) + goldVal;
}

void Treasure::print(){
    cout << "G";
}

bool Treasure::isTreasure(){ return true; }

string Treasure::actionPrint(){
    switch (goldVal) {
    case 1: return "a normal pile of gold"; break;
    case 2: return "a small hoard of gold"; break;
    case 4: return "a merchant hoard of gold"; break;
    case 6: return "a dragon hoard of gold"; break;
    }
    return "";
}

BarrierSuit::BarrierSuit(int x, int y): Treasure(x, y, 0) {}

void BarrierSuit::useItem(Player &p){
    p.switch_barrier();
}

void BarrierSuit::print(){
    cout << "B";
}

string BarrierSuit::actionPrint(){
    return "a Barrier Suit";
