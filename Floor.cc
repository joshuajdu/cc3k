#include "Floor.h"
#include <string>
#include "Cell.h"
#include "Posn.h"

using namespace std;

void Floor::addInput(string line, int x){
    for (int i=0; i<line.size(); i++){
	Posn p = Posn(i,x);
	Cell c;
	switch (line[0]){
	    case '|':
		c = Cell(p,cellType::vWall);
`		break;
	    case '-':
		c = Cell(p,cellType::hWall);
		break;
	    case '+':
		c = Cell(p,cellType::door);
		break;
	    case '#':
		c = Cell(p,cellType::passage);
		break;
	    case '.':
		c = Cell(p,cellType::tile);
		break;
	    case ' ':
		c = Cell(p,cellType::empty);
		break;
	    case '':
		
		break; 
 	}
	c.push_back(c);
    }
}
