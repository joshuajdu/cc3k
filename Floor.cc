#include "Floor.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Floor::addInput(string line, int x){
}

void Floor::spawn(){
    generateDefaultChambers(a, b, c, d, e);
    int chamber;
    Posn p{0,0};
    int enemyrand;
    for (int i=0; i<20; i++){
	chamber = rand() % 5;
	enemyrand = rand() % enemyRates::enemyTotal;
        switch(chamber){
            case 0: p = a.randomCell(); break;
            case 1: p = b.randomCell(); break;
            case 2: p = c.randomCell(); break;
            case 3: p = d.randomCell(); break;
            case 4: p = e.randomCell(); break;
    	}
	if (findCell(p)->getOccupierType() != None_ || !findCell(p)->isStairs()) i--;
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
    }
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

void Floor::printDisplay(){
    for(int i=0; i<(int)cells.size(); i++){
	for (int j=0; j<(int)cells[0].size(); j++){
	    cells[i][j].print();
	}
	cout << endl;
    }
}

Cell* Floor::findCell(Posn p){
    return &cells[p.y][p.x];
}
