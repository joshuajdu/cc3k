#include "Player.h"
#include <string>

using namespace std;

Player::Player(int hp = 140, int atk = 20, int def = 20, string race = "Human"): 
	       maxhp{hp}, hp{hp}, baseatk{atk}, atk{atk}, basedef{def}, def{def}, 
               race{race}, barrier_suit{false}, compass{false} {}

Player::~Player()
{
    //dtor
}

int Player::get_maxhp(){
    return maxhp;
}

int* Player::get_hp(){
    return &hp;
}

int Player::get_baseatk(){
    return baseatk;
}

int* Player::get_atk(){
    return &atk;
}

int Player::get_basedef(){
    return basedef;
}

int* Player::get_def(){
    return &def;
}

int* Player::get_gold(){
    return &gold;
}

void Player::switch_barrier(){
    barrier_suit = true;
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
