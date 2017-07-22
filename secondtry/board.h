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

	Player *player;
	Stairs *stairs;

	const int numChambers;
	char playerRace;

	void initEmpty(std::string &source);

	void generateFloor();
	void generatePlayer();
	/*
	void generatePotions();
	void generateGold();
	*/

	//std::map<Posn, Entity*> ents;

	//int curFloor;

public:

	Board();
	~Board();

	//int getCurFloor() const;

	//Player Character choices:
	void choosePlayer(char c);

	void move(std::string dir);
	/*
	void generateBoard();
	void choosePlayer(char c);

	void attack(string dir);
	void use(string dir);
	void restart();
	void giveUp();
	void quit();
	void freeze();
	void updateTurn();
	*/

	// displays board to cout
	void displayBoard() const;

	// gets pointer to Tile at p
	Tile* getTile(Posn p) const;

};

#endif
