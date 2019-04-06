#include "Floor.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Floor::printDisplay(Player &player){
    for(int i=0; i<(int)cells.size(); i++){
        for (int j=0; j<(int)cells[0].size(); j++){
            cells[i][j].print();
        }
        cout << endl;
    }
    cout << "Race: " << player.get_race() << " Gold: " << *player.get_gold();
    cout << "                                                  Floor 1" << endl;
    cout << "Hp: " << *player.get_hp() << endl;
    cout << "Atk: " << *player.get_atk() << endl;
    cout << "Def: " << *player.get_def() << endl;
    cout << "Action: ";
}

Posn Floor::targetPosn(Posn p, int direction){
    if (direction == 0) {p.y--;}
    else if (direction == 1) {p.y++;}
    else if (direction == 2) {p.x++;}
    else if (direction == 3) {p.x--;}
    else if (direction == 4) {p.y--; p.x++;}
    else if (direction == 5) {p.y--; p.x--;}
    else if (direction == 6) {p.y++; p.x++;}
    else if (direction == 7) {p.y++; p.x--;}
    return p;
}

bool Floor::playerInRange(Posn p){
    for (int i=-1; i<=1; i++){
	for (int j=-1; j<=1; j++){
	    Posn here = Posn(p.x + i, p.y + j);
	    if (findCell(here)->getOccupierType() == 0){
		return true;
	    }
	}
    }
    return false;
}

vector<Posn> Floor::enemyMovable(Posn p){
    vector<Posn> returnval;
    for (int i=-1; i<=1; i++){
	for (int j=-1; j<=1; j++){
	    Posn here = Posn(p.x + i, p.y + j);
	    if (findCell(here)->enemyCanMove()){
		returnval.push_back(here);
	    }
	}
    }
    return returnval;
}

void Floor::moveEnemy(Posn pos, Player &player){
    if (findCell(pos)->getOccupierType() == 1 && !findCell(pos)->hasMoved()){
	if (playerInRange(pos)){
	    findCell(pos)->getEnemy()->Damage(player);
	}
	else{
	    vector<Posn> movable = enemyMovable(pos);
	    if (movable.size() != 0){
    	    	int moveRand = rand()%movable.size();
    	    	Posn target = movable[moveRand];
    	    	findCell(pos)->transfer(findCell(target));
	    }
	}
    }       
}

void Floor::enemyTurn(Player &player){
    for (int i=0; i<int(cells.size()); i++){
	for (int j=0; j<int(cells[0].size()); j++){
	    Posn p = Posn(j,i);
	    moveEnemy(p, player);
	}
    }
}

void Floor::addInput(string line, int row, Player* player){
     for (int k = 0; k < (int)cells[row].size(); k++) {
        char cellInput = line[k];
        switch (cellInput) {
            case '0': cells[row][k].addOccupant(shared_ptr<Item>(new RH(k, row))); break;
            case '1': cells[row][k].addOccupant(shared_ptr<Item>(new BA(k, row))); break;
            case '2': cells[row][k].addOccupant(shared_ptr<Item>(new BD(k, row))); break;
            case '3': cells[row][k].addOccupant(shared_ptr<Item>(new PH(k, row))); break;
            case '4': cells[row][k].addOccupant(shared_ptr<Item>(new WA(k, row))); break;
            case '5': cells[row][k].addOccupant(shared_ptr<Item>(new WD(k, row))); break;
            case '6': cells[row][k].addOccupant(shared_ptr<Item>(new Treasure(k, row, 1))); break;
            case '7': cells[row][k].addOccupant(shared_ptr<Item>(new Treasure(k, row, 2))); break;
            case '8': cells[row][k].addOccupant(shared_ptr<Item>(new Treasure(k, row, 4))); break;
            case '9': cells[row][k].addOccupant(shared_ptr<Item>(new Treasure(k, row, 6))); break;
            case '@': cells[row][k].addOccupant(player); break;
	    case '\\': cells[row][k].setStairs(); break;
            case 'V': {
	   	enemies.push_back(shared_ptr<Enemy>(new Vampire()));
            	cells[row][k].addOccupant(enemies[enemies.size()-1]);
	    } break;
            case 'W': {
	   	enemies.push_back(shared_ptr<Enemy>(new Werewolf()));
            	cells[row][k].addOccupant(enemies[enemies.size()-1]);
	    }  break;
            case 'N': { 
	    	enemies.push_back(shared_ptr<Enemy>(new Goblin()));
            	cells[row][k].addOccupant(enemies[enemies.size()-1]);
	    } break;
            case 'M': {
	    	enemies.push_back(shared_ptr<Enemy>(new Merchant()));
            	cells[row][k].addOccupant(enemies[enemies.size()-1]);
	    } break;
            case 'D': {
	    	enemies.push_back(shared_ptr<Enemy>(new Dragon()));
            	cells[row][k].addOccupant(enemies[enemies.size()-1]);
	    } break;
            case 'X': {
	    	enemies.push_back(shared_ptr<Enemy>(new Phoenix()));
            	cells[row][k].addOccupant(enemies[enemies.size()-1]);
	    } break;
            case 'T': {
	    	enemies.push_back(shared_ptr<Enemy>(new Troll()));
            	cells[row][k].addOccupant(enemies[enemies.size()-1]);
	    } break;
	}
    }
}

