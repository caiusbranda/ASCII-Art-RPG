#include "enemy.h"

using namespace std;

Enemy::Enemy(int maxhp, int hp, int att, int def, Posn p, bool hostile) : Character{maxhp, hp, att, def, p},
  besidePlayer{false}, hostile{hostile} {}

