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
	generatePotions();
	generateGold();
	generateEnemies();

	this->entities.erase(player->getCurPos());

	attachTiles(player);

}

// generates player and stairs
void Board::generatePlayer() {

	// get random chamber
	int playerChamber = (rand() % numChambers);

	// get random tile within chosen chamber
	Posn pp = chambers[playerChamber]->randomTile();

	// creates player on that tile
	this->player = new Shade(pp);
	this->entities[pp] = player;

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
	this->stairs->attach(disp);
	this->entities[sp] = stairs;

	this->stairs->notifyObservers(SubscriptionType::Display);

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

		// update display
		pot->notifyObservers(SubscriptionType::Display);
	}
}

void Board::generateGold() {
	// 10 piles of gold
	// the spawn rate of gold is
	//	5/8 chance of normal,
	//	1/8 dragon hoard,
	//	1/4 small hoard.
	int numPiles = 10;

	for (int i = 0; i < numPiles; ++i) {
		Posn p{0,0};
		Treasure *tre;
		//first pick chamber and tile
		int goldChamber = rand() % numChambers;

		while (true) {
			p = this->chambers[goldChamber]->randomTile();
			if (p == player->getCurPos() || this->entities.count(p) == 0) break;
		}

		// then pick type of gold.
		int goldType = rand() % 8;

		if (goldType < 5) {
			tre = new Treasure{p, 2, "normal"};
		}
		else if (goldType < 6) {
			tre = new DragonHoard{p};
			this->dHoards.push_back(tre);
		}
		else {
			tre = new Treasure{p, 1, "small"};
		}
		tre->attach(disp);
		this->entities[p] = tre;

		tre->notifyObservers(SubscriptionType::Display);

	}
}


///////// ENEMIES ///////////

void Board::generateEnemies() {
	// Human: 2/9,
	// Dwarf: 3/18
	// Halfling: 5/18
	// Elf: 1/9
	// Orc: 1/9
	// Merchant: 1/9
	int numEns = 20;

	for (int i = 0; i < numEns; ++i) {
		Posn p{0,0};
		Enemy *en;
		// first pick chamber
		int enChamber = rand() % numChambers;

		// then pick tile
		while(true) {
			p = chambers[enChamber]->randomTile();
			if (p == player->getCurPos() || entities.count(p) == 0) break;
		}

		// then enemy type
		int whichEn = rand() % 18;
		if (whichEn < 4) {
			en = new Elf{p}; //new Human{p};
		}
		else if (whichEn < 7) {
			en = new Elf{p}; //new Dwarf{p};
		}
		else if (whichEn < 12) {
			en = new Elf{p}; //new Halfling{p};
		}
		else if (whichEn < 14) {
			en = new Elf{p}; //new Elf{p};
		}
		else if (whichEn < 16) {
			en = new Elf{p}; //new Orc{p};
		}
		else {
			en = new Elf{p}; //new Dwarf{p};
		}

		attachThings(en, p);

		// update display
		en->notifyObservers(SubscriptionType::Display);
	}

	// DRAGONS
/*
	for (auto &i : this->dHoards) {
		Posn dhp = i.getCurPos();
		Posn dp = randDir(dhp);
		Enemy *en = new Dragon{dp};
		attachThings(en);
	}
	*/
}

void Board::attachThings(Enemy *en, const Posn &p) {
	en->attach(this->disp);
	this->enemies[p] = en;
	this->entities[p] = en;
	this->attachTiles(en);
}


///////// MOVEMENT //////////

bool Board::movePlayer(const string &dir) {
	bool success = player->move(dir);
	if (success) {
		attachTiles(player);

		this->player->notifyObservers(SubscriptionType::Potion);
		this->player->notifyObservers(SubscriptionType::Enemy);
		this->player->notifyObservers(SubscriptionType::Gold);

		Posn pp = this->player->getCurPos();

		if (this->entities.count(pp) == 1
				&& this->entities.at(pp)->getType() == 'G') {
			dead.push_back(this->entities.at(pp));
  		entities.erase(pp);
		}

		// update display
		this->player->notifyObservers(SubscriptionType::Display);

		// reverts tile moved from in display
		disp->notify(tiles.at(player->getLastPos()));
	}
	return !success;
}


