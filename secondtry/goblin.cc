
#include <cstdlib>
#include <ctime>

#include "goblin.h"

using namespace std;

// goblin (110 HP, 15 Atk, 20 Def, steals 5 gold from every slain enemy)
Goblin::Goblin(Posn p) : Player{110, 110, 15, 20, p} {}

Goblin::~Goblin() {}
/*
void Goblin::attack(Character &other) {
	srand(time(0)); // seeds generator with current time

	int miss = rand() % 2
	if (miss == 1) other.attackedBy(*this);
	else cout << "Player Goblin's attack missed!" << endl;
}

void Goblin::attackedBy(Orc &o) {
	//50% chance to miss
	//Damage(Defender) = ceiling((100/(100+Def(Defender))) * Atk(Attacker))
}
*/

void Goblin::attack(Enemy *enemy) {
  enemy->attackedBy(this);
}
