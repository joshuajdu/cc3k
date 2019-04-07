#include <iostream>
#include <string>
#include "Potion.h"

using namespace std;

Potion::Potion(int x, int y, string name): Item(x, y, name) {}

void Potion::print(){
    cout << "P";
}

bool Potion::isTreasure() { return false; }

RH::RH(int x, int y): Potion(x, y, "RH") {}

void RH::useItem(Player &p){
    found = true;
    int* hp = p.get_hp();
    if (*hp + 10 > p.get_maxhp()) *hp = p.get_maxhp();
    else *hp = *hp + 10;
}

string RH::actionPrint() {
    if (!found) return "an unknown potion";
    else return "a " + getName() + " potion";
}

bool RH::foundItem(){ return found; }

BA::BA(int x, int y): Potion(x, y, "BA") {}

void BA::useItem(Player &p){
    found = true;
    *p.get_atk() = *p.get_atk() + 5;
}

string BA::actionPrint() {
    if (!found) return "an unknown potion";
    else return "a " + getName() + " potion";
}

bool BA::foundItem(){ return found; }

BD::BD(int x, int y): Potion(x, y, "BD") {}

void BD::useItem(Player &p){
    found = true;
    *p.get_def() = *p.get_def() + 5;
}

bool BD::foundItem(){ return found; }

string BD::actionPrint() {
    if (!found) return "an unknown potion";
    else return "a " + getName() + " potion";
}

PH::PH(int x, int y): Potion(x, y, "PH") {}

void PH::useItem(Player &p){
    found = true;
    int* hp = p.get_hp();
    if (p.get_race() == "Elf"){
        if (*hp + 10 > p.get_maxhp()) *hp = p.get_maxhp();
        else *hp = *hp + 10;
    }
    else{
        if (*hp - 10 < 0) *hp = 0;
    	else *hp = *hp - 10;
    }
}

string PH::actionPrint() {
    if (!found) return "an unknown potion";
    else return "a " + getName() + " potion";
}

bool PH::foundItem(){ return found; }

WA::WA(int x, int y): Potion(x, y, "WA") {}

void WA::useItem(Player &p){
    found = true;
    int* atk = p.get_atk();
    if (p.get_race() == "Elf"){
	*atk = *atk + 5;
    }
    else{
    	if (*atk - 5 < 0) *atk = 0;
    	else *atk = *atk - 5;
    }
}

string WA::actionPrint() {
    if (!found) return "an unknown potion";
    else return "a " + getName() + " potion";
}

bool WA::foundItem(){ return found; }

WD::WD(int x, int y): Potion(x, y, "WD") {}

void WD::useItem(Player &p){
    found = true;
    int* def = p.get_def();
    if (p.get_race() == "Elf"){
	*def = *def + 5;
    }
    else{
    	if (*def - 5 < 0) *def = 0;
    	else *def = *def - 5;
    }
}

string WD::actionPrint() {
    if (!found) return "an unknown potion";
    else return "a " + getName() + " potion";
}

bool WD::foundItem(){ return found; }

// Initialize founds to false
bool RH::found = false;
bool BA::found = false;
bool BD::found = false;
bool PH::found = false;
bool WA::found = false;
bool WD::found = false;

