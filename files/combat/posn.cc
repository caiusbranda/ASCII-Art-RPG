#include "posn.h"

Posn::Posn(int x, int y) : x{x}, y{y} {}

bool Posn::operator<(const Posn &rhs) const {
	if (y < rhs.y) return true;
	if (y == rhs.y) return x < rhs.x;
	return false;
}
