#include "character.h"
#include <iostream>

using namespace std;

Character::Character(int maxhp, int hp, int att, int def, Posn p, char icon) :
	Entity{p, icon}, maxhp{maxhp}, hp{hp}, att{att}, def{def} {}

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

bool Character::move(const Posn &np) {

	if (canMove(np)) {
		this->moveEffect();

		// actual move

		this->detachTiles();

		this->lastPos = this->curPos;
		this->curPos = np;

		//cerr << "lastPos: " << this->lastPos << endl;
		//cerr << "curPos: " << np << endl;

		this->notifyObservers(SubscriptionType::Display);
		return true;
	}
	this->notifyObservers(SubscriptionType::Display);
	return false;
}

bool Character::canMove(const Posn &np) {
	char c = this->tileObservers.at(np)->getType();
	if (c == '.') return true;
	else return false;
}

void Character::moveEffect() {
	return;
}

int Character::calculateDamage(Character *attacker) {
	//cerr << this->getDef() << " " << attacker->getAtt() << endl;
	double tempDmg = (100 / (100 + double(this->getDef())));
	//cerr << tempDmg << endl;
  return ceil(tempDmg * attacker->getAtt());
}

void Character::detachTiles() {
	this->tileObservers.clear();
}





