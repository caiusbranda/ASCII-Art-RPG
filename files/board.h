#ifndef __BOARD_H__
#define __BOARD_H__

#include <string>
#include <iostream>
#include <fstream>
#include <map>

#include "posn.h"

#include "observer.h"
#include "display.h"
#include "subject.h"
#include "tile.h"
/*
#include "room.h"
#include "chamber.h"
#include "passage.h"
#include "entity.h"
*/

class Display;

class Board {

	Display *disp;

	std::map<Posn, Tile*> tiles;

	// void generateItem(char i);

	//std::map<Posn, Entity*> ents;

	//int curFloor;

public:

	Board();
	~Board();

	void initEmpty(std::string &source);

	//int getCurFloor() const;

	//Player Character choices:

	void chooseShade();
	/*
	void generateBoard();
	void choosePlayer(char c);
	void move(string dir);
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

};

#endif
