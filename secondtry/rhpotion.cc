#include "rhpotion.h"
using namespace std;

bool RHPotion::known = false;

// Ctor
RHPotion::RHPotion(Posn p): Potion{p, 10, "rh"} {}

// use RH potion
void RHPotion::use(Player &p){
	p.setHp(p.getHp() + this->amount);
	this->known = true;
}

bool RHPotion::isKnown() {
	return this->known;
}

void RHPotion::notify(Subject *whoNotified) {
	cerr << "CAIUS IS BIG" << endl;
}

