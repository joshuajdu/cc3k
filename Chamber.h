#ifndef CHAMBER_H
#define CHAMBER_H

#include <vector>
#include "Posn.h"

struct Chamber{
    int numCells;
    std::vector<Posn> cells;

    Chamber();
    void addCell(int x, int y);
    void addCell(Posn p);
    Posn randomCell();
};

void generateDefaultChambers(Chamber &a, Chamber &b, Chamber &c, Chamber &d, Chamber &e);

#endif
