#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <string>

#include "Cell.h"
#include "Enemy.h"
#include "Item.h"
#include "Potion.h"
#include "Treasure.h"
#include "Posn.h"

class Floor{
    std::vector< vector<Cell> > cells;
    std::vector<Enemy*> enemies;

public:
    void addInput(std::string line, int x);
    void print();
    vector< vector<Cell> > getCell() const;
    vector<Enemy*>& getEnemies();
};
#endif
