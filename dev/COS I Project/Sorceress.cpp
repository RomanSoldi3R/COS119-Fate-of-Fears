#include "Sorceress.h"


Sorceress::Sorceress(const std::string& _name, int _health, int _attackPower) :
	Hero(_name, _health, _attackPower),
	mana(200),
	maxMana(200),
	shield(false),
	potionCount(5),
	spellbook{
		Ability("Fireball", 30, 0, 35),
		Ability("Mana Shield", shieldCost),
		Ability("Heal", 50) }
{}

void Sorceress::RecoverMana(int amount)
{
	if (amount <= 0)
	{
		amount = 0;
	}
	mana = mana + amount;
	if (mana >= maxMana)
	{
		mana = maxMana;
	}
}

// ============================== Overrides ==============================

void Sorceress::PrintStats() const
{
	std::cout << "\r\033[8C\033[35m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
	std::cout << "\r\033[8C\033[35m||\033[0m\r\033[27C" << GetName() << "\r\033[49C\033[35m||\033[0m" << std::endl;
	std::cout << "\r\033[8C\033[35m||\033[0m Health: \r\033[41C\033[32m" << std::setw(3) << std::setfill('0') << GetHealth() << "/" << GetMaxHealth() << "\033[0m\r\033[49C\033[35m||\033[0m" << std::endl;
	std::cout << "\r\033[8C\033[35m||\033[0m Mana: \r\033[41C\033[35m" << std::setw(3) << std::setfill('0') << mana << "/" << maxMana << "\033[0m\r\033[49C\033[35m || \033[0m" << std::endl;
	std::cout << "\r\033[8C\033[35m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
}

void Sorceress::TakeDmg(float physical, float elemental)
{
	if (shield)																// if shielded
	{
		Character::TakeDmg(physical / 1.11);								// physical damage taken is reduced by 10%
		Character::TakeDmg(elemental / 10);									// elemental damage taken is reduced by 90%

		if (mana <= shieldCost)												// if current mana is less than or equal to shield cost
		{
			mana = 0;														// set mana to 0
			shield = false;													// breaks the shield
		}
		else
		{
			mana = mana - shieldCost;										// else lose shield cost
		}
	}
	else
	{
		Character::TakeDmg(physical * 1.25);								// else if not shielded, take 25% more physical damage
		Character::TakeDmg(elemental * 1.25);								// and take 25% more elemental damage
	}
}

std::string Sorceress::TakeTurn(Character& target)
{
	std::cout << "1. Attack" << std::endl;									// print menu
	std::cout << "2. Spellbook" << std::endl;
	std::cout << "3. Mana Potion" << std::endl;
	
	bool inMenu = true;														// variables
	int damage = rand() % 11 + GetAttackPower();
	int hitChance = rand() % 10;											// 10% chance
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
			if (hitChance != 1)												// chance to miss
			{
				if (critChance == 1)										// chance to crit
				{
					before = target.GetHealth();
					target.TakeDmg(0, critDamage);							// deal twice the normal damage
					after = target.GetHealth();
					total = before - after;

					if (total == critDamage || total >= before)
					{
						result = "\t::Critical Hit!::"
							"\r\033[2K\t::Your wand WHIRLS a precise spell for \033[33m" + std::to_string(critDamage) + "\033[0m damage!::";
					}
					else
					{
						result = "\t::Your wand WHIRLS a spell forward::"
							"\r\033[2K\t::But you only deal " + std::to_string(total) + " damage::";
					}
				}
				else
				{
					before = target.GetHealth();
					target.TakeDmg(0, damage);								// else do normal damage
					after = target.GetHealth();
					total = before - after;

					if (total == damage || total >= before)
					{
						result = "\t::You cast a spell from your wand for " + std::to_string(damage) + " damage::";
					}
					else
					{
						result = "\t::You cast a spell from your wand::"
							"\r\033[2K\t::But you only deal " + std::to_string(total) + " damage::";
					}
				}
			}
			else
			{
				result = "\t::You missed::";
			}
			break;
		}

		if (key == '2')							// spells
		{
			inMenu = true;

			while (inMenu)
			{
				Helper::ErasePreviousLines(3);

				

				int key = _getch();
				std::cout << "\r\033[2K";








				if (key == 2)
				{
					if (mana >= shieldCost)										// if mana is greater than or equal to shield cost
					{
						shield = true;											// shield is up 
						result = "\t::You conjure a mana shield::";
						break;
					}
					else
					{
						std::cout << "\r\033[2K";
						result = "\t::\033[31mNot enough mana!\033[0m::";		// else choose from the menu again 
						continue;
					}
				}






			}
		}

		if (key == '3')							// Use mana potion
		{
			if (potionCount <= 0)											// if you have no potions left
			{
				std::cout << "\r\033[2K";
				result = "\t::\033[31m0 potions left!\033[0m::";
				Helper::Type(result, 45);
				continue;
			}
			else if (mana >= maxMana)
			{
				std::cout << "\r\033[2K";
				result = "\t::\033[31mMana is full\033[0m::";
				Helper::Type(result, 45);
				continue;
			}
			else
			{
				before = mana;
				potionCount = potionCount - 1;								// uses up 1 potion
				RecoverMana(50);											// recovers 50 mana
				after = mana;
				total = after - before;

				std::cout << "\r\033[2K";
				result = "\t::\033[34m+" + std::to_string(total) + " Mana\033[0m (" + std::to_string(potionCount) + " left)::";
				Helper::Type(result, 45);

				std::cout << "\r\033[06A\033[41C\033[32m" << mana << "\033[0m\033[06B";
				continue;
			}

		}

	}
	Helper::ErasePreviousLines(3);
	Helper::Type(result, 45);
	return result;
}

void Sorceress::TurnOver()
{
	RecoverMana(15);
}




