#include "treasure.h"
using namespace std;

// Ctor
Treasure::Treasure(int amount): Item{amount}{}

// Picks up gold
void Treasure::use(Player &p){
	  p.setGold(p.getGold() + this->amount); // no setGold / getGold method in character yet
}
