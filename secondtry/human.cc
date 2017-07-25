#include "human.h"
#include <sstream>
using namespace std;

Human::Human(Posn p) : Enemy{140, 140, 20, 20, p, 'H'} {}

Human::~Human() {}

int Human::attack(Player *player) {
  return player->attackedBy(this);
}

void Human::checkEnemyDead(Player *killer) {
  if(this->getHp() == 0) {
    int addedGold = 4;
    killer->pickUpGold(addedGold);
  }
}

string Human::getRace() const {
  return "Human";
}

