#include "potion.h"
using namespace std;

// Ctor
Potion::Potion(int amount, string type, bool isNearby): Item{amount, type}, isNearby{isNearby}{}

// use potion
void Potion::use(Player &p){}
