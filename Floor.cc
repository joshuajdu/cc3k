#include "Floor.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "Cell.h"
#include "Posn.h"
#include "Chamber.h"

using namespace std;

void Floor::addInput(string line, int x){
}

void Floor::spawn(){
    
    int chamber = rand() % 5;
    
    int enemyrand;
    for (int i=0; i<20; i++){
	if (i < enemyRates::W){
	    Werewolf temp;
	    enemies.push_back(&temp);
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

vector<Enemy*>* Floor::getEnemies(){
    return &enemies;
}
