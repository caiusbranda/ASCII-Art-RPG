#include "player.h"

using namespace std;

Player::Player(int maxhp, int hp, int att, int def, Posn p, string race)
	: Character{maxhp, hp, att, def, p, '@'}, race{race}, gold{0} {}

char Player::getIcon() const {
	return '@';
}

int Player::potionMagnitude() {
	return 1;
}

int Player::getGold() {
	return gold;
}
string Player::getRace() {
	return race;
}