Posn Floor::randomCellChamber(int chamber){
    if (chamber==-1) chamber = rand() % 5;
    Posn p{0,0};
    switch(chamber){
	case 0: p = a.randomCell(); break;
	case 1: p = b.randomCell(); break;
	case 2: p = c.randomCell(); break;
	case 3: p = d.randomCell(); break;
	case 4: p = e.randomCell(); break;
    }
    return p;
}

bool Floor::generateEnemy(){
    int enemyrand = rand() % enemyRates::enemyTotal;
    Posn p = randomCellChamber();
    if (findCell(p)->getOccupierType() != None_ || findCell(p)->isStairs()) return false;
    else {
        if (enemyrand < enemyRates::W){
            enemies.push_back(shared_ptr<Enemy>(new Werewolf()));
            findCell(p)->addOccupant(enemies[enemies.size()-1]);
        }
        else if (enemyrand < enemyRates::V){
            enemies.push_back(shared_ptr<Enemy>(new Vampire()));
            findCell(p)->addOccupant(enemies[enemies.size()-1]);
        }
        else if (enemyrand < enemyRates::N){
            enemies.push_back(shared_ptr<Enemy>(new Goblin()));
            findCell(p)->addOccupant(enemies[enemies.size()-1]);
        }
        else if (enemyrand < enemyRates::M){
            enemies.push_back(shared_ptr<Enemy>(new Merchant()));
            findCell(p)->addOccupant(enemies[enemies.size()-1]);
        }
        else if (enemyrand < enemyRates::X){
            enemies.push_back(shared_ptr<Enemy>(new Phoenix()));
            findCell(p)->addOccupant(enemies[enemies.size()-1]);
        }
        else{
            enemies.push_back(shared_ptr<Enemy>(new Troll()));
            findCell(p)->addOccupant(enemies[enemies.size()-1]);
        }
    }
    return true;
}

bool Floor::generatePotion(){
    int potionrand = rand() % 6;
    Posn p = randomCellChamber();
    if (findCell(p)->getOccupierType() != None_ || findCell(p)->isStairs()) return false;
    else{
	if (potionrand == 0){ findCell(p)->addOccupant(shared_ptr<Item>(new RH(p.x, p.y))); }
	else if (potionrand == 1) { findCell(p)->addOccupant(shared_ptr<Item>(new BA(p.x, p.y))); }
	else if (potionrand == 2) { findCell(p)->addOccupant(shared_ptr<Item>(new BD(p.x, p.y))); }
	else if (potionrand == 3) { findCell(p)->addOccupant(shared_ptr<Item>(new PH(p.x, p.y))); }
	else if (potionrand == 4) { findCell(p)->addOccupant(shared_ptr<Item>(new WA(p.x, p.y))); }
	else if (potionrand == 5) { findCell(p)->addOccupant(shared_ptr<Item>(new WD(p.x, p.y))); }
    }
    return true;
}

