#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <stdlib.h>
#include <iostream>

#include "Posn.h"
//#include "Player.h"

using namespace std;

class Player;

class Enemy
{
    public:

        Enemy(int hp, int atk, int def, string race);

        //virtual void Move(string direction) = 0;
        void Damage(Player &p);
        bool playerInRange(Player &p);
        string get_race();
        int *get_hp();
        int* get_atk();

    protected:

        int hp;
        int atk;
        int def;
        int room;
        string race;
        bool compass = false;
        //posn p;

    private:
};

class Werewolf : public Enemy{
    public:
        Werewolf();

    protected:

    private:
};

class Vampire : public Enemy{
    public:
        Vampire();

    protected:

    private:

};

class Goblin : public Enemy{
    public:
        Goblin();

    protected:

    private:
};

class Troll : public Enemy{
    public:
        Troll();

    protected:

    private:
};

class Phoenix : public Enemy{
    public:
        Phoenix();

    protected:

    private:
};

class Merchant : public Enemy{
    public:
        Merchant();

        void ChangeAggro();

    protected:

        static bool aggressive;

    private:
};

class Dragon : public Enemy{
    public:
        Dragon();

    protected:

    private:

};


#endif // ENEMY_H
