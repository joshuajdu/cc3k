#include "Cell.h"

using namespace std;

Cell::Cell(Posn p, cellType c): pos{p}, cellT{c} {occType = "NA";}
Cell::Cell(Posn p, cellType c, string obj): pos{p}, cellT{c}, occType{obj} {}

bool Cell::occupied() {
    return (occType != "NA");
}

string Cell::occupiedType(){
    return occType;
}

cellType Cell::type(){
    return cellT;
}

Item Cell::item(){

}

void Cell::print(){
    switch (cellT) {
        case hWall:     cout << "-"; break;
        case vWall:     cout << "|"; break;
        case door:      cout << "+"; break;
        case passage:   cout << "#"; break;
        case empty:     cout << " "; break;
}

void Cell::transfer(Cell &c) {
    if (this.occupied() && !c->occupied()) {
        c->occType = this.occType;
        this.occType = "NA";
    }
}
