#include <iostream>
#include <string>
#include <fstream>
#include "board.h"

using namespace std;

int main(int argc, char *argv[]){

	fstream in;

	Board *b = new Board;

	string cmd;
	char beg;

	// init commands
	if (cin >> beg) {

		// end of file case
		if (cin.eof()) {
			cerr << "End of file detected. Exiting." << endl;
			return 0;
		}

		switch(beg) {

			// shade
			case 's': b->choosePlayer(beg); break;
/*
			// drow
			case 'd': b->choosePlayer(beg); break;

			// vamp
			case 'v': b->choosePlayer(beg); break;

			// troll
			case 't': b->choosePlayer(beg); break;

			// goblin
			case 'g': b->choosePlayer(beg); break;

			// restart
			case 'r': b->restart(); break;

			// quit
			case 'q': b->quit(); break;
*/
			default: cerr << "INVALID INPUT" << endl; break;
		}
	}

	b->displayBoard();




	// commands while running
	string dir = "";
	bool attack = false;
	bool use = false;
	while (cin >> cmd) {
		bool failed = false;

		if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
				cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw") {

			dir = cmd;
			if (attack) {
				failed = b->attack(dir);
				attack = false;
			}
			else if (use) {
				failed = b->use(dir);
				use = false;
			}
			else failed = b->movePlayer(dir);

			if (!failed) b->actionEnemy();

			b->displayBoard();
		}

		else if (cmd == "u") {
			attack = false;
			use = true;
		}
		else if (cmd == "a") {
			use = false;
			attack = true;
		}
		/*
		// attack <direction>
		case "a": attack = true; break;

		// enemies stop moving
		case "f": b->freeze(); break;

		// restart game
		case "r": b->restart(); break;

		// quit while game is running
		case "q": b->giveUp(); break;
		*/

	}

}
