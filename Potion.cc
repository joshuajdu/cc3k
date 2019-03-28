#include <iostream>
#include <string>
#include "Potion.h"

using namespace std;

Potion::Potion(string name): name{name} {}

RH::RH(): Potion("RH") {}

void RH::useItem(Player &p){
    int* hp = p.get_hp();
    if (*hp + 10 > p.get_maxhp()) *hp = p.get_maxhp();
    else *hp = *hp + 10;
}

BA::BA(): Potion("BA") {}

void BA::useItem(Player &p){
    *p.get_atk() = *p.get_atk() + 5;
}

BD::BD(): Potion("BD") {}

void BD::useItem(Player &p){
    *p.get_def() = *p.get_def() + 5;
}

PH::PH(): Potion("PH") {}

void PH::useItem(Player &p){
    int* hp = p.get_hp();
    if (*hp - 10 < 0) *hp = 0;
    else *hp = *hp - 10;
}

WA::WA(): Potion("WA") {}

void WA::useItem(Player &p){
    int* atk = p.get_atk();
    if (*atk - 5 < 0) *atk = 0;
    else *atk = *atk - 5;
}

WD::WD(): Potion("WD") {}

void WD::useItem(Player &p){
    int* def = p.get_def();
    if (*def - 5 < 0) *def = 0;
    else *def = *def - 5;
}
