#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <stdlib.h>
#include <iostream>
#include "Enemy.h"
#include "Posn.h"

using namespace std;

class Player
{
    public:
        Player(int hp = 140, int attack = 20, int defence = 20, string race = "Human");

        void Move(string direction);
        void CalculateDamage(Enemy &enemy);
        //void pickupItem(const Item &item);
        //virtual void pickupTreasure(const Treasure &treasure) = 0;
        //virtual void usePotion(const Potion &potion) = 0;

        int get_maxhp();
        int* get_hp();
        int get_baseatk();
        int* get_atk();
        int get_basedef();
        int* get_def();

        string get_race();
        void Position();

    protected:
        int hp;
        int atk;
        int def;
        int maxhp;
        int baseatk;
        int basedef;
        int gold;
        posn p = {0,0};
        string race;
        bool barrier_suit;
        bool compass;

    private:
};

class Dwarf : public Player
{
    public:
        Dwarf();

    protected:

    private:
};

class Elf : public Player
{
    public:
        Elf();

    protected:

    private:
};

class Orc : public Player
{
    public:
        Orc();

    protected:

    private:
};

#endif // PLAYER_H
