#include "Sorcerer.h"


Sorcerer::Sorcerer(const std::string& _name, int _health, int _attackPower) :
	Hero(_name, _health, _attackPower),
	mana(100),
	potionCount(10)
{}

void Sorcerer::RecoverMana(int amount)
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

void Sorcerer::TakeDmg(int dmg)
{
	Character::TakeDmg(dmg * 2);
}

void Sorcerer::PrintStats() const
{

}

void Sorcerer::TakeTurn(Character& target)
{
	system("cls");															// clears the screen
	target.PrintStats();													// print target's stats
	PrintStats();															// print knight's stats

	std::cout << "1) Spells" << std::endl;
	std::cout << "2) Mana Shield" << std::endl;
	std::cout << "3) Mana Potion" << potionCount << " left)" << std::endl;

	bool running = true;													// variables
	std::string input;
	int damage = rand() % (11) + GetAttackPower();
	int critChance = rand() % 10;

	while (running)															// start of the loop
	{
		getline(std::cin, input);
		int choice;

		try																	// try/catch to prevent crashes from non number inputs
		{
			choice = stoi(input);
		}
		catch (const std::exception&)
		{
			std::cout << "::Please choose from the available options:: (1-3)" << std::endl;
			continue;
		}

		switch (choice)														// menu
		{
		case 1:							// spells

			if (critChance == 1)											// if crit chance lands on 1 (out of 10)
			{
				int critDamage = damage * 2;
				target.TakeDmg(critDamage);									// deal twice the normal damage
				std::cout << "Critical Hit! " << GetName() << " unleashed a strike for " << critDamage << " damage!" << std::endl;
			}
			else
			{
				target.TakeDmg(damage);										// else do normal damage
				std::cout << GetName() << " slashes " << target.GetName() << " for " << damage << std::endl;
			}

			running = false;
			break;

		case 2:

			break;

		case 3:

			break;

		default:

			std::cin.ignore();
			break;
		}
	}
}

void Sorcerer::TurnOver()
{
	RecoverMana(15);
}



