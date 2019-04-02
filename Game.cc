#include <iostream>

#include <cstdlib>
#include <ctime>

#include "Game.h"

using namespace std;

bool Game::check_direction(string direction){
    if (direction == "no" || direction == "so" || direction == "ea" || direction == "we" ||
        direction == "ne" || direction == "nw" || direction == "se" || direction == "sw"){
        return true;
    }
    return false;
}

void Game::user_turn(){

    string command;

    cin >> command;

    if (check_direction(command)){
        //move
    }

    else if (command == "u"){
        //use potion

    }
    else if (command == "a"){
        //attack enemy
    }
    else if (command == "r"){
        //restart game

    }
    else if (command == "q"){
        //quit the game
    }
}

Posn Game::get_position(int chamber){
    Posn position{0,0};
    if (chamber == 1){
        position = a.randomCell();
    }
    else if (chamber == 2){
        position = b.randomCell();
    }
    else if (chamber == 3){
        position = c.randomCell();
    }
    else if (chamber == 4){
        position = d.randomCell();
    }
    else{
        position = e.randomCell();
    }
    return position;
}

void Game::start_floor(){

    int chamber_number = rand() % 5 + 1;


   // Posn start_position{0,0};

    Posn start_position = get_position(chamber_number);

    cout << "Start: " << chamber_number << " Position: " << start_position.x << " " << start_position.y << endl;

    player.set_position(start_position);

    int stairs_number = chamber_number;

    while (stairs_number == chamber_number){
        stairs_number = rand() % 5 + 1;
    }

    Posn stairs_position = get_position(stairs_number);

    cout << "Stairs: " << stairs_number << " Position: " << stairs_position.x << " " << stairs_position.y << endl << endl;



}

void Game::start_game(){

    generateDefaultChambers(a, b, c, d, e);

    cout << "Game started" << endl;


    string race;

    cout << "Choose a race: (h/e/d/o)" << endl;
    cin >> race;

    if (race == "e"){
        player = Elf();
    }
    else if (race == "d"){
        player = Dwarf();
    }
    else if (race == "o"){
        player = Orc();
    }

    cout << "I am a " << player.get_race() << endl;

    int level = 1;
    while (level < 6 && *player.get_hp() > 0){
        start_floor();
        level++;
    }
}


