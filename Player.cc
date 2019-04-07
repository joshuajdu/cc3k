#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Posn.h"
#include "Enemy.h"

using namespace std;

Player::Player(int hp, int atk, int def, string race, int x, int y):
	       maxhp{hp}, hp{hp}, baseatk{atk}, atk{atk}, basedef{def}, def{def},
               race{race}, gold{0}, p{Posn(x,y)}, barrier_suit{false}, compass{false} {}

string Player::get_race(){
    return race;
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

bool Player::get_barriersuit(){
    return barrier_suit;
}

void Player::switch_barrier(){
    barrier_suit = true;
}

Posn Player::getPosn(){
    return p;
}

void Player::setPosn(Posn p){
    this->p = p;
}

void Player::Move(string direction){
    if (direction == "no"){
        p.y++;
    }
    else if (direction == "so"){
        p.y--;
    }
    else if (direction == "ea"){
        p.x++;
    }
    else if (direction == "we"){
        p.x--;
    }
    else if (direction == "ne"){
        p.x++;
        p.y++;
    }
    else if (direction == "nw"){
        p.y++;
        p.x--;
    }
    else if (direction == "se"){
        p.x++;
        p.y--;
    }
    else if (direction == "sw"){
        p.x--;
        p.y--;
    }
    else{
        //error
    }
}

void Player::Position(){
    cout << "x: " << p.x << " y: " << p.y << endl;
}


string Player::Damage(shared_ptr<Enemy> e){
    //ceiling ((100/100+ def(defender)) * atk (attacker))

    double dmg = 100.0/(100+def) * (*e->get_atk());
    dmg = ceil(dmg);

    int x = (int)dmg;

    hp -= x;
    if (hp < 0){
        hp = 0;
    }

    return "\n        " + e->get_race() + " deals " + std::to_string(x) + " damage to PC.";
}

Dwarf::Dwarf(): Player(100, 20, 30, "Dwarf") {}

Elf::Elf(): Player(140,20,10,"Elf") {}

Orc::Orc(): Player(180,30,25,"Orc"){}


