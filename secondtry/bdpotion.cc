#include "bdpotion.h"
using namespace std;

bool BDPotion::known = false;

// Ctor
BDPotion::BDPotion(Posn p): Potion{p, 5, "BD"} {}

// use BD potion
void BDPotion::use(Player &p){
	p.setDef(p.getDef() + this->amount);
	this->known = true;
	this->useAction(p);
}

bool BDPotion::isKnown() {
	return this->known;
}

void BDPotion::notify(Subject *whoNotified) {
	this->encounterAction(this->known);
}
