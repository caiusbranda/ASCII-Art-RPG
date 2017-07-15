#ifndef __GOBLIN_H__
#define __GOBLIN_H__

class Goblin final : public Player {
public:

	// goblin (110 HP, 15 Atk, 20 Def, steals 5 gold from every slain enemy)
	Goblin(Posn p);

	// other attacks this
	void attack(Character &other);

	// this attacked by other
	void attackedBy(Orc &o) override;
//void attackedBy(Elf &e) override;


  /*
  virtual void attackedBy(Halfling &e) = 0;
  virtual void attackedBy(Dragon &e) = 0;
  virtual void attackedBy(Merchant &e) = 0;
  virtual void attackedBy(Dwarf &e) = 0;
  virtual void attackedBy(Human &e) = 0;
  */

};

#endif
