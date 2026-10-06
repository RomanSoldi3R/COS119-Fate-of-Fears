#include "Goblin.h"


Goblin::Goblin(const std::string& _name, int _health, int _attackPower) : 
	Enemy(_name, _health, _attackPower)
{}

void Goblin::TakeTurn(Character & target)
{
	system("cls");													// clears the screen
	PrintStats();													// print goblin's stats
	target.PrintStats();											// print target's stats

	int damage = rand() % 11 + GetAttackPower();
	int critChance = rand() % 10;

	if (critChance == 1)											// if crit chance lands on 1 (out of 10)
	{
		int critDamage = damage * 2;
		target.TakeDmg(critDamage);									// deal twice the normal damage
		std::cout << "Critical Hit! " << GetName() << "'s club hits for " << critDamage << " damage!" << std::endl;
	}
	else
	{
		target.TakeDmg(damage);										// else do normal damage
		std::cout << GetName() << " hits " << target.GetName() << " for " << damage << std::endl;
	}
}


