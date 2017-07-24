#include "potion.h"
using namespace std;

// Ctor
Potion::Potion(Posn p, int amount, string type): Item{p, 'P', amount, type} {}

// Dtor
Potion::~Potion() {}

// use potion
void Potion::use(Player &p){}

SubscriptionType Potion::getSubType() const {
	return SubscriptionType::Potion;
}

// updates Action of Player after using potion
void Potion::useAction(Player &p) {
	Stats s = p.getStats();
	p.setAction(s.race + " uses " + this->type);
}

// updates Action when PC encounters potion
void Potion::encounterAction(Subject &p, bool known) {
	Stats s = p.getStats();
	if (known) {
		p.setAction(s.action + " and sees a " + this->type + " potion");
	}
	else {
		p.setAction(s.action + " and sees an unknown potion");
	}
}
