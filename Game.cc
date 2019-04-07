#include <iostream>
#include <fstream>
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

string Game::flavorText() {
    switch (rand() % 23) {
    case 0: return "It feels frigid."; break;
    case 1: return "You feel something watching you."; break;
    case 2: return "The walls are covered in decay."; break;
    case 3: return "You gulp hesitantly."; break;
    case 4: return "You tighten your grip on your weapon."; break;
    case 5: return "Your eyes dart around, looking for danger."; break;
    case 6: return "You feel uncomfortable."; break;
    case 7: return "You twiddle your thumbs."; break;
    case 8: return "Sweat drips down your face."; break;
    case 9: return "You think of your homeland."; break;
    case 10: return "You keep a steady pace."; break;
    case 11: return "You think of your family and friends."; break;
    case 12: return "Your mind is blank."; break;
    case 13: return "You think of the exit."; break;
    case 14: return "You cough violently."; break;
    case 15: return "You find it hard to breathe."; break;
    case 16: return "You feel a menacing presence nearby."; break;
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22: return "You don't see any treasure around you yet."; break;
    }
    return "";
}

void Game::start_game(string filename){
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
	else if (race == "h"){
	    player = Player();
	}
        int level = 1;
	string action;
        while (level <= 5 ){
            Floor fl; /// ADD FLOOR GENERATION AND NECESSARY CODE HERE
	    fl.generateFloor();
	    if (filename == "") fl.spawn(player);
	    else {
		ifstream inputFile (filename);
        	string line;
        	int rowCount = 0;
        	while (getline(inputFile,line)) {
            	    fl.addInput(line, rowCount, &player);
            	    rowCount++;
        	}
        	inputFile.close();
	    }
	    if (level == 1) {action = "Player character has spawned.";}
	    else {action += "and has descended to floor "; action += to_string(level) += ".";}
            /// Loads default floor with random spawn
	    bool successfulCommand = true;
            while (*player.get_hp() > 0) {
		if (successfulCommand){
		    fl.printDisplay(player, level);
		    cout << action << "\n ";
		    if (action.back() != '\n') cout << "\n";
		    cout << "> ";
		}
		fl.resetMove();
                Posn currentPosition = player.getPosn();
		successfulCommand = false;
                cin >> input;
                if (input == "r") {level = 6; break;} /// to break out of 'level' loop
                else if (input == "q") return;
                else if (input == "u") {
                    cin >> input;
                    if (check_direction(input)) {
                        if (fl.findCell(targetPosn(currentPosition, input))->getOccupierType() == Item_) {
                            fl.findCell(targetPosn(currentPosition, input))->getItem()->useItem(player);
			    action = "PC uses " + 
                                fl.findCell(targetPosn(currentPosition, input))->getItem()->getName()
                                + ".";
			    fl.findCell(targetPosn(currentPosition, input))->removeOccupant();
                            successfulCommand = true;
                        }
                    }
                } else if (input == "a") {
                    cin >> input;
                    if (check_direction(input)) {
                        if (fl.findCell(targetPosn(currentPosition, input))->getOccupierType() == occType::Enemy_) {
			    action = fl.findCell(targetPosn(currentPosition,input))->getEnemy()->Damage(player);
			    successfulCommand = true;
			    if (fl.checkDeath()) {*player.get_gold() += 1;}
                        }
                    }
                } else if (check_direction(input)) {

                    if (fl.findCell(targetPosn(currentPosition, input))->playerCanMove() &&
			(fl.findCell(targetPosn(currentPosition, input))->getOccupierType() != Gold_ 
			|| !fl.dragonInRange(targetPosn(currentPosition, input)))) {
			player.setPosn(targetPosn(currentPosition, input));
                        fl.findCell(currentPosition)->transfer(fl.findCell(player.getPosn()));
			action = "PC moves ";

                        // for action display
                        if (input[0] == 'w') {action += "West";}
                        else if (input[0] == 'e') {action += "East";}
                        else if (input[0] == 'n') {action += "North";}
                        else {action += "South";}
                        
                        if (input[1] == 'w') {action += "west";}
                        else if (input[1] == 'e' && input[0] != 'w') {action+= "east";}
			
			bool onlyOne = true, seesSomething = false;
                        for (int relativeRow = -1; relativeRow <= 1; relativeRow++) {
                            for (int relativeCol = -1; relativeCol <= 1; relativeCol++) {
                                Posn sight = {player.getPosn().x + relativeCol,
                                              player.getPosn().y + relativeRow};
                                if (fl.findCell(sight)->getOccupierType() == occType::Item_||
                                    fl.findCell(sight)->getOccupierType() == occType::Gold_) {
                                    if (onlyOne) {
                                        onlyOne = false;
                                        seesSomething = true;
                                        action += " and sees ";
                                    } else { action += ", ";}
                                    action += fl.findCell(sight)->getItem()->actionPrint();
                                }
                            }
                        }

                        successfulCommand = true;
			if (fl.findCell(player.getPosn())->isStairs()) { break; }
			if (!seesSomething) {action += ". " + flavorText() + ".";}
                        action += ".";
                    }
                }
                if (successfulCommand) { action += fl.enemyTurn(player); } 
		//fl.printDisplay(player, level);
		if (!successfulCommand){
		    cout << "Invalid Input.\n> " << endl;
		}
            }
	    if (*player.get_hp() == 0) {
		cout << "======================================\n";
                cout << "         You lost. Try again!\n";
                cout << "======================================\n\n";

                break;
	    }
            level++;
	    player.resetPlayer();
        }
	if (level == 6) {
            int gold = *player.get_gold();
            cout << "//~~~====================================~~~\\\\\n";
            cout << "||                                          ||\n";
            cout << "||       Y  O  U              W  I  N       ||\n";
            cout << "||                                          ||\n";
            cout << "||         F I N A L      S C O R E         ||\n";
            cout << "||                                          ||\n";
            cout << "||                 {  ";
            if (race == "d") {
                if (gold < 5) {cout << 0;}
                cout << gold * 2;
            } else {
                if (gold < 10) {cout << 0;}
                if (race == "o") {cout << gold / 2;}
                else {cout << gold;}
            }               
            cout << "  }                 ||\n";
            cout << "||                                          ||\n";
            cout << "\\\\~~~====================================~~~//\n\n\n";
	    cout << "                [ PLAY AGAIN ]\n";
            cout << "                  [ Y OR N ]\n";
            char playAgain = '0';
            while (playAgain != 'Y' && playAgain != 'N') {cout << "> "; cin >> playAgain;}
            if (playAgain == 'N') break;
        }
    }
}
