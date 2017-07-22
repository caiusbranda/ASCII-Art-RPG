#include "wapotion.h"
using namespace std;

// Ctor
WAPotion::WAPotion(): Potion{5, "wa"}{}

// use WA potion
void use(Player &p){
	  p.setAtt(p.getAtt() - this->amount);
}
