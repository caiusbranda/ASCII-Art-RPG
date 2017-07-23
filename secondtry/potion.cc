#include "potion.h"
using namespace std;

// Ctor
Potion::Potion(int amount, string type): Item{amount, type} {}

// use potion
void Potion::use(Player &p){}
