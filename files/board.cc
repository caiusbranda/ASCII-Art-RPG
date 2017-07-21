#include <cstdlib>
#include <ctime>

#include "board.h"

using namespace std;

Board::Board() : disp{nullptr}, player{nullptr}, numChambers{5}, playerRace{'s'}
	{}

Board::~Board() {
	delete disp;

	delete player;

	for (auto &i : tiles) delete &i;

	for (auto &i : chambers) delete &i;
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
				tiles.at(p)->attach(disp);

				disp->updateDisplay(p,c);
				++x;
			}
		}
	}

	for (int i = 1; i <= numChambers; ++i) {
		chambers.push_back(new Chamber(this, i));
		//cout << *(chambers.at(i));
	}

}

void Board::choosePlayer(char c) {
	string file = "cc3kfloorbase.txt";

	initEmpty(file);
	generateFloor();
}

void Board::generateFloor() {
	// order is player, stairs, potions, gold, enemies
	generatePlayer();
	generatePotions();
	/*
	generateGold();
	generateEnemies();
	*/
}

// generates player and stairs
void Board::generatePlayer() {
	srand(time(0)); // seeds generator with current time

	// get random chamber
	int playerChamber = (rand() % numChambers);

	// get random tile within chosen chamber
	Posn p1 = chambers[playerChamber]->randomTile();

	// creates player on that tile
	this->player = new Goblin(p1);

	// update display
	tiles.at(p1)->notifyComing(player);

	int stairsChamber = (rand() % numChambers);
	while(true) {
		if (stairsChamber != playerChamber) break;
		stairsChamber = (rand() % numChambers);
	}

	Posn p2 = chambers[stairsChamber]->randomTile();

	tiles.at(p2)->notifyComing('/');
}

void Board::generatePotions() {

}

void Board::displayBoard() const {
	cout << *disp;
}

Tile* Board::getTile(Posn p) const {
	return tiles.at(p);
}

