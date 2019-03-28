#include <iostream>
#include "Player.h"
#include "Posn.h"
#include "Enemy.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Orc a;
    cout << "I am a " << a.get_race() << endl;
    cout << *(a.get_hp()) << endl;

    a.Position();
    a.Move("ea");
    a.Position();
    a.Move("so");
    a.Position();

    Goblin b;
    cout << "I am a " << b.get_race() << endl;
    cout << *(b.get_hp()) << endl;

    return 0;
}

