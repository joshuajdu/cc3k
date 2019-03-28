#include <iostream>
#include <string>
#include "Potion.h"

using namespace std;

Potion::Potion(int x, int y, string name): Item(x, y, name) {}

RH::RH(int x, int y): Potion(x, y, "0") {}

void RH::useItem(Player &p){
    int* hp = p.get_hp();
    if (*hp + 10 > p.get_maxhp()) *hp = p.get_maxhp();
    else *hp = *hp + 10;
}

BA::BA(int x, int y): Potion(x, y, "1") {}

void BA::useItem(Player &p){
    *p.get_atk() = *p.get_atk() + 5;
}

BD::BD(int x, int y): Potion(x, y, "2") {}

void BD::useItem(Player &p){
    *p.get_def() = *p.get_def() + 5;
}

PH::PH(int x, int y): Potion(x, y, "3") {}

void PH::useItem(Player &p){
    int* hp = p.get_hp();
    if (*hp - 10 < 0) *hp = 0;
    else *hp = *hp - 10;
}

WA::WA(int x, int y): Potion(x, y, "4") {}

void WA::useItem(Player &p){
    int* atk = p.get_atk();
    if (*atk - 5 < 0) *atk = 0;
    else *atk = *atk - 5;
}

WD::WD(int x, int y): Potion(x, y, "5") {}

void WD::useItem(Player &p){
    int* def = p.get_def();
    if (*def - 5 < 0) *def = 0;
    else *def = *def - 5;
}
