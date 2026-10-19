#include "Goblin.h"


Goblin::Goblin(const std::string& _name, int _health, int _attackPower) : 
	Enemy(_name, _health, _attackPower)
{}


void Goblin::PrintStats() const
{
	Art::GoblinIcon();
	std::cout << "\r\033[67C\033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m||\033[0m" << "\r\033[85C\033[38;5;28m" << GetName() << "\r\033[108C" << "\033[31m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m||\033[0m Health: " << "\r\033[100C\033[1;32m" << std::setw(3) << std::setfill('0') << GetHealth() << "/" << std::setw(3) << std::setfill('0') << GetMaxHealth() << "\033[0m\r\033[108C" << "\033[31m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m||\033[0m" << "\033[0m\r\033[108C" << "\033[31m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
}


std::string Goblin::TakeTurn(Character & target)
{
	int damage = Helper::RandomNumberGenerator(1, 10) + GetAttackPower();
	int hitChance = Helper::RandomNumberGenerator(1, 10);			// 10% chance
	int critChance = Helper::RandomNumberGenerator(1, 10);			// 10% chance
	int critDamage = damage * 2;
	int before = 0;
	int after = 0;
	int total = 0;
	std::string broken;
	std::string result;

	if (hitChance != 1)
	{
		if (critChance == 1)										// if crit chance lands on 1 (out of 10)
		{
			before = target.GetHealth();
			broken = target.TakeDmg(critDamage);					// deal twice the normal damage
			after = target.GetHealth();
			total = before - after;

			if (total >= before)									// if overkill
			{
				result = "\r\033[67C::Critical Hit!::"
					"\r\033[2K\033[67C::" + GetName() + " CRACKS you for \033[33m" + std::to_string(critDamage) + " \033[38;5;94mphysical\033[0m damage::";
			}
			else if (total >= critDamage)
			{
				result = "\r\033[67C::Critical Hit!::"
					"\r\033[2K\033[67C::" + GetName() + " CRACKS you for \033[33m" + std::to_string(total) + " \033[38;5;94mphysical\033[0m damage::";
			}
			else
			{
				if (!broken.empty())
				{
					result = "\r\033[67C::" + GetName() + " swings his club in ANGER!::"
						"\r\033[2K\033[67C::But only deals " + std::to_string(total) + " \033[38;5;94mphysical\033[0m damage::" + "\r\033[2K\t::" + GetName() + broken;
				}
				else
				{
					result = "\r\033[67C::" + GetName() + " swings his club in ANGER!::"
						"\r\033[2K\033[67C::But only deals " + std::to_string(total) + " \033[38;5;94mphysical\033[0m damage::";
				}
			}
		}
		else
		{
			before = target.GetHealth();
			broken = target.TakeDmg(damage);						// else do normal damage
			after = target.GetHealth();
			total = before - after;

			if (total >= before)									// if kill
			{
				result = "\r\033[67C::" + GetName() + " hits you for " + std::to_string(damage) + " \033[38;5;94mphysical\033[0m damage::";
			}
			else if (total >= damage)
			{
				result = "\r\033[67C::" + GetName() + " hits you for " + std::to_string(total) + " \033[38;5;94mphysical\033[0m damage::";
			}
			else
			{
				if (!broken.empty())
				{
					result = "\r\033[67C::" + GetName() + " swings wildly::"
						"\r\033[2K\033[67C::But only deals " + std::to_string(total) + " \033[38;5;94mphysical\033[0m damage::" + "\r\033[2K\t::" + GetName() + broken;
				}
				else
				{
					result = "\r\033[67C::" + GetName() + " swings wildly::"
						"\r\033[2K\033[67C::But only deals " + std::to_string(total) + " \033[38;5;94mphysical\033[0m damage::";
				}
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


