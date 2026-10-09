#include "Goblin.h"


Goblin::Goblin(const std::string& _name, int _health, int _attackPower) : 
	Enemy(_name, _health, _attackPower)
{}

void Goblin::PrintStats() const
{
	std::cout << "\r\033[5A\033[67C\033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m||\033[0m" << "\r\033[83C" << GetName() << "\r\033[108C" << "\033[31m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m||\033[0m Health: " << "\r\033[100C\033[32m" << std::setw(3) << std::setfill('0') << GetHealth() << "/" << std::setw(3) << std::setfill('0') << GetMaxHealth() << "\033[0m\r\033[108C" << "\033[31m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m||\033[0m" << "\033[0m\r\033[108C" << "\033[31m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
}

std::string Goblin::TakeTurn(Character & target)
{
	int damage = rand() % 11 + GetAttackPower();					// variables
	int hitChance = rand() % 10;									// 10% chance
	int critChance = rand() % 10;									// 10% chance
	int critDamage = damage * 2;
	int before = 0;
	int after = 0;
	int total = 0;
	std::string result;

	if (hitChance != 1)
	{
		if (critChance == 1)										// if crit chance lands on 1 (out of 10)
		{
			before = target.GetHealth();
			target.TakeDmg(critDamage);								// deal twice the normal damage
			after = target.GetHealth();
			total = before - after;

			if (total >= before)									// if overkill
			{
				result = "\r\033[67C::Critical Hit!::"
					"\r\033[2K\033[67C::" + GetName() + " CRACKS you for \033[33m" + std::to_string(critDamage) + "\033[0m damage!::"
					"\r\033[2K\033[67C::OVERKILL!::";
			}
			else
			{
				result = "\r\033[67C::Critical Hit!::"
					"\r\033[2K\033[67C::" + GetName() + " CRACKS you for \033[33m" + std::to_string(total) + "\033[0m damage!::";
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
				result = "\r\033[67C::" + GetName() + " hits you for " + std::to_string(damage) + " damage::"
				"\r\033[2K\t::" + GetName() + " killed you!::";
			}
			else
			{
				result = "\r\033[67C::" + GetName() + " hits you for " + std::to_string(total) + " damage::";
			}
		}
	}
	else
	{
		result = "\r\033[67C::" + GetName() + " misses::";
	}

	Helper::Type(result, 45);
	return result;
}


