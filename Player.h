#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
    public:
        Player(int hp, int attack, int defence, string race);
        ~Player();

        void Move(string direction);
        //void CalculateDamage(Enemy &enemy);
        //void pickupItem(const Item &item);
        //virtual void pickupTreasure(const Treasure &treasure) = 0;
        //virtual void usePotion(const Potion &potion) = 0;

	int get_maxhp();
        int* get_hp();
	int get_baseatk();
	int* get_atk();
	int get_basedef();
	int* get_def();

    protected:
	int maxhp;
        int hp;
	int baseatk;
        int atk;
	int basedef;
        int def;
        int gold;
        //posn p;
        string race;
        bool barrier_suit;
        bool compass;

    private:
};

#endif // PLAYER_H
