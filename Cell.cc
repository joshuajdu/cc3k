#include "Cell.h"

using namespace std;

/// various overloaded constructors for each possibility

Cell::Cell(Posn p, cellType c): cellT{c}, pos{p} {}

Cell::Cell(Posn p, cellType c, Player *pl): cellT{c}, pos{p} {
    occ.occupied = true;
    occ.p = pl;
}

Cell::Cell(Posn p, cellType c, shared_ptr<Enemy> e): cellT{c}, pos{p} {
    occ.occupied = true;
    occ.e = e;
}

Cell::Cell(Posn p, cellType c, shared_ptr<Item> i): cellT{c}, pos{p}{
    occ.occupied = true;
    occ.i = i;
}

void Cell::setStairs() {stairs = true; occ.occupied = true;}

/// information-based functions
Posn Cell::getPosn() {return pos;}

bool Cell::isStairs() {return stairs;}

bool Cell::occupied() {return occ.occupied;}

occType Cell::getOccupierType() {return occ.occupierType;}

cellType Cell::type() {return cellT;}

shared_ptr<Item> Cell::getItem() {return occ.i;}

shared_ptr<Enemy> Cell::getEnemy() {return occ.e;}

bool Cell::playerCanMove() {
    if (!occupied() || occ.occupierType == occType::Gold_ || stairs) {
        if (cellT >= 2 && cellT <= 4) return true;
    }
    return false;
}

bool Cell::enemyCanMove() {
    return (!occupied() && cellT == cellType::tile);
}

void Cell::print(){
    if (this->occupied()) {
        switch (occ.occupierType) {
        case occType::Player_: cout << "@"; break;
        case occType::Enemy_: occ.e->print(); break;
        case occType::Item_: occ.i->print(); break;
        case occType::Gold_: occ.i->print(); break;
        case occType::None_:
            if (stairs && compass) cout << "\\";
            else cout << ".";
        }
    } else {
        switch (cellT) {
        case cellType::hWall:     cout << "-"; break;
        case cellType::vWall:     cout << "|"; break;
        case cellType::door:      cout << "+"; break;
        case cellType::passage:   cout << "#"; break;
        case cellType::tile:      cout << "."; break;
        case cellType::empty:     cout << " "; break;
        }
    }
}

/// object interaction
void Cell::addOccupant(Player *p) {
    occ.p = p;
    occ.occupied = true;
    occ.occupierType = occType::Player_;
}

///### [[ add in win condition if Cell is staircase ]] ###
void Cell::addOccupant(shared_ptr<Enemy> e) {
    occ.e = e;
    occ.occupied = true;
    occ.occupierType = occType::Enemy_;
}

void Cell::addOccupant(shared_ptr<Item> i) {
    occ.i = i;
    occ.occupied = true;
    if (i->isTreasure()) occ.occupierType = occType::Gold_;
    else occ.occupierType = occType::Item_;
}

void Cell::transfer(Cell *c) {
    if (this->occupied() && !c->occupied()) {
	switch (getOccupierType()) {
	    case occType::Player_: c->addOccupant(occ.p); break;
            case occType::Gold_: c->addOccupant(occ.i); break;
            case occType::Item_: c->addOccupant(occ.i); break;
            case occType::Enemy_: c->addOccupant(occ.e); break;
	}
        occ.occupied = false;
        occ.e = nullptr; occ.i = nullptr; occ.p = nullptr;
    }
    moved = true;
}

void Cell::removeOccupant(){
    occ.occupied = false;
    occ.e = nullptr; occ.i = nullptr; occ.p = nullptr;
}

void Cell::resetMove() { moved = false; }

void Cell::compassFound() {compass = true;}
bool Cell::compass = false;
