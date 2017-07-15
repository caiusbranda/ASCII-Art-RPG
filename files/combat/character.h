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
  virtual void move(string dir);
  void attack(Character &other);

// abstract class
  virtual ~Character() = 0;
};

#endif
