#ifndef __POSN_H__
#define __POSN_H__

struct Posn {
	unsigned int x, y;

	bool operator<(const Posn &rhs) const;
};

#endif
