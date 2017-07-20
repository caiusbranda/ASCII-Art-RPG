#include "character.h"

Character::Character(int maxhp, int hp, int att, int def, Posn p) :
	maxhp{maxhp}, hp{hp}, att{att}, def{def}, p{p} {}

int Character::getMaxHp() const {
	return maxhp;
}

int Character::getHp() const {
	return hp;
}

int Character::getAtt() const {
	return att;
}

int Character::getDef() const {
	return def;
}
