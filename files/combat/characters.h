#ifndef __CHARACTERS_H__
#define __CHARACTERS_H__

struct Posn {
	int x;
	int y;
}

class Character {

	const int maxhp;

	int hp;
	int att;
	int def;

	//Posn p;

public:

// accessors:
	int getMaxHp() const;
	int getHp() const;
	int getAtt() const;
	int getDef() const;
	//Posn getPos() const;

// mutators:
	void setHp(int hp);
	void setAtt(int att);
	void setDef(int def);
	//void setPos(Posn &p);

	//void move(string dir);


// abstract class
virtual ~Character() = 0;

};

#endif
