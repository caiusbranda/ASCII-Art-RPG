#include "wapotion.h"
using namespace std;

bool WAPotion::known = false;

// Ctor
WAPotion::WAPotion(Posn p): Potion{p, 5, "WA"} {}

// use WA potion
void WAPotion::use(Player &p){
	p.setAtt(p.getAtt() - this->amount);
	this->known = true;
	this->useAction(p);
}

bool WAPotion::isKnown() {
	return this->known;
}

void WAPotion::notify(Subject *whoNotified) {
	this->encounterAction(*whoNotified, this->known);
}

