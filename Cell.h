#ifndef CELL_H
#define CELL_H

#include "Item.h"
#include "Posn.h"

enum cellType { hWall, vWall, door, passage, empty };

struct Occupier {
    bool occupied;
    Player *p;
    Enemy *e;
    Item *i;
};

class Cell {
    private:
        cellType cellT;
        occupant occ;
        Posn pos;
    public:
        Cell(Posn p, cellType c);
        Cell(Posn p, cellType c, string obj);
        bool occupied();
        occupant occupiedType();
        cellType type();
        Item item();
        void print();
        void transfer(Cell &c);
};

#endif
