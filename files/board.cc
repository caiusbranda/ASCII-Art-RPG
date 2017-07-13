#include "board.h"

using namespace std;

Board::Board() : disp{nullptr} {}

Board::~Board() {
	delete disp;

	for (auto i : tiles) {
		delete &i;
	}
}

void Board::initEmpty(string &source) {
	if (disp != nullptr) return;

	ifstream in{source};

	disp = new Display;

	int h = 0;
	int w = 0;

	disp->getHW(h,w);

	// each row
	for (int y = 0; y < h; ++y) {
		// each column
		for (int x = 0; x < w;) {
			Posn p{x,y};
			char c;
			if(!(in >> noskipws >> c)) return;

			if(c != '\n') {
				tiles[p] = new Tile{p,c};
				disp->updateDisplay(p,c);
				++x;
			}
		}
	}
}
]
void Board::chooseShade() {
	string file = "cc3kfloorbase.txt";
	initEmpty(file);
}

void Board::displayBoard() const {
	cout << *disp;
}
