CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -g -Werror=vla
EXEC = cc3k+
OBJECTS = main.o Item.o Player.o Posn.o Potion.o Treasure.o Enemy.o Cell.o Chamber.o Floor.o Game.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC}
