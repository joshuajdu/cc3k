#include <iostream>
#include <string>
#include "Item.h"
#include "Posn.h"

using namespace std;

Item::Item(int x, int y, string name): p{Posn(x, y)}, name{name} {}

string Item::getName() {return name;}

Posn Item::getPosn() {return p;}

void Item::setName(string name) {this->name = name;}
