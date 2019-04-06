#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

#include "Posn.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Potion.h"
#include "Treasure.h"
#include "Cell.h"
#include "Chamber.h"
#include "Floor.h"

class Game{

    public:

        bool check_direction(std::string direction);
        void start_game(string filename = "");
        Posn targetPosn(Posn p, std::string direction);
       // void start_game(Floor f);

    protected:

    private:

        Player player;

};

#endif
