#include "character.cc"

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

void Character::setHp(int newHp){
	if (newHp > maxhp){
		this->hp = maxhp;
	}
	else if (newHp < 0){
		this->hp = 0;
	}
	else {
		this->hp = newHp;
	}
}

void Character::setAtt(int newAtt){
	this->att = newAtt;
}

void Character::setDef(int newDef){
	this->def = newDef;
}
