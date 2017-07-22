#include "character.h"

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

bool Character::move(const string &dir) {
	Posn np{0,0};
	string compass = "";

	if (dir == "no"){
		np = {0,-1};
		compass = "North";
	}
	else if (dir == "so") {
		np = {0,1};
		compass = "South";
	}
	else if (dir == "ea") {
		np = {1,0};
		compass = "East";
	}
	else if (dir == "we") {
		np = {-1,0};
		compass = "West";
	}
	else if (dir == "ne") {
		np = {1,-1};
		compass = "Northeast"
	}
	else if (dir == "nw") {
		np = {-1,-1};
		compass = "Northwest";
	}
	else if (dir == "se") {
		np = {1,1};
		compass = "Southeast";
	}
	else if (dir == "sw") {
		np = {1,-1};
		compass = "Southwest";
	}

	np = np + this->getCurPos();

	if (canMove(np)) {
		this->moveEffect();

		// actual move
		this->detachTiles();
		this->lastPos = this->curPos;
		this->curPos = np;

		// update display

		this->notifyObservers(SubscriptionType::Display);

		return true;
	}
	action = "Cannot move there!";
	this->notifyObservers(SubscriptionType::Display);
	return false;
}

bool Character::canMove(const Posn &np) {
	char c = this->tileObservers.at(np)->getType();
	if (c == '.' || c == 92 || c == 'G' || c == '+' || c == '#') return true;
	else return false;
}

void Character::moveEffect() {
	return;
}

string Character::getAction() {
	return action;
}


