#include "rhpotion.h"
using namespace std;

bool RHPotion::known = false;

// Ctor
RHPotion::RHPotion(Posn p): Potion{p, 10, "RH"} {}

// use RH potion
void RHPotion::use(Player &p){
	p.setHp(p.getHp() + this->amount);
	this->known = true;
	this->useAction();
}

bool RHPotion::isKnown() {
	return this->known;
}

void RHPotion::notify(Subject *whoNotified) {
	this->encounterAction(this->known);
}

