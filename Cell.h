#ifndef CELL_H
#define CELL_H

#include "Posn.h"
#include "Item.h"
#include "Player.h"
#include "Enemy.h"

enum cellType { hWall, vWall, door, passage, tile, empty };
enum occType { Player_, Enemy_, Item_, Gold_, None_ };

/// general purpose storage for relevant game pointers

struct Occupier {
    bool occupied;
    occType occupierType;
    Player *p;
    Enemy *e;
    Item *i;
};

class Cell {
    private:
    cellType cellT;
    Occupier occ = {false, occType::None, nullptr, nullptr, nullptr};
    Posn pos;
    bool stairs = false;
    static bool compassFound;

public:
    /// CONSTRUCTORS / DATA MANIPULATION
    Cell(Posn p, cellType c);
    Cell(Posn p, cellType c, Player &pl);
    Cell(Posn p, cellType c, Enemy &e);
    Cell(Posn p, cellType c, Item &i);

    void setStairs();

    /// INFORMATION-BASED FUNCTIONS

    Posn getPosn();
    bool isStairs();
    bool occupied();
    occType getOccupierType();

    cellType type();

    Item* getItem();
    Enemy* getEnemy();

    bool playerCanMove();
    bool enemyCanMove();

    void print();

    /// INTERACTION WITH OTHER OBJECTS

    void addOccupant(Player &p);
    void addOccupant(Enemy &e);
    void addOccupant(Item &i);
    void transfer(Cell &c);
    void compassFound();
};

#endif
