#include "Knight.h"


Knight::Knight(const std::string& _name, int _health, int _attackPower) : 
	Hero(_name, _health, _attackPower),
	stamina(100),															// adds stamina to the knight class
	blocking(false),														// adds blocking set to false to the knight doesn't start the fight blocking
	potionCount(5)															// adds 5 potions to the knight
{}

void Knight::RecoverStamina(int amount)
{
	if (!blocking)															// if not blocking
	{
		if (amount <= 0)													// and if stamina recovery amount is less than or equal to 0
		{
			amount = 0;														// amount is set to 0
		}
		stamina = stamina + amount;											// add the recovery amount to current stamina

		if (stamina >= 100)													// if stamina exceeds or is equal to 100 after the recovery amount
		{
			stamina = 100;													// set stamina to 100
		}
	}
}

void Knight::TakeDmg(int dmg)
{
	if (blocking)															// if blocking
	{
		Character::TakeDmg(dmg / 2);										// damage taken is reduced by 50%
		if (stamina <= 25)													// if current stamina is less than or equal to 25
		{
			stamina = 0;													// set stamina to 0
			blocking = false;												// breaks the block
		}
		else
		{
			stamina = stamina - 25;											// else lose 25 stamina
		}
	}
	else
	{
		Character::TakeDmg(dmg);											// else if not blocking, take normal damage
	}
}

void Knight::PrintStats() const
{
	std::cout << "=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=" << std::endl;
	std::cout << "|| Class: " << GetName() << " \t\t||" << std::endl;
	std::cout << "|| Health: " << GetHealth() << "/" << GetMaxHealth() << "\tStamina: " << stamina << " ||" << std::endl;
	std::cout << "=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=" << std::endl;
}

void Knight::TakeTurn(Character& target)
{
	system("cls");															// clears the screen
	blocking = false;														// each turn set blocking to false
	target.PrintStats();													// print target's stats
	PrintStats();															// print knight's stats

	std::cout << "1) Knight Slash" << std::endl;							// print menu
	std::cout << "2) Shield Up" << std::endl;
	std::cout << "3) Health Potion (" << potionCount << " left)" << std::endl;

	bool running = true;													// variables
	std::string input;
	int choice = 0;
	int damage = rand() % 11 + GetAttackPower();
	int critChance = rand() % 10;

	while (running)															// start of the loop
	{
		getline(std::cin, input);

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
		case 1:							// attack
			
			if (critChance == 1)											// if crit chance lands on 1 (out of 10)
			{
				int critDamage = damage * 2;
				target.TakeDmg(critDamage);									// deal twice the normal damage
				std::cout << "Critical Hit! " << GetName() << " unleashes a massive strike for " << critDamage << " damage!" << std::endl;
			}
			else
			{
				target.TakeDmg(damage);										// else do normal damage
				std::cout << GetName() << " slashes " << target.GetName() << " for " << damage << std::endl;
			}

			running = false;
			break;

		case 2:							// block

			if (stamina >= 25)												// if knight's stamina is greater or equal to 25
			{
				blocking = true;											// the knight blocks
				std::cout << GetName() << " braces for impact" << std::endl;
				running = false;										
				break;
			}
			else
			{
				std::cout << "Not enough stamina!" << std::endl;			// else choose from the menu again 
				continue;
			}

		case 3:							// potion

			if (potionCount <= 0)											// if you have no potions left
			{
				std::cout << "You have " << potionCount << " potions left!" << std::endl;
				continue;
			}
			else if (GetHealth() >= GetMaxHealth())
			{
				std::cout << "You are already at max health" << std::endl;
				continue;
			}
			else
			{
				Heal(30);													// heal up by 30 hp
				potionCount = potionCount - 1;								// uses up 1 potion
				std::cout << "You feel rejuvenated! " << "(" << potionCount << " left)" << std::endl;
				running = false;
				break;
			}

		default:						// incorrect choice

			std::cout << "::Please choose from the available options:: (1-3)" << std::endl;
			continue;
		}
	}

	getline(std::cin, input);
}

void Knight::TurnOver()
{
	RecoverStamina(10);
}

