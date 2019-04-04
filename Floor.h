#ifndef FLOOR_H
#define FLOOR_H

#include <vector>
#include <string>
#include <memory>

#include "Cell.h"
#include "Enemy.h"
#include "Item.h"
#include "Potion.h"
#include "Treasure.h"
#include "Posn.h"
#include "Chamber.h"

enum enemyRates {
    W = 3,  // Werewolf         (4/18, 0-3)
    V = 6,  // Vampire          (3/18, 4-6)
    N = 11, // Goblin           (5/18, 7-11)
    M = 13, // Merchant         (2/18, 12-13)
    X = 15, // Phoenix          (2/18, 14-15)
    T = 17, // Troll            (2/18, 16-17)
    enemyTotal = 18
};

enum goldRates {
    G = 4,   // Gold            (5/8, 0-4)
    G_D = 5, // Dragon Hoard    (1/8, 5-5)
    G_S = 7, // Small Hoard     (2/8, 6-7)
    goldTotal = 8
};

class Floor{
    std::vector< vector<Cell> > cells;
    std::vector< shared_ptr<Enemy> > enemies;
    Chamber a,b,c,d,e;

public:
    void generateFloor();
    void addInput(std::string line, int x);
    Cell* findCell(Posn p);
    void printDisplay();
    void spawn();
};

#endif
