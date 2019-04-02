#include "Chamber.h"
#include <vector>

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
