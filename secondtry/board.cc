#include <cstdlib>
#include <sstream>

#include "board.h"

using namespace std;

Board::Board() : disp{nullptr}, player{nullptr}, numChambers{5}, playerRace{'s'}
{}

Board::~Board() {
	delete disp;

	delete player;

	for (auto &i : tiles) delete &i;

	for (auto &i : chambers) delete &i;

	for (auto &i : dead) delete &i;

	for (auto &i : entities) delete &i;

	for (auto &i : enemies) delete &i;
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
	//generatePotions();
	generateEnemies();
	/*
	generateGold();

	*/
}

// generates player and stairs
void Board::generatePlayer() {

	// get random chamber
	int playerChamber = (rand() % numChambers);

	// get random tile within chosen chamber
	Posn pp{40, 12};// = chambers[playerChamber]->randomTile();

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

//// Potions ////

void Board::generatePotions() {
	// 10 potions are spawned on each floor.
	//	each type having 1/6 probability.
	//	each chamber has equal 1/5 probability.
	//	Each tile in the chamber has equal chance.
	int numPotions = 10;

	for (int i = 0; i < numPotions; ++i) {
		Posn p{0,0};
		Potion *pot;
		// first pick chamber
		int potChamber = rand() % numChambers;

		// second pick tile
		while(true) {
			p = chambers[potChamber]->randomTile();
			if (p == player->getCurPos() || entities.count(p) == 0) break;
		}
		//	then pick type
		int whichPot = rand() % 6;
		if (whichPot == 0) {
			pot = new BAPotion(p);
		}
		else if (whichPot == 1) {
			pot = new BDPotion(p);
		}
		else if (whichPot == 2) {
			pot = new WAPotion(p);
		}
		else if (whichPot == 3) {
			pot = new WDPotion(p);
		}
		else if (whichPot == 4) {
			pot = new RHPotion(p);
		}
		else if (whichPot == 5) {
			pot = new PHPotion(p);
		}
		pot->attach(disp);
		this->entities[p] = pot;

		attachTiles(player);

		// update display
		pot->notifyObservers(SubscriptionType::Display);
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

///////// ENEMIES ///////////

void Board::generateEnemies() {
	Posn p{38, 10};
	Enemy *en = new Elf{p};
	en->attach(disp);
	this->enemies[p] = en;
	this->entities[p] = en;
	attachTiles(en);

	//cerr << "count at generation: " << enemies.count(p) << endl;

	en->notifyObservers(SubscriptionType::Display);
}

///////// MOVEMENT //////////

bool Board::movePlayer(const string &dir) {
	bool success = player->move(dir);
	if (success) {
		attachTiles(player);

		this->player->notifyObservers(SubscriptionType::Potion);
		this->player->notifyObservers(SubscriptionType::Enemy);
		// update display
		this->player->notifyObservers(SubscriptionType::Display);

		// makes last tile back to normal
		disp->notify(tiles.at(player->getLastPos()));
	}
	return !success;
}

////////// MISC ////////////

void Board::attachTiles(Subject *s) {
	Posn sp = s->getCurPos();
	for (int y = -1; y <= 1; ++y) {
		for (int x = -1; x <= 1; ++x) {
			Posn tp = {x,y};
			tp = tp + sp;

			if (this->entities.count(tp) == 1) {
				//this->player->attach(this->entities.at(tp));
				s->attach(tp, this->entities.at(tp));
			}
			else if (this->enemies.count(tp) == 1) {
				s->attach(tp, this->enemies.at(tp));
			}
			else {
				s->attach(tp, tiles.at(tp));
			}

		}
	}
}

Posn Board::randDir(const Posn &p) {
	int r = rand() % 8;
	Posn np{0,0};

	if (r == 0) {
		np = {-1,-1};
	}
	else if (r == 1) {
		np = {-1, 0};
	}
	else if (r == 2) {
		np = {-1, 1};
	}
	else if (r == 3) {
		np = {0, 1};
	}
	else if (r == 4) {
		np = {1, 1};
	}
	else if (r == 5) {
		np = {1, 0};
	}
	else if (r == 6) {
		np = {1, -1};
	}
	else if (r == 7) {
		np = {0, -1};
	}

	return np = np + p;
}

///////// COMBAT ////////////

bool Board::attack(const string &dir) {
  Posn enPos = this->player->canAttack(dir, enemies);

  // check if there is an enemy there (attack went through)
  if (this->enemies.count(enPos) == 1) {
  	Enemy *en = this->enemies.at(enPos);
  	int hp = en->getHp();
  	// check if enemy hp is 0
  	if (hp == 0) {
  		dead.push_back(en);
  		entities.erase(enPos);
  		enemies.erase(enPos);

  		this->tiles.at(enPos)->notifyObservers(SubscriptionType::Display);
			attachTiles(this->player);
  	}
  	return false;
	}
	return true;
}

void Board::actionEnemy() {

	map<Posn, Enemy *> temp = this->enemies;

  for (auto &it : this->enemies) {


  	// checks if near player
    if(it.second->isNearPlayer()) {
      stringstream ss;
      int dmg = it.second->attack(this->player);

      // printing action:
      ss << "and "<< it.second->getRace() << " dealt " << dmg << " damage to "
       << this->player->getRace() << " (" << this->player->getHp() << " HP)";

      this->player->appendAction(ss.str());
    }

    // if the enemy doesnt attack player, move the enemy
    else {
    	// first pick spot for enemy to move
    	Enemy *en = it.second;

    	// attempt to move
    	Posn np{0,0};

    	while(true) {
    		np = randDir(en->getCurPos());

    		// detaches tiles on successful move
    		bool success = en->move(np);
    		if (success) break;
    	}
    	// attaches tiles again
    	attachTiles(en);

    	temp[np] = en;

    	temp.erase(en->getLastPos());

    	// revert last position
    	disp->notify(tiles.at(en->getLastPos()));
    }
  }
  this->enemies = temp;
  this->player->notifyObservers(SubscriptionType::Display);
}

///////// POTIONS ///////////

bool Board::use(const string &dir) {
	Posn potPos = this->player->use(dir);
	bool failed = true;

	if (entities.count(potPos) == 1 &&
		entities.at(potPos)->getType() == 'P') {
		dead.push_back(entities.at(potPos));
		entities.erase(potPos);
		failed = false;
	}

	this->tiles.at(potPos)->notifyObservers(SubscriptionType::Display);
	attachTiles(this->player);
	return failed;
}

//////////////////////////////


void Board::displayBoard() const {
	cout << *disp;
}

Tile* Board::getTile(const Posn &p) const {
	return tiles.at(p);
}

