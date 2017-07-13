#include "board.h"

void Board::initEmpty() {
	disp = new Display;

	std::cout << *disp;
}

void Board::chooseShade() {
	initEmpty();
}
