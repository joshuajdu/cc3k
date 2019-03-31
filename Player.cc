#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Posn.h"
#include "Enemy.h"

using namespace std;

Player::Player(int hp, int atk, int def, string race):
	       maxhp{hp}, hp{hp}, baseatk{atk}, atk{atk}, basedef{def}, def{def},
               race{race}, barrier_suit{false}, compass{false} {}

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

void Player::switch_barrier(){
    barrier_suit = true;
}

void Player::Move(string direction){

    if (direction == "we") p.x--;
    else {
        switch (direction[0]) {
        case 'n': p.y++; break;
        case 's': p.y--; break;
        case 'e': p.x++; break;
        }
        switch (direction[1]) {
        case 'e': p.x++; break;
        case 'w': p.x--; break;
        }
    }
}

void Player::Position(){
    cout << "x: " << p.x << " y: " << p.y << endl;
}


void Player::Damage(Enemy &e){
    //ceiling ((100/100+ def(defender)) * atk (attacker))

    double dmg = 100.0/(100+def) * (*e.get_atk());
    dmg = ceil(dmg);

    int x = (int)dmg;

    hp -= x;
    if (hp < 0){
        hp = 0;
    }

    cout << "Attack: " << (*e.get_atk()) << " Defence: " << def << endl;
    cout << "Damage done:" << dmg << endl;
}




Dwarf::Dwarf(): Player(100, 20, 30, "Dwarf") {}

Elf::Elf(): Player(140,20,10,"Elf") {}

Orc::Orc(): Player(180,30,25,"Orc"){}


