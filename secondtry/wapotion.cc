#include "wapotion.h"
using namespace std;

bool WAPotion::known = false;

// Ctor
WAPotion::WAPotion(Posn p): Potion{p, 5, "wa"} {}

// use WA potion
void WAPotion::use(Player &p){
	p.setAtt(p.getAtt() - this->amount);
	this->known = true;
}

bool WAPotion::isKnown() {
	return this->known;
}

void WAPotion::notify(Subject *whoNotified) {
	cerr << "CAIUS IS BIG" << endl;
}

