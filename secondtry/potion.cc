#include "potion.h"
using namespace std;

// Ctor
Potion::Potion(Posn p, int amount, string type): Item{p, 'P', amount, type} {}

	Potion::~Potion() {}

// use potion
void Potion::use(Player &p){}

SubscriptionType Potion::getSubType() const {
	return SubscriptionType::Potion;
}
