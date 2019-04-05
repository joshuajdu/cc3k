#ifndef CELL_H
#define CELL_H

#include <memory>

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
    shared_ptr<Enemy> e;
    shared_ptr<Item> i;
};

class Cell {
    cellType cellT;
    Occupier occ = {false, occType::None_, nullptr, nullptr, nullptr};
    Posn pos;
    bool moved = false;
    bool stairs = false;
    static bool compass;

public:
    /// CONSTRUCTORS / DATA MANIPULATION
    Cell(Posn p, cellType c);
    Cell(Posn p, cellType c, Player *pl);
    Cell(Posn p, cellType c, shared_ptr<Enemy> e);
    Cell(Posn p, cellType c, shared_ptr<Item> i);
    void setStairs();

    /// INFORMATION-BASED FUNCTIONS
    Posn getPosn();
    bool isStairs();
    bool occupied();
    occType getOccupierType();
    cellType type();
    shared_ptr<Item> getItem();
    shared_ptr<Enemy> getEnemy();
    bool playerCanMove();
    bool enemyCanMove();
    void print();

    /// INTERACTION WITH OTHER OBJECTS
    void addOccupant(Player *p);
    void addOccupant(shared_ptr<Enemy> e);
    void addOccupant(shared_ptr<Item> i);
    void transfer(Cell &c);
    void compassFound();
    void resetMove();
};
#endif
