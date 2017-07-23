#include "phpotion.h"
using namespace std;

bool PHPotion::known = false;

// Ctor
PHPotion::PHPotion(Posn p): Potion{p, 10, "PH"} {}

// use PH potion
void PHPotion::use(Player &p){
	p.setHp(p.getHp() - this->amount);
	this->known = true;
	this->updateAction();
}

bool PHPotion::isKnown() {
	return this->known;
}

void PHPotion::notify(Subject *whoNotified) {
	cerr << "CAIUS IS BIG" << endl;
}

