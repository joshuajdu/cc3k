#include "Player.h"
#include <string>

using namespace std;

Player::Player(int hp = 140, int attack = 20, int defence = 20, string race = "Human"): 
	       hp{hp}, attack{attack}, defence{defence}, race{race}, barrier_suit{false}, compass{false} {}

Player::~Player()
{
    //dtor
}

int& Player::get_hp(){
    return &hp;
}

void Player::Move(string direction){
    if (direction == "no"){

    }
    else if (direction == "so"){

    }
    else if (direction == "ea"){

    }
    else if (direction == "we"){

    }
    else if (direction == "ne"){

    }
    else if (direction == "nw"){

    }
    else if (direction == "se"){

    }
    else if (direction == "sw"){

    }
    else{
        //error
    }
}
