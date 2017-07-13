#include "tile.h"

using namespace std;

Tile::Tile(char type, Posn p) : p{p}, type{type} {}


char Tile::getType() const { 
  return this->type;
}

void Tile::notifyLeave() {
    this->type = '.'; // sets cell to empty
  }

void Tile::notifyComing(Subject &whoNotified) {
    this->type = whoNotified.getType();
    this->notifyDisplay();
  }
