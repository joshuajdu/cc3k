#include "Cell.h"

using namespace std;

/// various overloaded constructors for each possibility
Cell::Cell(Posn p, cellType c): cellT{c}, pos{p} {}

Cell::Cell(Posn p, cellType c, Player *pl): cellT{c}, pos{p} {
    occ.occupied = true;
    occ.p = pl;
}

Cell::Cell(Posn p, cellType c, Enemy *e): cellT{c}, pos{p} {
    occ.occupied = true;
    occ.e = e;
}

Cell::Cell(Posn p, cellType c, Item *i): cellT{c}, pos{p} {
    occ.occupied = true;
    occ.i = i;
}

/// information-based functions
Posn Cell::getPosn() {
    return pos;
}

bool Cell::occupied() {
    return occ.occupied;
}

Occupier Cell::getOccupier(){
    return occ;
}

cellType Cell::type(){
    return cellT;
}

Item* Cell::item(){
    return occ.i;
}

void Cell::print(){
    switch (cellT) {
// ADD IN CASE WHERE IT'S A TILE BUT OCCUPIED
        case hWall:     cout << "-"; break;
        case vWall:     cout << "|"; break;
        case door:      cout << "+"; break;
        case passage:   cout << "#"; break;
	case tile:      cout << "."; break;
        case empty:     cout << " "; break;
    }
}

/// object interaction
void Cell::addOccupant(Player *p) {occ.p = p; occ.occupied = true;}

///### [[ add in win condition if Cell is staircase ]] ###
void Cell::addOccupant(Enemy *e) {occ.e = e; occ.occupied = true;}
void Cell::addOccupant(Item *i) {occ.i = i; occ.occupied = true;}

void Cell::transfer(Cell &c) {
    if (this->occupied() && !c.occupied()) {
        c.addOccupant(occ.p);
        c.addOccupant(occ.i);
        c.addOccupant(occ.e);
        occ.occupied = false;
        occ.e = nullptr; occ.i = nullptr; occ.p = nullptr;
    }
}
