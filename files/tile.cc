#include "tile.h"

using namespace std;

Tile::Tile(Posn p, char type) : p{p}, type{type}, chamber{0} {

}

char Tile::getType() const {
  return this->type;

}

void Tile::notifyLeave() {
    this->type = '.'; // sets cell to empty
  }

void Tile::notifyComing(Subject *whoNotified) {
    this->type = whoNotified->getType();
    this->notifyDisplay();
  }

void Tile::notifyComing(char c) {
  this->type = c;
  this->notifyDisplay();
}

SubscriptionType Tile::getSubType() const {
	return SubscriptionType::Display;
}

int Tile::getChamber() const {
	return chamber;

}

void Tile::setChamber(int cham) {
	chamber = cham;
}

Posn Tile::getPosn() const {
	return p;
}

Tile::~Tile(){}
