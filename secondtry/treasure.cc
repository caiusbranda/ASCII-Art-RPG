#include <sstream>
#include "player.h"
#include "treasure.h"
#include <iostream>

using namespace std;

// Ctor
Treasure::Treasure(Posn p, int amount, string type): Item{p, 'G', amount, type}{}

// Picks up gold
void Treasure::use(Subject &p){
  cerr << " OPTION USED" << endl;
	if (this->canPickUp()){
	  p.pickUpGold(this->amount);
		this->pickAction(p);
	}
	else {
		Stats s = p.getStats();
		p.setAction(s.action + " because the dragon has not been slain");
	}
}

// updates Action when Player picks up gold
void Treasure::pickAction(Subject &p) {
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
	if (this->curPos == whoNotified->getCurPos()){
		this->use(*whoNotified);
	}
}

SubscriptionType Treasure::getSubType() const {
	return SubscriptionType::Gold;
}
