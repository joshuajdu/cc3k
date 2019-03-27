#include <iostream>
#include <string>
#include "Potions.h"

using namespace std;

Potions::Potions(string name): name{name} {}

RH::RH(): Potions("RH") {}

void RH::useItem(Player &p){
    
}
