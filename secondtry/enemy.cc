#include "enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(int maxhp, int hp, int att, int def, Posn p, char icon)
	: Character{maxhp, hp, att, def, p, icon}, nearPlayer{false} {}

SubscriptionType Enemy::getSubType() const {
	// cerr << "enemy subtype" << endl;
	return SubscriptionType::Enemy;
}

char Enemy::getType() const {
	return this->getIcon();
}

void Enemy::notify(Subject *whoNotified) {
	//cerr << "enemy notified" << endl;
  this->nearPlayer = !this->nearPlayer;
}

bool Enemy::isNearPlayer() const {
  return this->nearPlayer;
}

int Enemy::attackedBy(Shade *e) {
  int dmg = this->calculateDamage(e);
  this->setHp(this->getHp() - dmg);
  return dmg;
}
