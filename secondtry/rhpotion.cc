#include "rhpotion.h"
using namespace std;

// Ctor
RHPotion::RHPotion(): Potion{10, "rh"}{}

// use RH potion
void use(Player &p){
	p.setHp(p.getHp() + this->amount);
}
