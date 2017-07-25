#include "merchant.h"
using namespace std;

Merchant::Merchant(Posn p) : Enemy{30, 30, 70, 5, p, 'M'}, hostile{false} {}

Merchant::~Merchant() {}

int Merchant::attack(Player *player) {
  return player->attackedBy(this);
}

bool Merchant::isHostile() const {
  return this->hostile;
}

string Merchant::getRace() const {
  return "Merchant";
}



