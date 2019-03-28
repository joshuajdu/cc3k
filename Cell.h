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
        Occupier occ = {false, nullptr, nullptr, nullptr};
        Posn pos;
    public:
        Cell(Posn p, cellType c);
        Cell(Posn p, cellType c, Player &pl);
        Cell(Posn p, cellType c, Enemy &e);
        Cell(Posn p, cellType c, Item &i);
        bool occupied();
        Occupier getOccupier();
        cellType type();
        Item item();
        void print();
        void addOccupant(Player &p);
        void addOccupant(Enemy &e);
        void addOccupant(Item &i);
        void transfer(Cell &c);
};

#endif
