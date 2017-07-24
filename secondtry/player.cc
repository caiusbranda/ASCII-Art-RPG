#include "player.h"
#include <iostream>

using namespace std;

Player::Player(int maxhp, int hp, int att, int def, Posn p, string race)
	: Character{maxhp, hp, att, def, p, '@'}, race{race},
		action{"PC has entered floor x"}, gold{0} {}

char Player::getIcon() const {
	return '@';
}

int Player::potMag() {
	return 1;
}

Stats Player::getStats() const {
	Stats ret{this->getHp(),this->getAtt(),this->getDef(),this->gold,this->race,this->action};
	return ret;
}

Posn Player::findDir(const string &dir) {
	Posn np{0,0};
	string compass = this->race;
	compass += " moves ";

	if (dir == "no") {
		np = {0,-1};
		compass += "North";
	}
	else if (dir == "so") {
		np = {0,1};
		compass += "South";
	}
	else if (dir == "ea") {
		np = {1,0};
		compass += "East";
	}
	else if (dir == "we") {
		np = {-1,0};
		compass += "West";
	}
	else if (dir == "ne") {
		np = {1,-1};
		compass += "Northeast";
	}
	else if (dir == "nw") {
		np = {-1,-1};
		compass += "Northwest";
	}
	else if (dir == "se") {
		np = {1,1};
		compass += "Southeast";
	}
	else if (dir == "sw") {
		np = {1,-1};
		compass += "Southwest";
	}

	np = np + this->getCurPos();
	this->action = compass;
	return np;
}

bool Player::move(const string &dir) {
	Posn np = findDir(dir);

	if (canMove(np)) {
		this->moveEffect();

		// actual move

		this->detachTiles();

		this->lastPos = this->curPos;
		this->curPos = np;

		return true;
	}
	this->action = "Cannot move there";
	this->notifyObservers(SubscriptionType::Display);
	return false;
}

bool Player::canMove(const Posn &np) {
	char c = this->tileObservers.at(np)->getType();
	if (c == '.' || c == 92 || c == 'G' || c == '+' || c == '#') return true;
	else return false;
}

Posn Player::use(const string &dir) {
	Posn np = findDir(dir);

	if (canUse(np)) {
		this->tileObservers.at(np)->use(*this);
	}
	else {
		this->action = "There's no potion to use";
		this->notifyObservers(SubscriptionType::Display);
	}

	this->detachTiles();
	return np;
}

bool Player::canUse(const Posn &np) {
	char c = this->tileObservers.at(np)->getType();
	if (c != 'P') return false;
	return true;
}

void Player::setAction(const std::string &s) {
	this->action = s;
}


