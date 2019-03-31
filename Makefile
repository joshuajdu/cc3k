CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -g -Werror=vla
EXEC = a5
OBJECTS = main.o Item.o Player.o Posn.o Potion.o Treasure.o Enemy.o Cell.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC}
