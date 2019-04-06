#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Game.h"

using namespace std;

bool Game::check_direction(string direction){
    if (direction == "no" || direction == "so" || direction == "ea" || direction == "we" ||
        direction == "ne" || direction == "nw" || direction == "se" || direction == "sw"){
        return true;
    }
    return false;
}

Posn Game::targetPosn(Posn p, string direction){
    if (direction == "no") {p.y--;}
    else if (direction == "so") {p.y++;}
    else if (direction == "ea") {p.x++;}
    else if (direction == "we") {p.x--;}
    else if (direction == "ne") {p.y--; p.x++;}
    else if (direction == "nw") {p.y--; p.x--;}
    else if (direction == "se") {p.y++; p.x++;}
    else if (direction == "sw") {p.y++; p.x--;}
    return p;
}

void Game::start_game(){
    cout << "Game started" << endl;
    string race, input;
    while (true) {
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
        int level = 1;
        while (level <= 5 ){
            Floor fl; /// ADD FLOOR GENERATION AND NECESSARY CODE HERE
	    fl.generateFloor();
	    fl.spawn(player);
	    fl.printDisplay(player);
	    cout << "Player character has spawned." << endl;
            /// Loads default floor with random spawn
            bool floor_not_complete = true;
            while (floor_not_complete && *player.get_hp() > 0) {
                Posn currentPosition = player.getPosn();
                bool successfulCommand = false;
                cin >> input;
                if (input == "r") {level = 6; break;} /// to break out of 'level' loop
                else if (input == "q") return;
                else if (input == "u") {
                    cin >> input;
                    if (check_direction(input)) {
                        if (fl.findCell(targetPosn(currentPosition, input))->getItem()) {
                            fl.findCell(targetPosn(currentPosition, input))->getItem()->useItem(player);
                            successfulCommand = true;
                        }
                    }
                } else if (input == "a") {
                    cin >> input;
                    if (check_direction(input)) {
                        if (fl.findCell(targetPosn(currentPosition, input))->getOccupierType() == occType::Enemy_) {
                            player.Damage(fl.findCell(targetPosn(currentPosition,input))->getEnemy());
                            successfulCommand = true;
                        }
                    }
                } else if (check_direction(input)) {
                    if (fl.findCell(targetPosn(currentPosition, input))->playerCanMove()) {
			player.setPosn(targetPosn(currentPosition, input));
                        fl.findCell(currentPosition)->transfer(fl.findCell(player.getPosn()));
			 /// ### CELL.CC TRANSFER MUST BE CHANGED!!!
                        successfulCommand = true; /// WE NEED TO CHECK FOR OCCTYPE OR ELSE IT WILL BE WRONG!
                    }
                }
                if (successfulCommand) { fl.enemyTurn(player); } ///### ADD MOVE COMMAND INSIDE OF IF STATEMENT
		fl.printDisplay(player);
		if (!successfulCommand){
		    cout << "Invalid Input" << endl;
		}
            }
            level++;
        }
    }
}
