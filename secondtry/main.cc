#include <iostream> 
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "board.h"

using namespace std;

void handleArgs(int argc, char* argv[], bool dlcEnabled, string &source){
	for (int i = 1; i < argc; ++i) {
		string argument;
		istringstream ss{argv[i]};
		argument = ss.str();
		if (argument == "-dlc") dlcEnabled = true;
		else source = argument;
	}
}

int main(int argc, char *argv[]){
	srand(time(0));

	while(true) {
		fstream in;

		Board b{};

		string cmd;
		char beg;
		bool dlcEnabled;
		string source = "cc3kfloorbase.txt";

		cout << endl;
		for (int i = 0; i < 52; ++i) cout << "=";
		cout << endl;
		cout << ">>>>>>>> ";
		cout << "WELCOME TO CC3K - DAY ONE EDITION™";
		cout << " <<<<<<<<" << endl;
		for (int i = 0; i < 52; ++i) cout << "=";
		cout << endl << endl;
		cout << "Thank you for purchasing this Early Access™ title!" << endl;
		cout << "From CMJ Family Inc™" << endl;
		cout << endl;
		
		handleArgs(argc, argv, dlcEnabled, source);

		// init commands
		while(true) {

			cout << "To start the game," << endl;
			cout << "please enter a character to select a race:" << endl;
			cout << "(s)hade (hard)" << endl;
			cout << "(d)row (med)" << endl;
			cout << "(v)ampire (med)" << endl;
			cout << "(t)roll (easy)" << endl;
			cout << "(g)oblin (hard)" << endl;

			if (dlcEnabled) {
				cout << "g(h)ost (???)" << endl;
			}

			cout << endl;

			cin >> beg;

			// end of file case
			if (cin.eof()) {
				cerr << "End of file detected. Exiting." << endl;
				return 0;
			}
			// shade
			else if (beg == 's'){
				b.choosePlayer(beg, source);
				break;
			}

			// drow
			else if (beg == 'd') {
				b.choosePlayer(beg);
				break;
			}

			// vamp
			else if (beg == 'v') {
				b.choosePlayer(beg);
				break;
			}

			// troll
			else if (beg == 't') {
				b.choosePlayer(beg);
				break;
			}
			// goblin
			else if (beg == 'g') {
				b.choosePlayer(beg);
				break;
			}

			// restart
			else if (beg == 'r') return;

			// quit
			else if (beg == 'q') b.quit(); break;
			
			else {
				cout << "Invalid input! Please try again. (or enter 'q' to quit)" << endl;
				cout << endl;
				cin.clear();
				cin.ignore();
			}
		}

		b.displayBoard();




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
					failed = b.attack(dir);
					attack = false;
				}
				else if (use) {
					failed = b.use(dir);
					use = false;
				}
				else {
	        failed = b.movePlayer(dir);
	      }

				if (!failed) b.actionEnemy();

				b.displayBoard();
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
			case "f": b.freeze(); break;

			// restart game
			case "r": b.restart(); break;

			// quit while game is running
			case "q": b.giveUp(); break;
	*/

			b.clearAction();
		}
		// Check if game has ended
		if (b->isGameOver() && b->wonGame()) {
			cout << "You won!" << endl;
			int score = b->generateScore();
			cout << "Your score: " << score << endl;
		}
		else if (b->isGameOver()) {
			cout << "Game over!" << endl;
		}
	}
}
