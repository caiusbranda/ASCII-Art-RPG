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
	srand(time(0)); // seeds generator with current time

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
	// 10 potions are spawned on each floor.
	//	each type having 1/6 probability.
	//	each chamber has equal 1/5 probability.
	//	Each tile in the chamber has equal chance.
	int numPotions = 10;

	for (int i = 0; i < numPotions; ++i) {
		Posn p{0,0};
		// first pick chamber
		int potChamber = rand() % numChambers;

		// second pick tile
		p = chambers[potChamber]->randomTile();

		//	then pick type
		int whichPot = rand() % 6;
		// <make pot goes here>
		// tiles.at(p)->notifyComing(???)
	}
}

void Board::generateGold() {

}

void Board::displayBoard() const {
	cout << *disp;
}

Tile* Board::getTile(Posn p) const {
	return tiles.at(p);
}

