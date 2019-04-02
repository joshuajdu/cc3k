#include <iostream>
#include "Player.h"
#include "Posn.h"
#include "Enemy.h"
#include "Item.h"
#include "Potion.h"
#include "Treasure.h"
#include "Cell.h"
#include "Chamber.h"
#include "Floor.h"

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

//Global Constant Chambers used for Generation Purposes
Chamber a, b, c, d, e;

int main(){
    Player player;
    BA pot1 = BA(0,0);
    generateDefaultChambers(a, b, c, d, e);
    
    return 0;
}
