#include <iostream>
#include <string>
#include "board.h"
#include "entity.h"

using namespace std;

int main(int argc, char *argv){
	Board *b = new Board;

	string cmd;

	// init commands
	if (cin >> cmd) {

		switch(cmd) {
			// shade
			case "s": b->chooseShade(); break;

			// drow
			case "d": b->chooseDrow(); break;

			// vamp
			case "v": b->chooseVamp(); break;

			// troll
			case "t": b->chooseTroll(); break;

			// goblin
			case "g": b->chooseGobl(); break;

			// restart
			case "r": b->restart(); break;

			// quit
			case "q": b->quit(); break;

			// also need end of file case

			default: cerr << "INVALID INPUT" << endl; break;
		}
	}

	// commands while running
	string dir = "";
	bool attack = false;
	bool use = false;
	while (cin >> cmd) {
		switch(cmd) {

			// set direction =
			case "no": case "so": case "ea": case "we":
			case "ne": case "nw": case "se": case "sw":
				dir = cmd;
				if (attack) b->attack(dir);
				else if (use) b->use(dir);
				else b->move(dir);
				break;

			// use potion <direction>
			case "u": use = true; break;

			// attack <direction>
			case "a": attack = true; break;

			// enemies stop moving
			case "f": b->freeze(); break;

			// restart game
			case "r": b->restart(); break;

			// quit while game is running
			case "q": b->giveUp(); break;
		}
	}
}
