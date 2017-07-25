#include "dragon.h"
using namespace std;

Dragon::Dragon(Posn p) : Enemy{150, 150, 20, 20, p, 'D'} {}

Dragon::~Dragon() {}

int Dragon::attack(Player *player) {
  return player->attackedBy(this);
}

string Dragon::getRace() const {
  return "Dragon";
}

