#include "Knight.h"


Knight::Knight(const std::string& _name, int _health, int _attackPower) : 
	Hero(_name, _health, _attackPower),
	stamina(100),															// adds stamina to the knight class
	potionCount(5),
	blocking(false),														// adds blocking set to false to the knight doesn't start the fight blocking															// adds 5 potions to the knight
	skills{ 
		Ability("Raise Shield", 24) }
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
	std::cout << "\r\033[8C\033[33m||\033[0m\r\033[27C" << GetName() << "\r\033[49C\033[33m||\033[0m" << std::endl;
	std::cout << "\r\033[8C\033[33m||\033[0m Health: \r\033[41C\033[32m" << std::setw(3) << std::setfill('0') << GetHealth() << "/" << GetMaxHealth() << "\033[0m\r\033[49C\033[33m||\033[0m" << std::endl;
	std::cout << "\r\033[8C\033[33m||\033[0m Stamina: \r\033[45C\033[33m" << std::setw(3) << std::setfill('0') << stamina << "\033[0m\r\033[49C\033[33m||\033[0m" << std::endl;
	std::cout << "\r\033[8C\033[33m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
}


void Knight::TakeDmg(float _physical, float _elemental)
{
	if (blocking)															// if blocking
	{
		Character::TakeDmg(_physical / 2.5);								// damage taken is reduced by 60%
		Character::TakeDmg(_elemental / 1.25);								// damage taken is reduced by 20%

		if (stamina <= skills[BLOCK].GetAbilityCost())						// if current stamina is less than or equal to block cost
		{
			stamina = 0;													// set stamina to 0
			blocking = false;												// breaks the block
		}
		else
		{
			stamina = stamina - skills[BLOCK].GetAbilityCost();			// else lose block cost
		}
	}
	else
	{
		Character::TakeDmg(_physical);										// else if not blocking, take physical damage
		Character::TakeDmg(_elemental);										// and take elemental damage
	}
}


std::string Knight::TakeTurn(Character& target)
{
	blocking = false;														// each turn set blocking to false

	std::cout << "\t1. Attack" << std::endl;								// print menu
	std::cout << "\t2. [Skills]" << std::endl;
	std::cout << "\t3. Health Potion" << std::endl;

	bool running = true;													// variables
	bool inMenu = true;
	int damage = rand() % 11 + GetAttackPower();
	int hitChance = rand() % 20;											// 5% chance
	int critChance = rand() % 10;											// 10% chance
	int critDamage = damage * 2;
	int before = 0;
	int after = 0;
	int total = 0;
	std::string result;

	while (running)															// start of the loop
	{
		int key = _getch();
		std::cout << "\r\033[2K";

		if (key == '1')	//======================== Attack ========================
		{
			Helper::ErasePreviousLines(3);

			if (hitChance != 1)												// chance to miss
			{
				if (critChance == 1)										// chance to crit
				{
					before = target.GetHealth();
					target.TakeDmg(critDamage);								// deal twice the normal damage
					after = target.GetHealth();
					total = before - after;
					
					if (total >= critDamage || total >= before)
					{
						result = "\t::Critical Hit!::"
							"\r\033[2K\t::You UNLEASH a MASSIVE blow for \033[33m" + std::to_string(critDamage) + "\033[0m damage!::";
					}
					else
					{
						result = "\t::You UNLEASH a MASSIVE blow::"
							"\r\033[2K\t::But only " + std::to_string(total) + " damage was dealt::";
					}
				}
				else
				{
					before = target.GetHealth();
					target.TakeDmg(damage);									// else do normal damage
					after = target.GetHealth();
					total = before - after;

					if (total >= damage || total >= before)
					{
						result = "\t::You strike for " + std::to_string(damage) + " damage::";
					}
					else
					{
						result = "\t::You strike::"
							"\r\033[2K\t::But only " + std::to_string(total) + " damage was dealt::";
					}
				}
			}
			else
			{
				result = "\t::You missed::";
			}
			break;
		}

		if (key == '2')	//======================== [Skills] ========================
		{
			Helper::ErasePreviousLines(3);

			int counter = 1;

			for (const Ability& ability : skills)
			{
				std::cout << "\t" << counter++ << ". " << ability.GetAbilityName() << std::endl;
			}

			inMenu = true;

			while (inMenu)
			{
				int key = _getch();
				int index = key - '0' - 1;									// turns the key press into the index position: key '1'(ascii value 49) - '0'(ascii value 48) - 1 = 0(index position)
				std::cout << "\r\033[2K";

				if (key == 27 || key == 8)									// if key press is esc or backspace - exit skills menu
				{
					Helper::ErasePreviousLines(counter - 1);
					std::cout << "\t1. Attack" << std::endl;				// print menu
					std::cout << "\t2. [Skills]" << std::endl;
					std::cout << "\t3. Health Potion" << std::endl;
					break;
				}

				switch (index)
				{
				case BLOCK:	//======================== Raise Shield ========================

					if (stamina >= skills[BLOCK].GetAbilityCost())			// if stamina is greater than or equal to 24
					{
						blocking = true;									// the knight blocks
						Helper::ErasePreviousLines(counter - 1);
						result = "\t::You brace for impact::";
						running = false;
						inMenu = false;
						break;
					}
					else													// else choose from the menu again 
					{
						std::cout << "\r\033[2K";
						result = "\t::\033[31mNot enough stamina!\033[0m::";
						Helper::Type(result, 45);
						continue;
					}
				
				}

			}

		}

		if (key == '3')	//======================== Health Potion ========================
		{
			if (potionCount <= 0)											// if you have no potions left
			{
				result = "\t::\033[31m0 potions left!\033[0m::";
				Helper::Type(result, 45);
				continue;
			}
			else if (GetHealth() >= GetMaxHealth())
			{
				result = "\t::\033[31mHealth is full\033[0m::";
				Helper::Type(result, 45);
				continue;
			}
			else
			{			
				before = GetHealth();
				potionCount = potionCount - 1;								// uses up 1 potion
				Heal(30);													// heals 30 hp
				after = GetHealth();
				total = after - before;

				result = "\t::\033[32mYou Heal for +" + std::to_string(total) + " Health\033[0m (" + std::to_string(potionCount) + " left)::";
				Helper::Type(result, 45);

				std::cout << "\r\033[06A\033[41C\033[32m" << std::setw(3) << std::setfill('0') << GetHealth() << "\033[0m\033[06B" << std::flush;
				continue;
			}
			
		}
		
	}
	
	Helper::Type(result, 45);
	return result;
}


void Knight::TurnOver()
{
	RecoverStamina(10);
}


