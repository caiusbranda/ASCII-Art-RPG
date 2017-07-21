#include "phpotion.h"
using namespace std;

// Ctor
PHPotion::PHPotion(): Potion{10, "ph"}{}

// use PH potion
void use(Player &p){
	p.setHp(p.getHp() - this->amount);
}
