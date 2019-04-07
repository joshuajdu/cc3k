#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Enemy.h"
#include "Player.h"

using namespace std;

Enemy::Enemy(int hp , int atk, int def, string race, int x, int y):
            hp{hp},atk{atk},def{def},race{race}, p{Posn(x,y)}{}

string Enemy::get_race(){
    return race;
}

Posn Enemy::getPosn(){
    return p;
}

bool Enemy::hasCompass(){
    return compass;
}

void Enemy::gainCompass() { compass = true; }

int *Enemy::get_hp(){
    return &hp;
}
int *Enemy::get_atk(){
    return &atk;
}

bool Enemy::isAggressive(){
    return true;
}

string Enemy::Damage(Player &p){
    //ceiling ((100/100+ def(defender)) * atk (attacker))
    ChangeAggro();
    double dmg = 100.0/(100+def) * (*p.get_atk());
    dmg = ceil(dmg);

    int x = (int)dmg;

    hp -= x;
    if (hp < 0){
        hp = 0;
    }

    return "PC deals " + to_string(x) + " damage to "
		       + race + " (" + to_string(hp) + " HP).";
}

void Enemy::ChangeAggro() {}

bool Enemy::playerInRange(Player &p){


    return true;
}

Werewolf::Werewolf(): Enemy(120,30,5,"Werewolf") {}

void Werewolf::print() { cout << "W"; }

Vampire::Vampire() : Enemy(50,25,25,"Vampire") {}

void Vampire::print() { cout << "V"; }

Goblin::Goblin() : Enemy(70,5,10,"Goblin") {}

void Goblin::print() { cout << "N"; }

Troll::Troll() : Enemy(120,25,15,"Troll"){}

void Troll::print() { cout << "T"; }

Phoenix::Phoenix() : Enemy(50,35,20,"Phoenix"){}

void Phoenix::print() { cout << "X"; }

Merchant::Merchant() : Enemy(30,70,5,"Merchant"){}

void Merchant::print() { cout << "M"; }

bool Merchant::aggressive = false;

bool Merchant::isAggressive(){
    return aggressive;
}

void Merchant::ChangeAggro(){
    aggressive = true;
}

Dragon::Dragon() : Enemy(150,20,20,"Dragon"){}

void Dragon::print() { cout << "D"; }
