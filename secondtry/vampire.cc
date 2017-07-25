#include "vampire.h"

using namespace std;

// (125 HP, 25 Atk, 25 Def)
Vampire::Vampire(Posn p)
  : Player{50, 0, 25, 25, p, "Vampire"} {}

int Vampire::attack(Enemy *enemy) {
  int dmg = enemy->attackedBy(this);
  enemy->checkEnemyDead(this);
  return dmg;
}

Vampire::~Vampire() {}
