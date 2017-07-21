#include "bdpotion.h"
using namespace std;

// Ctor
BDPotion::BDPotion(): Potion{5, "bd"}{}

// use BD potion
void use(Player &p){
	p.setDef(p.getDef() + this->amount);
}
