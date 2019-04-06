#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Potion.h"
#include "Treasure.h"
#include "Cell.h"
#include "Chamber.h"

class Game{

    public:

        bool check_direction(std::string direction);
        void start_game();
        Posn targetPosn(Posn p, string direction);
       // void start_game(Floor f);

    protected:

    private:

        Player player;

};

#endif
