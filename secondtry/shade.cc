#include "shade.h"
#include <cstdlib>

using namespace std;

// (125 HP, 25 Atk, 25 Def)
Shade::Shade(Posn p)
	: Player{125, 125, 25, 25, p, "Shade"} {}

int Shade::attack(Enemy *enemy) {
  return enemy->attackedBy(this);
}

int Shade::attackedBy(Elf *e) {
  int dmgDealt = this->calculateDamage(e);

  if (rand() % 2 == 1) {
    dmgDealt *= 2;
  }

  this->setHp(this->getHp() - dmgDealt);
  return dmgDealt;
}

Shade::~Shade() {}
