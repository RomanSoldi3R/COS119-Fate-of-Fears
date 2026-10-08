#include "Goblin.h"


Goblin::Goblin(const std::string& _name, int _health, int _attackPower) : 
	Enemy(_name, _health, _attackPower)
{}

void Goblin::PrintStats() const
{
	Art::GoblinArt();
	std::cout << "\r\033[5A\033[67C\033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m||\033[0m" << "\r\033[84C" << GetName() << "\r\033[108C" << "\033[31m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m||\033[0m Health: " << "\r\033[100C\033[32m" << GetHealth() << "/" << GetMaxHealth() << "\033[0m\r\033[108C" << "\033[31m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m||\033[0m" << "\033[0m\r\033[108C" << "\033[31m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
}

std::string Goblin::TakeTurn(Character & target)
{
	int damage = rand() % 11 + GetAttackPower();							// variables
	int critChance = rand() % 10;
	int critDamage = damage * 2;
	int before = 0;
	int after = 0;
	int finalResult = 0;
	std::string result;

	if (critChance == 1)											// if crit chance lands on 1 (out of 10)
	{
		before = target.GetHealth();
		target.TakeDmg(critDamage);									// deal twice the normal damage
		after = target.GetHealth();
		finalResult = before - after;

		result = "::Critical Hit! " + GetName() + "'s club hits for \033[33m" + std::to_string(finalResult) + "\033[0m!::";
	}
	else
	{
		before = target.GetHealth();
		target.TakeDmg(damage);										// else do normal damage
		after = target.GetHealth();
		finalResult = before - after;

		result = "::" + GetName() + "'s club hits " + target.GetName() + " for " + std::to_string(finalResult) + "::";
	}

	return result;
}


