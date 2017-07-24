#include "phpotion.h"
using namespace std;

bool PHPotion::known = false;

// Ctor
PHPotion::PHPotion(Posn p): Potion{p, 10, "PH"} {}

// use PH potion
void PHPotion::use(Player &p){
	p.setHp(p.getHp() - this->amount * p.potMag());
	this->known = true;
	this->useAction(p);
}

bool PHPotion::isKnown() {
	return this->known;
}

void PHPotion::notify(Subject *whoNotified) {
	this->encounterAction(*whoNotified, this->known);
}

