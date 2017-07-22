#include "player.h"

using namespace std;

Player::Player(int maxhp, int hp, int att, int def, Posn p)
	: Character{maxhp, hp, att, def, p, '@'} {}

char Player::getIcon() const {
	return '@';
}

int Player::potionMagnitude() {
	return 1;
}
