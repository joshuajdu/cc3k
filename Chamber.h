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
};

#endif
