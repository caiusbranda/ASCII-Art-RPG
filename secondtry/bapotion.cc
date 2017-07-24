#include "bapotion.h"

using namespace std;

bool BAPotion::known = false;

// Ctor
BAPotion::BAPotion(Posn p): Potion{p, 5, "BA"} {}

// use BA potion
void BAPotion::use(Player &p) {
	p.setAtt(p.getAtt() + this->amount);
	this->known = true;
	this->useAction(p);
}

bool BAPotion::isKnown() {
	return this->known;
}

void BAPotion::notify(Subject *whoNotified) {
	cerr << 1 << endl;
	this->encounterAction(*whoNotified, this->known);
}
