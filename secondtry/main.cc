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

	cout << endl;
	for (int i = 0; i < 52; ++i) cout << "=";
	cout << endl;
	cout << ">>>>>>>> ";
	cout << "WELCOME TO CC3K - DAY ONE EDITION™";
	cout << " <<<<<<<<" << endl;
	for (int i = 0; i < 52; ++i) cout << "=";
	cout << endl << endl;
	cout << "Thank you for purchasing this Early Access™ title!" << endl;
	cout << endl;

	// init commands
	while(true) {

		cout << "To start the game, please enter a character to select a race:" << endl;
		cout << "(s)hade (hard)" << endl;
		cout << "(d)row (med)" << endl;
		cout << "(v)amprie (med)" << endl;
		cout << "(t)roll (easy)" << endl;
		cout << "(g)oblin (hard)" << endl;

		cin >> beg;

		// end of file case
		if (cin.eof()) {
			cerr << "End of file detected. Exiting." << endl;
			return 0;
		}
		// shade
		else if (beg == 's'){
			b->choosePlayer(beg);
			break;
		}
/*
		// drow
		else if (beg == 'd') b->choosePlayer(beg); break;

		// vamp
		else if (beg == 'v') b->choosePlayer(beg); break;

		// troll
		else if (beg == 't') b->choosePlayer(beg); break;

		// goblin
		else if (beg == 'g') b->choosePlayer(beg); break;

		// restart
		else if (beg == 'r') b->restart(); break;

		// quit
		else if (beg == 'q') b->quit(); break;
*/
		else {
			cerr << "Invalid input! Please try again. (or enter 'q' to quit)" << endl;
			cin.clear();
			cin.ignore();
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
		// enemies stop moving
		case "f": b->freeze(); break;

		// restart game
		case "r": b->restart(); break;

		// quit while game is running
		case "q": b->giveUp(); break;
*/
	}

}
