#include "wdpotion.h"
using namespace std;

// Ctor
WDPotion::WDPotion(): Potion{5, "wd"}{}

// use WD potion
void use(Player &p){
	  p.setDef(p.getDef() - this->amount);
}
