#include "Chamber.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

Chamber::Chamber(): numCells{0} {};

void Chamber::addCell(int x, int y){
    numCells++;
    Posn p = Posn(x,y);
    cells.push_back(p);
}

void Chamber::addCell(Posn p){
    numCells++;
    cells.push_back(p);
}

Posn Chamber::randomCell(){
    int random = rand() % numCells;
    return cells[random];
}

void generateDefaultChambers(Chamber &a, Chamber &b, Chamber &c, Chamber &d, Chamber &e){
    //Adding Posns for Chamber 1
    for (int i=3; i<=28; i++){
	for (int j=3; j<=6; j++){
	    Posn temp = Posn(i,j);
	    a.addCell(temp);
	}
    }

    //Adding Posns for Chamber 2
    b.addCell(61,3);
    b.addCell(61,4);
    for (int i=39; i<=60; i++){
	for (int j=3; j<=6; j++){
	    Posn temp = Posn(i,j);
	    b.addCell(temp);
     	}
    }
    for (int i=61; i<=69; i++){
	for (int j=5; j<=6; j++){
	     Posn temp = Posn(i,j);
	     b.addCell(temp);
 	}
    }
    b.addCell(70,6);
    b.addCell(71,6);
    b.addCell(72,6);
    for (int i=61; i<=75; i++){
	for (int j=7; j<=12; j++){
	     Posn temp = Posn(i,j);
	     b.addCell(temp);
	}
    }

    //Add Posns to Chamber 3
    for (int i=38; i<=49; i++){
	for (int j=10; j<=12; j++){
	     Posn temp = Posn(i,j);
	     c.addCell(temp);
	}
    }

    //Add Posns to Chamber 4
    for (int i=4; i<=24; i++){
	for (int j=15; j<=21; j++){
	     Posn temp = Posn(i,j);
	     d.addCell(temp);
	}
    }

    //Add Posns to Chamber 5
    for (int i=37; i<=64; i++){
	for (int j=19; j<=21; j++){
	    Posn temp = Posn(i,j);
	    e.addCell(temp);
	}
    }
    for (int i=65; i<=75; i++){
	for (int j=16; j<=21; j++){
	    Posn temp = Posn(i,j);
	    e.addCell(temp);
	}
    }
}
