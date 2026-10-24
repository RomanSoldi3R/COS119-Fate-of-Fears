#include "FinalBoss.h"

FinalBoss::FinalBoss(const std::string& _name, int _health, int _attackPower) :
	Enemy(_name, _health, _attackPower),
	rage(0),
	shield(false),
	shieldCount(0)
{}


void FinalBoss::PrintStats() const
{
	std::cout << "\r\033[5A\033[67C\033[38;5;245m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[38;5;245m||\033[0m" << "\r\033[86C\033[31m" << GetName() << "\r\033[108C" << "\033[38;5;245m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[38;5;245m||\033[0m Health: " << "\r\033[100C\033[1;32m" << std::setw(3) << std::setfill('0') << GetHealth() << "/" << std::setw(3) << std::setfill('0') << GetMaxHealth() << "\033[0m\r\033[108C" << "\033[38;5;245m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[38;5;245m||\033[0m Rage:" << "\r\033[104C\033[31m" << std::setw(2) << std::setfill('0') << rage << "%\033[0m\r\033[108C" << "\033[38;5;245m||\033[0m" << std::endl;
	std::cout << "\r\033[67C\033[38;5;245m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
}


std::string FinalBoss::TakeDmg(float _physical, float _elemental)
{
	std::string result;
	int shieldResistance = rand() % 5;										// 20% chance
	int growingRage = 0;

	if (shield && shieldCount > 0)											// if shielded
	{
		Character::TakeDmg(_physical / 2, _elemental / 2);					// physical damage reduced by 50%, elemental damage reduced by 50%

		if (shieldResistance == 1)
		{
			shield = false;
			rage = rage + (growingRage = Helper::RandomNumberGenerator(20, 30));

			if (rage >= 100)
			{
				rage = 100;
				result = "\033[31m broke " + GetName() + "'s defenses!::"
					"\r\033[2K\t::\033[31m" + GetName() + " is ENRAGED!\033[0m::";
			}
			else
			{
				result = "\033[31m broke " + GetName() + "'s defenses!::"
					"\r\033[2K\t::" + GetName() + "'s rage grows \033[31m" + std::to_string(growingRage) + "%\033[0m::";
			}
		}
	}
	else
	{
		Character::TakeDmg(_physical * 1.25, _elemental);					// else if not shielded, take %25 more physical damage + elemental
	}
	return result;
}


