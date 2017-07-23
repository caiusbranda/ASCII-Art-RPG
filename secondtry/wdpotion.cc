#include "wdpotion.h"
using namespace std;

bool WDPotion::known = false;

// Ctor
WDPotion::WDPotion(Posn p): Potion{p, 5, "wd"} {}

// use WD potion
void WDPotion::use(Player &p){
	p.setDef(p.getDef() - this->amount);
	this->known = true;
}

bool WDPotion::isKnown() {
	return this->known;
}

void WDPotion::notify(Subject *whoNotified) {
	cerr << "CAIUS IS BIG" << endl;
}

