#include <iostream>
#include "Player.h"
#include "Posn.h"
#include "Enemy.h"
#include "Item.h"
#include "Potion.h"
#include "Treasure.h"
#include "Cell.h"
#include "Chamber.h"

using namespace std;

void printPlayer(Player &a){
    cout << "HP: " <<  *a.get_hp() << endl;
    cout << "ATK: " << *a.get_atk() << endl;
    cout << "DEF: " << *a.get_def() << endl;
    cout << "Gold: " << *a.get_gold() << endl;
    cout << "BarrierSuit: " << a.get_barriersuit() << endl;    
}

void useItem(Player &a, Item &p){
    p.useItem(a);
}

int main()
{
    Player a;
    printPlayer(a);
    BA pot1 = BA(0,0);
    cout << pot1.foundItem() << endl;
    printPlayer(a);
    pot1.useItem(a);
    cout << pot1.foundItem() << endl;
    printPlayer(a);
    useItem(a, pot1);
    printPlayer(a);
    // Testing Treasures
    Treasure trea1 = Treasure(1,1,6);
    BarrierSuit suit = BarrierSuit(3,4);
    useItem(a, trea1);
    printPlayer(a);
    useItem(a, suit);
    printPlayer(a);
    Treasure trea2 = Treasure(4,5,2);
    useItem(a, trea2);
    printPlayer(a);
    return 0;
}
