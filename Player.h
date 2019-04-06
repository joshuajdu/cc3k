#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <stdlib.h>
#include <iostream>
#include <memory>
//#include "Enemy.h"
#include "Posn.h"

using namespace std;

class Enemy;

class Player
{
    public:
        Player(int hp = 140, int attack = 20, int defence = 20, string race = "Human", int x = 0, int y = 0);

        void Move(string direction);
        void Damage(std::shared_ptr<Enemy> e);
        //void pickupItem(const Item &item);
        //virtual void pickupTreasure(const Treasure &treasure) = 0;
        //virtual void usePotion(const Potion &potion) = 0;

        int get_maxhp();
        int* get_hp();
        int get_baseatk();
        int* get_atk();
        int get_basedef();
        int* get_def();
        int* get_gold();
        bool get_barriersuit();
        void switch_barrier();

        string get_race();
        Posn getPosn();
	void setPosn(Posn p);
        void Position();

    protected:
        int maxhp;
        int hp;
        int baseatk;
        int atk;
        int basedef;
        int def;
        string race;
        int gold;
        Posn p;
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
