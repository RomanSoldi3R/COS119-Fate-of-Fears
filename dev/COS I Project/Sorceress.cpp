#include "Sorceress.h"


Sorceress::Sorceress(const std::string& _name, int _health, int _attackPower) :
	Hero(_name, _health, _attackPower),
	mana(100),
	shield(false),
	potionCount(5)
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

void Sorceress::PrintStats() const
{

}

void Sorceress::TakeDmg(int dmg)
{
	Character::TakeDmg(dmg * 2);
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



