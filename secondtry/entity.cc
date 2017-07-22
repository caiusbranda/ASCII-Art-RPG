#include "entity.h"
using namespace std;

Entity::Entity(Posn p, char icon)
	: curPos{p}, lastPos{p}, icon{icon} {}

char Entity::getIcon() const {
	return this->icon;
}

Posn Entity::getCurPos() const {
	return this->curPos;
}

Posn Entity::getLastPos() const {
	return this->lastPos;
}

Entity::~Entity(){}
