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

        Enemy(int hp, int atk, int def, string race, int x=0, int y=0);

        //virtual void Move(string direction) = 0;
        void Damage(Player &p);
        bool playerInRange(Player &p);
        string get_race();
        int *get_hp();
        int *get_atk();
        Posn getPosn();
	virtual void print() = 0;
        virtual bool isAggressive();

    protected:

        int hp;
        int atk;
        int def;
        int room;
        string race;
        bool compass = false;
        Posn p;

    private:
};

class Werewolf : public Enemy{
    public:
        Werewolf();
	void print();
    protected:

    private:
};

class Vampire : public Enemy{
    public:
        Vampire();
	void print();
    protected:

    private:

};

class Goblin : public Enemy{
    public:
        Goblin();
	void print();
    protected:

    private:
};

class Troll : public Enemy{
    public:
        Troll();
	void print();
    protected:

    private:
};

class Phoenix : public Enemy{
    public:
        Phoenix();
	void print();
    protected:

    private:
};

class Merchant : public Enemy{
    public:
        Merchant();
	void print();
        void ChangeAggro();
        bool isAggressive();

    protected:

        static bool aggressive;

    private:
};

class Dragon : public Enemy{
    public:
        Dragon();
	void print();
    protected:

    private:

};

#endif // ENEMY_H
