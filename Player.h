#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{

    public:
        Player();
        ~Player();

        void Move(string direction);
        //void CalculateDamage(Enemy &enemy);
        //void pickupItem(const Item &item);
        //virtual void pickupTreasure(const Treasure &treasure) = 0;
        //virtual void usePotion(const Potion &potion) = 0;

        int get_hp();

    protected:
        int hp;
        int attack;
        int defence;
        int gold;
        //posn p;
        string race;
        bool barrier_suit;
        bool compass;

    private:
};

#endif // PLAYER_H
