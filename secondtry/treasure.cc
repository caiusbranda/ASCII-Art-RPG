#include "treasure.h"
using namespace std;

// Ctor
Treasure::Treasure(int amount, string type): Item{amount, type}{}

// Picks up gold
void Treasure::use(Player &p){
	if (this->canPickUp()){
	  p.setGold(p.getGold() + this->amount); // no setGold / getGold method in character yet
		this->pickAction();
	}
	else {
		Stats s = p.getStats();
		p.setAction(s.action + " because the dragon has not been slain");
	}
}

// updates Action when Player picks up gold
void Treasure::pickAction(Player &p) {
	Stats s = p.getStats();
	p.setAction(s.race + " picks up " + this->amount + " gold");
}

// Checks if Player can pick up gold
bool Treasure::canPickUp(){
	return true;
}
