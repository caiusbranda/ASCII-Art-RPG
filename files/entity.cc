#include "entity.h"
using namespace std;

Posn Entity::getPosn() const {
  return Posn(this->x, this->y);
}

Entity::~Entity(){}
