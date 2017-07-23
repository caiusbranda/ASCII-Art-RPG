#include "bdpotion.h"
using namespace std;

bool BDPotion::known = false;

// Ctor
BDPotion::BDPotion(Posn p): Potion{p, 5, "bd"} {}

// use BD potion
void BDPotion::use(Player &p){
	p.setDef(p.getDef() + this->amount);
	this->known = true;
}

bool BDPotion::isKnown() {
	return this->known;
}
