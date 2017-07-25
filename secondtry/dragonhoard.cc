#include "dragonhoard.h"
using namespace std;

// Ctor
DragonHoard::DragonHoard(Posn p): Treasure{p, 6, "dHoard"}, dragonSlain{false}{}

// Checks if PC can pick up dragon hoard
bool DragonHoard()::canPickUp(){
	return DragonSlain;
}

// Notify
void DragonHoard::notify(Subject *whoNotified){
	// Case 1: Subject is Dragon
	if (...) {
		this->DragonSlain = true;
	}
	// Case 2: Subject is PC
	else {
		this->use(*whoNotified);
	}
}
