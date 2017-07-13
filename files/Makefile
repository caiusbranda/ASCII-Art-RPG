CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = cc3k
OBJECTS = main.o board.o display.o posn.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
