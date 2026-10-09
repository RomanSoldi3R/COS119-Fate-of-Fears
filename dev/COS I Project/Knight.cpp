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

// ============================== Overrides ==============================

void Knight::PrintStats() const
{
	Art::KnightIcon();
	std::cout << "\r\033[8C\033[33m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
	std::cout << "\r\033[8C\033[33m||\033[0m" << "\r\033[27C" << GetName() << "\r\033[49C" << "\033[33m||\033[0m" << std::endl;
	std::cout << "\r\033[8C\033[33m||\033[0m Health: " << "\r\033[41C\033[32m" << std::setw(3) << std::setfill('0') << GetHealth() << "/" << GetMaxHealth() << "\033[0m\r\033[49C" << "\033[33m||\033[0m" << std::endl;
	std::cout << "\r\033[8C\033[33m||\033[0m Stamina: " << "\r\033[45C\033[33m" << std::setw(3) << std::setfill('0') << stamina << "\033[0m\r\033[49C" << "\033[33m||\033[0m" << std::endl;
	std::cout << "\r\033[8C\033[33m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
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

std::string Knight::TakeTurn(Character& target)
{
	blocking = false;														// each turn set blocking to false

	std::cout << "\t1. Knight Slash" << std::endl;							// print menu
	std::cout << "\t2. Shield Up" << std::endl;
	std::cout << "\t3. Health Potion (" << potionCount << " left)" << std::endl;

	int damage = rand() % 11 + GetAttackPower();							// variables
	int critChance = rand() % 10;
	int critDamage = damage * 2;
	int before = 0;
	int after = 0;
	int finalResult = 0;
	std::string result;

	while (true)															// start of the loop
	{
		int key = _getch();
		
		if (key == '1')							// Attack
		{
			if (critChance == 1)											// if crit chance lands on 1 (out of 10)
			{
				before = target.GetHealth();
				target.TakeDmg(critDamage);									// deal twice the normal damage
				after = target.GetHealth();
				finalResult = before - after;

				result = "::Critical Hit! " + GetName() + " unleashed a massive strike for \033[33m" + std::to_string(finalResult) + "\033[0m!::";
			}
			else
			{
				before = target.GetHealth();
				target.TakeDmg(damage);										// else do normal damage
				after = target.GetHealth();
				finalResult = before - after;

				result = "::" + GetName() + " slashed " + target.GetName() + " for " + std::to_string(finalResult) + "::";
			}

			break;
		}

		if (key == '2')							// Block
		{

			if (stamina >= 25)												// if knight's stamina is greater or equal to 25
			{
				blocking = true;											// the knight blocks
				result = "::" + GetName() + " braces for impact::";
				break;
			}
			else
			{
				std::cout << "\r\033[2K";
				std::cout << "::Not enough stamina!::";		// else choose from the menu again 
				continue;
			}
		}

		if (key == '3')							// Use potion
		{
			if (potionCount <= 0)											// if you have no potions left
			{
				std::cout << "\r\033[2K";
				std::cout << "::You have \033[31m0\033[0m potions left!::";
				continue;
			}
			else if (GetHealth() >= GetMaxHealth())
			{
				std::cout << "\r\033[2K";
				std::cout << "::You have full health::";
				continue;
			}
			else
			{
				before = GetHealth();
				Heal(30);													// heal up by 30 hp
				after = GetHealth();
				finalResult = after - before;
				potionCount = potionCount - 1;								// uses up 1 potion

				result = "::You healed for \033[32m" + std::to_string(finalResult) + "\033[0m (" + std::to_string(potionCount) + " left)::";
				break;
			}

		}
		
	}

	return result;
}

void Knight::TurnOver()
{
	RecoverStamina(10);
}