std::string FinalBoss::TakeTurn(Character& target)
{
	int damage = Helper::RandomNumberGenerator(1, 10) + GetAttackPower();
	int shieldChance = Helper::RandomNumberGenerator(1, 3);					// 33% chance
	int hitChance = Helper::RandomNumberGenerator(1, 10);					// 10% chance
	int critChance = Helper::RandomNumberGenerator(1, 10);					// 10% chance
	int critDamage = damage * 2;
	int before = 0;
	int after = 0;
	int total = 0;
	std::string broken;
	std::string result;

	if (rage < 100 && shieldCount <= 0 && shieldChance == 1)
	{
		shieldCount = 1;

		shield = true;														// shield is up 
		result = "\r\033[67C::" + GetName() + " casts Barrier::";
	}
	else if (hitChance != 1)
	{
		if (critChance == 1)												// if crit chance lands on 1 (out of 10)
		{
			if (rage >= 100)		//======================== 100% Rage + Crits ========================
			{
				before = target.GetHealth();
				broken = target.TakeDmg(critDamage, critDamage);			// deal twice the physical and elemental damage
				after = target.GetHealth();
				total = before - after;
				rage = 0;

				if (total >= before)										// if overkill, print normal High Damage
				{
					result = "\r\033[67C::Critical Hit!::"
						"\r\033[2K\033[67C::" + GetName() + " lands a METEOR STRIKE for \033[33m" + std::to_string(critDamage) + " \033[38;5;94mphysical\033[0m and\033[31m fire\033[0m damage!::";
				}
				else if (total >= critDamage * 2)							// if crit, print total damage
				{
					result = "\r\033[67C::Critical Hit!::"
						"\r\033[2K\033[67C::" + GetName() + " lands a METEOR STRIKE for  \033[33m" + std::to_string(total) + " \033[38;5;94mphysical\033[0m and\033[31m fire\033[0m damage!::";
				}
				else
				{
					if (!broken.empty())									// if breaks player's shields that reduces their resource to 0, print that out
					{
						result = "\r\033[67C::" + GetName() + " lands a METEOR STRIKE!::"
							"\r\033[2K\033[67C::But only deals " + std::to_string(total) + " \033[38;5;94mphysical\033[0m and\033[31m fire\033[0m damage" + "\r\033[2K\t::" + GetName() + broken;
					}
					else													// else hits player's shields, print reduced damage
					{
						result = "\r\033[67C::" + GetName() + " lands a METEOR STRIKE!::"
							"\r\033[2K\033[67C::But only deals " + std::to_string(total) + " \033[38;5;94mphysical\033[0m and\033[31m fire\033[0m damage::";
					}
				}
			}
			else		//======================== Crits ========================
			{
				before = target.GetHealth();
				broken = target.TakeDmg(critDamage);						// deal twice the damage
				after = target.GetHealth();
				total = before - after;

				if (total >= before)										// if overkill
				{
					result = "\r\033[67C::Critical Hit!::"
						"\r\033[2K\033[67C::" + GetName() + " lands a CRUSHING BLOW for \033[33m" + std::to_string(critDamage) + " \033[38;5;94mphysical\033[0m damage::";
				}
				else if (total >= critDamage)
				{
					result = "\r\033[67C::Critical Hit!::"
						"\r\033[2K\033[67C::" + GetName() + " lands a CRUSHING BLOW for \033[33m" + std::to_string(total) + " \033[38;5;94mphysical\033[0m damage::";
				}
				else
				{
					if (!broken.empty())
					{
						result = "\r\033[67C::" + GetName() + " lands a CRUSHING BLOW!::"
							"\r\033[2K\033[67C::But only deals " + std::to_string(total) + " \033[38;5;94mphysical\033[0m damage::" + "\r\033[2K\t::" + GetName() + broken;
					}
					else
					{
						result = "\r\033[67C::" + GetName() + " lands a CRUSHING BLOW!::"
							"\r\033[2K\033[67C::But only deals " + std::to_string(total) + " \033[38;5;94mphysical\033[0m damage::";
					}
				}
			}
		}
		else		//======================== 100% Rage + Normal Damage ========================
		{
			if (rage >= 100)
			{
				before = target.GetHealth();
				broken = target.TakeDmg(damage, damage);					// deals physical and elemental damage
				after = target.GetHealth();
				total = before - after;
				rage = 0;

				if (total >= before)										// if kill
				{
					result = "\r\033[67C::" + GetName() + " CRUSHES you for " + std::to_string(damage) + " \033[38;5;94mphysical\033[0m and\033[31m fire\033[0m damage!::";
				}
				else if (total >= damage * 2)
				{
					result = "\r\033[67C::" + GetName() + " CRUSHES you for " + std::to_string(total) + " \033[38;5;94mphysical\033[0m and\033[31m fire\033[0m damage!::";
				}
				else
				{
					if (!broken.empty())
					{
						result = "\r\033[67C::" + GetName() + " swings with rage::"
							"\r\033[2K\033[67C::But only deals " + std::to_string(total) + " \033[38;5;94mphysical\033[0m and\033[31m fire\033[0m damage!::" + "\r\033[2K\t::" + GetName() + broken;
					}
					else
					{
						result = "\r\033[67C::" + GetName() + " swings with rage::"
							"\r\033[2K\033[67C::But only deals " + std::to_string(total) + " \033[38;5;94mphysical\033[0m and\033[31m fire\033[0m damage!::";
					}
				}
			}
			else		//======================== Normal Damage ========================
			{
				before = target.GetHealth();
				broken = target.TakeDmg(damage);							// else do normal damage
				after = target.GetHealth();
				total = before - after;

				if (total >= before)										// if kill
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
	}
	else		//======================== Misses ========================
	{
		result = "\r\033[67C::" + GetName() + " misses::";
	}

	Helper::Type(result, 45);
	return result;
}


void FinalBoss::TurnOver()
{
	std::string result;
	int growingRage = 0;

	rage = rage + (growingRage = Helper::RandomNumberGenerator(20, 30));
	Helper::ErasePreviousLines(4);

	if (rage >= 100)
	{
		rage = 100;
		std::cout << "\r\033[2K";
		result = "\r\033[67C::\033[31m" + GetName() + " is ENRAGED!\033[0m::\n";
	}
	else
	{
		std::cout << "\r\033[2K";
		result = "\r\033[67C::" + GetName() + "'s rage grows... \033[31m +" + std::to_string(growingRage) + "%\033[0m::\n";
	}
	if (shield)
	{
		shieldCount++;
	}
	if (shieldCount > 4)
	{
		shield = false;
		shieldCount = 0;
		std::cout << "\r\033[2K";
		result = "\r\033[67C::\033[31m" + GetName() + "'s barrier wore off\033[0m::\n";
	}
	Helper::Type(result, 45);
	Helper::Pause();
}
