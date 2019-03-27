#include "Player.h"
#include <string>

using namespace std;


Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

int Player::get_hp(){
    return hp;
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
