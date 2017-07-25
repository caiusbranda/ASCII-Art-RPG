#include "dwarf.h"
using namespace std;


Dwarf::Dwarf(Posn p) : Enemy{100, 100, 20, 30, p, 'W'} {}

Dwarf::~Dwarf() {}

int Dwarf::attack(Player *player) {
  return player->attackedBy(this);
}

int Dwarf::attackedBy(Vampire *e) {
  p->setHp(p->getHp - 5); // lose 5 HP every attack
  return this->defaultAttack(e);
}

string Dwarf::getRace() const {
  return "Dwarf";
}

