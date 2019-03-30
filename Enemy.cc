#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Enemy.h"
#include "Player.h"

using namespace std;

Enemy::Enemy(int hp , int atk, int def, string race):
            hp{hp},atk{atk},def{def},race{race}{}

string Enemy::get_race(){
    return race;
}

int *Enemy::get_hp(){
    return &hp;
}
int *Enemy::get_atk(){
    return &atk;
}

void Enemy::Damage(Player &p){
    //ceiling ((100/100+ def(defender)) * atk (attacker))

    double dmg = 100.0/(100+def) * (*p.get_atk());
    dmg = ceil(dmg);

    int x = (int)dmg;

    hp -= x;
    if (hp < 0){
        hp = 0;
    }

    cout << "Attack: " << (*p.get_atk()) << " Defence: " << def << endl;
    cout << "Damage done:" << dmg << endl;

}

bool Enemy::playerInRange(Player &p){


    return true;
}

Werewolf::Werewolf(): Enemy(120,30,5,"Werewolf") {}

Vampire::Vampire() : Enemy(50,25,25,"Vampire") {}

Goblin::Goblin() : Enemy(70,5,10,"Goblin") {}

Troll::Troll() : Enemy(120,25,15,"Troll"){}

Phoenix::Phoenix() : Enemy(50,35,20,"Phoenix"){}

Merchant::Merchant() : Enemy(30,70,5,"Merchant"){}

bool Merchant::aggressive = false;

void Merchant::ChangeAggro(){
    aggressive = true;
}

Dragon::Dragon() : Enemy(150,20,20,"Dragon"){}

