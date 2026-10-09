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

void Knight::TakeDmg(float physical, float elemental)
{
	if (blocking)															// if blocking
	{
		Character::TakeDmg(physical / 2.5);									// damage taken is reduced by 60%
		if (stamina <= 25)													// if current stamina is less than or equal to 25
		{
			stamina = 0;													// set stamina to 0
			blocking = false;												// breaks the block
		}
		else
		{
			stamina = stamina - 25;											// else lose 25 stamina
		}
		Character::TakeDmg(elemental / 1.25);								// damage taken is reduced by 20%
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
		Character::TakeDmg(physical);										// else if not blocking, take physical damage
		Character::TakeDmg(elemental);										// and take elemental damage
	}
}

std::string Knight::TakeTurn(Character& target)
{
	blocking = false;														// each turn set blocking to false

	std::cout << "\t1. Knight Slash" << std::endl;							// print menu
	std::cout << "\t2. Shield Up" << std::endl;
	std::cout << "\t3. Health Potion (" << potionCount << " left)" << std::endl;

	int damage = rand() % 11 + GetAttackPower();							// variables
	int hitChance = rand() % 20;											// 5% chance
	int critChance = rand() % 10;											// 10% chance
	int critDamage = damage * 2;
	int before = 0;
	int after = 0;
	int total = 0;
	std::string result;

	while (true)															// start of the loop
	{
		int key = _getch();
		std::cout << "\r\033[2K";

		if (key == '1')							// Attack
		{
			if (hitChance != 1)												// 5% chance to miss
			{
				if (critChance == 1)										// 10% chance to crit
				{
					before = target.GetHealth();
					target.TakeDmg(critDamage);								// deal twice the normal damage
					after = target.GetHealth();
					total = before - after;
					
					if (total >= before)									// if overkill
					{
						result = "\t::Critical Hit!::"
							"\r\033[2K\t::You UNLEASH a massive blow for \033[33m" + std::to_string(critDamage) + "\033[0m damage!::"
							"\r\033[2K\t::OVERKILL!::";
					}
					else
					{
						result = "\t::Critical Hit!::"
							"\r\033[2K\t::You UNLEASH a massive blow for \033[33m" + std::to_string(total) + "\033[0m damage!::";
					}
				}
				else
				{
					before = target.GetHealth();
					target.TakeDmg(damage);									// else do normal damage
					after = target.GetHealth();
					total = before - after;

					if (total >= before)									// if kill
					{
						result = "\t::You strike for " + std::to_string(damage) + " damage::"
							"\r\033[2K\t::You killed the " + target.GetName() + "!::";
					}
					else
					{
						result = "\t::You strike for " + std::to_string(total) + " damage::";
					}
				}
			}
			else
			{
				result = "\t::You missed::";
			}
			break;
		}

		if (key == '2')							// Block
		{

			if (stamina >= 25)												// if knight's stamina is greater or equal to 25
			{
				blocking = true;											// the knight blocks
				result = "\t::" + GetName() + " braces for impact::";
				break;
			}
			else
			{
				std::cout << "\r\033[2K";
				std::cout << "\t::\033[31mNot enough stamina!\033[0m::";	// else choose from the menu again 
				continue;
			}
		}

		if (key == '3')							// Use potion
		{
			if (potionCount <= 0)											// if you have no potions left
			{
				std::cout << "\r\033[2K";
				std::cout << "\t::\033[31mYou have 0 potions left!\033[0m::";
				continue;
			}
			else if (GetHealth() >= GetMaxHealth())
			{
				std::cout << "\r\033[2K";
				std::cout << "\t::\033[31mYour HP is full\033[0m::";
				continue;
			}
			else
			{			
				before = GetHealth();
				potionCount = potionCount - 1;								// uses up 1 potion
				Heal(30);													// heals 30 hp
				after = GetHealth();
				total = after - before;

				std::cout << "\t::\033[32m+" << total << " Health\033[0m (" << potionCount << " left)::";
				continue;
			}

		}
	
	}
	std::cout << "\r\033[1A\033[2K";
	std::cout << "\r\033[1A\033[2K";
	std::cout << "\r\033[1A\033[2K";

	Helper::Type(result, 45);
	return result;
}

void Knight::TurnOver()
{
	RecoverStamina(10);
}

