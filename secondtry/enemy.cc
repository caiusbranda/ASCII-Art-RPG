#include "enemy.h"

using namespace std;

Enemy::Enemy(int maxhp, int hp, int att, int def, Posn p, char icon)
	: Character{maxhp, hp, att, def, p, icon} {}

SubscriptionType Enemy::getSubType() {
	return SubscriptionType::Enemy;
}

void Enemy::notify(Subject *whoNotified) {
	return;
}
