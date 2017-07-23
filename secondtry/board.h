#ifndef __BOARD_H__
#define __BOARD_H__

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

#include "posn.h"

//#include "observer.h"
#include "display.h"
//#include "subject.h"
#include "tile.h"
#include "chamber.h"
#include "stairs.h"
//#include "character.h"
//#include "player.h"
#include "shade.h"

/*
#include "passage.h"
#include "entity.h"
*/

class Display;
class Chamber;
class Player;

class Board {

	Display *disp;

	std::map<Posn, Tile*> tiles;
	std::vector<Chamber *> chambers;
	//std::vector<Enemy *> enemies;

	Player *player;
	Stairs *stairs;

	const int numChambers;
	char playerRace;

	void initEmpty(const std::string &source);

// generation
	void generateFloor();
	void generatePlayer();
	/*
	void generatePotions();
	void generateGold();
	*/

	//std::map<Posn, Entity*> ents;

	//int curFloor;

// misc
	void attachTiles(Subject *s);

public:

	Board();
	~Board();

	//int getCurFloor() const;

	//Player Character choices:
	void choosePlayer(char c);

	void movePlayer(const std::string &dir);


	void generateBoard();

	void attack(const std::string &dir);
	void use(const std::string &dir);
	/*
	void restart();
	void giveUp();
	void quit();
	void freeze();
	void updateTurn();
	*/

	// displays board to cout
	void displayBoard() const;

	// gets pointer to Tile at p
	Tile* getTile(const Posn &p) const;

};

#endif
