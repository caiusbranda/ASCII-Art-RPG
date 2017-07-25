#ifndef __BOARD_H__
#define __BOARD_H__

#include "common.h"

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
	std::map<Posn, Observer *> entities;
  std::map<Posn, Enemy *> enemies;
  std::map<Posn, Treasure *> treasures;

  std::vector<Chamber *> chambers;
	std::vector<Observer *> dead;


	Player *player;
	Stairs *stairs;

	int floor;
	const int numChambers;
	char playerRace;

	bool freeze;

	void initEmpty(const std::string &source);

// generation
	void generateFloor();
	void generatePlayer();
	void generatePotions();
	void generateGold();
	void generateEnemies();

// misc

	// attaches adjacent entities or tiles to subject's observers
	void attachTiles(Subject *s);

	// specifically for enemy movement
	void attachTilesTemp(Subject *s, std::map<Posn, Enemy*> &ens);

	// finds the posn of a random tile location in a direction
	Posn randDir(const Posn &p);

	// attaches things to enemies
	void attachThings(Enemy *en, const Posn &p);

	// resets player tiles
	void resetPlayer();

	void newFloor();

public:

	Board();
	~Board();

	//int getCurFloor() const;

	//Player Character choices:
	void choosePlayer(char c);

	bool movePlayer(const std::string &dir);

	// randomly generates board
	void generateBoard();

	bool attack(const std::string &dir);
	bool use(const std::string &dir);

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

	// makes enemies do their actions
	void actionEnemy();

	void clearAction();

	int generateScore(Player *p);

	void toggleFreeze();

};

#endif
