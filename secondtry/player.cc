#include "player.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

Player::Player(int maxhp, int hp, int att, int def, Posn p, string race)
	: Character{maxhp, hp, att, def, p, '@'}, race{race},
		action{"PC has entered floor x"}, gold{0} {}

char Player::getIcon() const {
	return '@';
}

int Player::potMag() const {
	return 1;
}

Stats Player::getStats() const {
	Stats ret{this->getHp(),this->getAtt(),this->getDef(),this->gold,this->race,this->action};
	return ret;
}

string Player::getRace() const {
  return this->race;
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
		np = {-1,1};
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
		this->notifyObservers(SubscriptionType::Enemy);

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
	}
	this->notifyObservers(SubscriptionType::Display);
	this->notifyObservers(SubscriptionType::Enemy);
	this->detachTiles();
	return np;
}

bool Player::canUse(const Posn &np) {
	char c = this->tileObservers.at(np)->getType();
	if (c != 'P') return false;
	return true;
}

void Player::setAction(const string &s) {
	this->action = s;
}

void Player::appendAction(const string &s) {
  this->action += " " + s;
}

Posn Player::canAttack(const string &dir, map<Posn, Enemy*> &enemies) {
  stringstream ss;
  Posn attackPosn = this->findDir(dir);
  if(enemies.count(attackPosn) == 1) {
    Enemy* enemy = enemies.at(attackPosn);
    int dmg = this->attack(enemy);
    ss << this->race << " dealt " << dmg << " damage to " << enemy->getRace() << " (" << enemy->getHp() << " HP)";
    this->action = ss.str();
  } else {
    this->action = "Cannot attack that!";
  }
  this->notifyObservers(SubscriptionType::Display);
  return attackPosn;
}

//--------- ATTACKS -----------//

int Player::attackedBy(Elf *e) {
  int dmgDealt = this->calculateDamage(e);

  if (rand() % 2 == 1) {
    dmgDealt *= 2;
  }

  this->setHp(this->getHp() - dmgDealt);
  return dmgDealt;
}

int Player::attackedBy(Orc *e) {
  return this->defaultAttack(e);
}

int Player::attackedBy(Halfling *e) {
  return this->defaultAttack(e);
}

int Player::attackedBy(Dragon *e) {
  return this->defaultAttack(e);
}

int Player::attackedBy(Merchant *e) {
  return this->defaultAttack(e);
}

int Player::attackedBy(Dwarf *e) {
  return this->defaultAttack(e);
}

int Player::attackedBy(Human *e) {
  return this->defaultAttack(e);
}

int Player::getGold() const {
	return this->gold;
}

void Player::pickUpGold(int gold) {
	this->gold += gold;
  stringstream ss;
  ss << this->race << " picked up " << gold << " gold.";
  this->appendAction(ss.str());
}

void Player::notify(Subject *whoNotified) {
	return;
}

char Player::getType() const {
	return this->getIcon();
}

SubscriptionType Player::getSubType() const {
	return SubscriptionType::Player;
}








