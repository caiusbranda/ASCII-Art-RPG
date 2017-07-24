#include "shade.h"
#include <cstdlib>

using namespace std;

// (125 HP, 25 Atk, 25 Def)
Shade::Shade(Posn p)
	: Player{125, 125, 25, 25, p, "Shade"} {}

void Shade::attack(Enemy *enemy) {
  enemy->attackedBy(this);
}

void Shade::attackedBy(Elf *e) {
  int dmgDealt = this->calculateDamage(e);

  if (rand() % 2 == 1) {
    dmgDealt *= 2;
  }

  this->setHp(this->getHp() - dmgDealt);
  
}

void Shade::attackedBy(Orc *e);
  
void Shade::attackedBy(Halfling *e);

void Shade::attackedBy(Dragon *e);

void Shade::attackedBy(Merchant *e);

void Shade::attackedBy(Dwarf *e);

void Shade::attackedBy(Human *e);

Shade::~Shade() {}