bool Floor::generateDragon(shared_ptr<Item> treasure){
    vector<Posn> possible;
    for (int i=-1; i<=1; i++){
	for (int j=-1; j<=1; j++){
	    Posn temp = treasure->getPosn();
	    temp.x = temp.x+i;
	    temp.y = temp.y+j;
	    if (findCell(temp)->getOccupierType() != None_ ||
	  	findCell(temp)->isStairs() ||
		findCell(temp)->type() != cellType::tile) {}
	    else possible.push_back(temp);
	}
    }
    if (possible.size() == 0) return false;
    int random = rand() % possible.size();
    enemies.push_back(shared_ptr<Enemy>(new Dragon()));
    findCell(possible[random])->addOccupant(enemies[enemies.size()-1]);
    return true;
}

bool Floor::generateGold(){
    int goldrand = rand() % goldRates::goldTotal;
    Posn p = randomCellChamber();
    if (findCell(p)->getOccupierType() != None_ || findCell(p)->isStairs()) return false;
    else{
	if (goldrand < goldRates::G){
	    findCell(p)->addOccupant(shared_ptr<Item>(new Treasure(p.x, p.y, 1)));
	}
        else if (goldrand < goldRates::G_D){
	    findCell(p)->addOccupant(shared_ptr<Item>(new Treasure(p.x, p.y, 6)));
	    generateDragon(findCell(p)->getItem());
	}
	else{
	    findCell(p)->addOccupant(shared_ptr<Item>(new Treasure(p.x, p.y, 2)));
	}
    }
    return true;
}

void Floor::spawn(Player &player){
    generateDefaultChambers(a, b, c, d, e);
    Posn p{0,0};
    int playerChamber = rand() % 5;
    int stairsChamber = playerChamber;
    // Makes sure player and stairway are in different one's
    while(playerChamber == stairsChamber){
	stairsChamber = rand() % 5;
    }
    // Put Player in cell
    player.setPosn(randomCellChamber(playerChamber));
    findCell(player.getPosn())->addOccupant(&player);
    // Put Stairway in cell
    findCell(randomCellChamber(stairsChamber))->setStairs();
    // Generate Potions
    for (int i=0; i<10; i++){ if(!generatePotion()) i--; }
    for (int i=0; i<10; i++){ if(!generateGold()) i--; }
    for (int i=enemies.size(); i<20; i++){ if(!generateEnemy()) i--; }
}

void Floor::generateFloor(){
    ifstream inFile;
    inFile.open("layout.txt");
    if (!inFile){
	cerr << "layout.txt does not exist, please enter default layout.";
	exit(1);
    }
    string line;
    int row = 0;
    while(getline(inFile, line)){
	vector<Cell> rowCells;
	for (int i=0; i<(int)line.size(); i++){
	    Posn p = Posn(i,row);
	    switch (line[i]){
		case '|': {
		    Cell c = Cell(p,cellType::vWall);
		    rowCells.push_back(c);
		} break;
		case '-': {
		    Cell c = Cell(p,cellType::hWall);
                    rowCells.push_back(c);
		} break;
		case '+': {
		    Cell c = Cell(p,cellType::door);
                    rowCells.push_back(c);
		} break;
		case '#': {
		    Cell c = Cell(p,cellType::passage);
                    rowCells.push_back(c);
		} break;
		case '.': {
		    Cell c = Cell(p,cellType::tile);
                    rowCells.push_back(c);
		} break;
		case ' ': {
		    Cell c = Cell(p,cellType::empty);
                    rowCells.push_back(c);
		} break;
	    }
	}
    cells.push_back(rowCells);
    }
}

Cell* Floor::findCell(Posn p){
    return &cells[p.y][p.x];
}