////////// MISC ////////////

void Board::attachTiles(Subject *s) {

	cerr << s->getIcon() << " called attachTiles." << endl;

	Posn sp = s->getCurPos();
	for (int y = -1; y <= 1; ++y) {
		for (int x = -1; x <= 1; ++x) {
			Posn tp = {x,y};
			tp = tp + sp;

			if (this->enemies.count(tp) == 1) {
				s->attach(tp, this->enemies.at(tp));
				//cerr << s->getIcon() << " attached an enemy." << endl;
			}

			else if (this->entities.count(tp) == 1) {
				s->attach(tp, this->entities.at(tp));
				//cerr << s->getIcon() << " attached an item." << endl;
			}

			else if (player->getCurPos() == tp && s->getIcon() != 'P') {
				s->attach(tp, player);
				//cerr << s->getIcon() << " attached a player." << endl;
			}

			else {
				s->attach(tp, tiles.at(tp));
				//cerr << s->getIcon() << " attached an empty tile." << endl;
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
  		//en->deathEffect();
  		this->tiles.at(enPos)->notifyObservers(SubscriptionType::Display);
			attachTiles(this->player);
  	}
  	return false;
	}
	return true;
}

void Board::actionEnemy() {

	map<Posn, Enemy *> temp = this->enemies;

	int i = 0;
  for (auto &it : this->enemies) {
  	++i;

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
    	// if dragon then move on
    	if (en->getType() == 'D') continue;
    	// attempt to move

    	// want to:
    	//	get random positon to move to
    	//	try to move there with en->move(np)
    	//	might move or not
    	//		IF SUCCESSFUL:
    	//			need to add new location on enemy map
    	//			remove old location
    	//			update display to revert LAST position
    	//		IF NOT SUCCESSFUL:
    	//			do NOT update location on enemy map
    	// ALWAYS WANT TO ATTACH TILES

    	Posn np{0,0};
    	np = randDir(en->getCurPos());

    	// detaches tiles
    	bool success = en->move(np);

    	cout << "(" << i << ") " << (success ? "ENEMY MOVED" : "NO ENEMY MOVE :(") << endl;

 			// on success, change location of enemy in temp map, erase last location,
 			//	change last location of display to previous thing.
    	if (success) {
    		temp[np] = en;
    		temp.erase(en->getLastPos());
    		disp->notify(tiles.at(en->getLastPos()));
    	}

    	// attaches tiles from temp
    	attachTilesTemp(en, temp);
    }
  }
  this->enemies = temp;
  this->player->notifyObservers(SubscriptionType::Display);
}

void Board::attachTilesTemp(Subject *s, map<Posn, Enemy*> &ens) {
	Posn sp = s->getCurPos();
	for (int y = -1; y <= 1; ++y) {
		for (int x = -1; x <= 1; ++x) {
			Posn tp = {x,y};
			tp = tp + sp;

			if (ens.count(tp) == 1) {
				s->attach(tp, ens.at(tp));
				//cerr << s->getIcon() << " attached an enemy." << endl;
			}

			else if (this->entities.count(tp) == 1) {
				s->attach(tp, this->entities.at(tp));
				//cerr << s->getIcon() << " attached an item." << endl;
			}

			else if (player->getCurPos() == tp && s->getIcon() != 'P') {
				s->attach(tp, player);
				//cerr << s->getIcon() << " attached a player." << endl;
			}

			else {
				s->attach(tp, tiles.at(tp));
				//cerr << s->getIcon() << " attached an empty tile." << endl;
			}
		}
	}
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

