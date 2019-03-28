#include "Cell.h"

using namespace std;

Cell::Cell(Posn p, cellType c): pos{p}, cellT{c} {}
Cell::Cell(Posn p, cellType c, Player &pl): pos{p}, cellT{c} {
    occ.occupied = true;
    occ.p = p1;
}

Cell::Cell(Posn p, cellType c, Enemy &e): pos{p}, cellT{c} {
    occ.occupied = true;
    occ.e = e;
}

Cell::Cell(Posn p, cellType c, Item &i): pos{p}, cellT{c} {
    occ.occupied = true;
    occ.i = i;
}

/// various overloaded constructors for each possibility

bool Cell::occupied() {
    return occ.occupied;
}

Occupier Cell::getOccupier(){
    return occ;
}

cellType Cell::type(){
    return cellT;
}

Item Cell::item(){
    if (occ.i) return occ.i;
}

void Cell::print(){
    switch (cellT) {
        case hWall:     cout << "-"; break;
        case vWall:     cout << "|"; break;
        case door:      cout << "+"; break;
        case passage:   cout << "#"; break;
        case empty:     cout << " "; break;
}

void Cell::addOccupant(Player &p) {occ.p = p; occ.occupied = true;}
void Cell::addOccupant(Enemy &e) {occ.e = e; occ.occupied = true;}
void Cell::addOccupant(Item &i) {occ.i = i; occ.occupied = true;}

void Cell::transfer(Cell &c) {
    if (this.occupied() && !c->occupied()) {
        c->addOccupant(occ.p);
        c->addOccupant(occ.i);
        c->addOccupant(occ.e);
        occ.occupied = false;
        occ.e = nullptr; occ.i = nullptr; occ.p = nullptr;
    }
}
