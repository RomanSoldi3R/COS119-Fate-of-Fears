#include "Sorceress.h"


Sorceress::Sorceress(const std::string& _name, int _health, int _attackPower) :
	Hero(_name, _health, _attackPower),
	mana(100),
	shield(false),
	potionCount(5),
	elementalPower(35)
{}

void Sorceress::RecoverMana(int amount)
{
	if (amount <= 0)
	{
		amount = 0;
	}
	mana = mana + amount;
	if (mana >= 100)
	{
		mana = 100;
	}
}

// ============================== Overrides ==============================

void Sorceress::PrintStats() const
{

}

void Sorceress::TakeDmg(float physical, float elemental)
{
	if (shield)															// if shield is up
	{
		Character::TakeDmg(dmg / 1.25);									// damage taken is reduced by 90%
		if (mana <= 25)													// if current mana is less than or equal to 25
		{
			mana = 0;													// set mana to 0
			shield = false;												// breaks the block
		}
		else
		{
			mana = mana - 25;											// else lose 25 stamina
		}

	}
	else
	{
		Character::TakeDmg(dmg * 1.25);											// else if not blocking, take normal damage
	}
}

std::string Sorceress::TakeTurn(Character& target)
{
	std::cout << "1) Wand" << std::endl;
	std::cout << "2) Mana Shield" << std::endl;
	std::cout << "3) Book of Spells" << potionCount << " left)" << std::endl;

	bool running = true;													// variables
	int damage = rand() % 11 + GetAttackPower();
	int hitChance = rand() % 20;											// 5% chance
	int critChance = rand() % 10;											// 10% chance
	int critDamage = damage * 2;
	int before = 0;
	int after = 0;
	int finalResult = 0;
	std::string result;

	while (running)															// start of the loop
	{
		int key = _getch();

	}

	return result;
}

void Sorceress::TurnOver()
{
	RecoverMana(15);
}



