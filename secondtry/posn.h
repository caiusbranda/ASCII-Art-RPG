#ifndef __POSN_H__
#define __POSN_H__

struct Posn {
	int x;
	int y;

	bool operator<(const Posn &rhs) const;
	bool operator==(const Posn &rhs) const;
	Posn operator+(const Posn &rhs) const;

	Posn(int x, int y);
};

#endif
