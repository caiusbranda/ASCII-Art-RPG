#include "phpotion.h"
using namespace std;

bool PHPotion::known = false;

// Ctor
PHPotion::PHPotion(Posn p): Potion{p, 10, "ph"} {}

// use PH potion
void PHPotion::use(Player &p){
	p.setHp(p.getHp() - this->amount);
	this->known = true;
}

bool PHPotion::isKnown() {
	return this->known;
}
