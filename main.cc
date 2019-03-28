#include <iostream>
#include "Player.h"
#include "Potion.h"
#include "Item.h"
#include "Posn.h"
#include "Treasure.h"

using namespace std;

void printPlayer(Player *a){
    cout << "HP: " << *a->get_hp() << endl;
    cout << "ATK: " << *a->get_atk() << endl;
    cout << "DEF: " << *a->get_def() << endl;
}

int main(){
    Player a;
    printPlayer(&a);
    
    RH p1 = RH(5,6);
    BA p2 = BA(1,2);
    BD p3 = BD(1,0);
    PH p4 = PH(0,0);
    WA p5 = WA(1,1);
    WD p6 = WD(8,2);
}
