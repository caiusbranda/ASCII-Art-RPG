#include "posn.h"

bool Posn::operator<(const Posn &rhs) const {
	if (x < rhs.x) return true;
	if (y < rhs.y) return true;
	return false;
}
