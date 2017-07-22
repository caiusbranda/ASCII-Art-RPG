#include "bapotion.h"
using namespace std;

// Ctor
BAPotion::BAPotion(): Potion{5, "ba"}{}

// use BA potion
void use(Player &p){
	p.setAtt(p.getAtt() + this->amount);
}
