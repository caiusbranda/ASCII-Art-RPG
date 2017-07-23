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
	p.setAction(s.race + " uses " + this->type + ".");
}

void Potion::encounterAction(bool known) {

