#include <sstream>
#include "player.h"
#include "treasure.h"

using namespace std;

// Ctor
Treasure::Treasure(Posn p, int amount, string type): Item{p, 'G', amount, type}{}

// Picks up gold
void Treasure::use(Player &p){
	if (this->canPickUp()){
	  p.setGold(p.getGold() + this->amount);
		this->pickAction(p);
	}
	else {
		Stats s = p.getStats();
		p.setAction(s.action + " because the dragon has not been slain");
	}
}

// updates Action when Player picks up gold
void Treasure::pickAction(Player &p) {
	Stats s = p.getStats();
	ostringstream os;
	os << " picks up " << this->amount << " gold";
	string action = os.str();
	p.setAction(s.race + action);
}

// Checks if Player can pick up gold
bool Treasure::canPickUp(){
	return true;
}

// Player has walked on gold
void Treasure::notify(Subject *whoNotified){
	this->use(*whoNotified);
}
