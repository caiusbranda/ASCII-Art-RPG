#include "enemy.h"

using namespace std;

Enemy::Enemy(int maxhp, int hp, int att, int def, Posn p, char icon)
	: Character{maxhp, hp, att, def, p, icon}, hasAttacked{false} {}

SubscriptionType Enemy::getSubType() {
	return SubscriptionType::Enemy;
}

char Enemy::getType() const {
	return this->getIcon();
}
