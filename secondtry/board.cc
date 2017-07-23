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

//////////// INITIALIZATION /////////////

void Board::initEmpty(const string &source) {
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



//////////// GENERATION /////////////

void Board::generateFloor() {
	srand(time(0)); // seeds generator with current time

	// order is player, stairs, potions, gold, enemies

	generatePlayer();

	/*m
	generatePotions();
	generateGold();
	generateEnemies();
	*/
}

// generates player and stairs
void Board::generatePlayer() {

	// get random chamber
	int playerChamber = (rand() % numChambers);

	// get random tile within chosen chamber
	Posn pp = chambers[playerChamber]->randomTile();

	// creates player on that tile
	this->player = new Shade(pp);

	// attach display to player observers
	player->attach(disp);

	player->notifyObservers(SubscriptionType::Display);

	int stairsChamber = (rand() % numChambers);

	while(true) {
		if (stairsChamber != playerChamber) break;
		stairsChamber = (rand() % numChambers);
	}

	Posn sp = chambers[stairsChamber]->randomTile();

	// make stairs
	this->stairs = new Stairs(sp);

	// attach display to stairs observers
	stairs->attach(disp);

	stairs->notifyObservers(SubscriptionType::Display);

	// add stairs to player's observers
	player->attach(stairs);

	// add adjacent tiles to player's observers LAST
	this->attachTiles(player);
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
		if (whichPot == 0) {

		}
		else ()
		// tiles.at(p)->notifyComing(???)
	}
}

/*
void Board::generateGold() {
	// 10 piles of gold
	// the spawn rate of gold is
	//	5/8 chance of normal,
	//	1/8 dragon hoard,
	//	1/4 small hoard.
	int numPiles = 10;

	for (int i = 0; i < numPiles; ++i) {
		Posn p{0,0};
		//first pick chamber and tile
		int goldChamber = rand() % numChambers;
		p = chambers[goldChamber]->randomTile();

		// then pick type of gold.
	}
}
*/

///////// MOVEMENT //////////

void Board::movePlayer(const string &dir) {
	bool success = player->move(dir);
	if (success) {
		attachTiles(player);
		disp->notify(tiles.at(player->getLastPos()));
	}
}

///////// MISC ////////////
void Board::attachTiles(Subject *s) {
	Posn sp = s->getCurPos();
	for (int y = -1; y <= 1; ++y) {
		for (int x = -1; x <= 1; ++x) {
			Posn tp = {x,y};
			tp = tp + sp;
			s->attach(tp, tiles.at(tp));
		}
	}
}

///////// COMBAT ////////////

void Board::attack(const string &dir) {
	return;
}

void Board::use(const string &dir) {
	return;
}

/////////////////////////////


void Board::displayBoard() const {
	cout << *disp;
}

Tile* Board::getTile(const Posn &p) const {
	return tiles.at(p);
}
