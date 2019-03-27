CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -g -Werror=vla
EXEC = a5
OBJECTS = main.o Human.o Items.o Player.o Posn.o

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC}
