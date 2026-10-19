#include "Sorceress.h"


Sorceress::Sorceress(const std::string& _name, int _health, int _attackPower) :
	Hero(_name, _health, _attackPower),
	mana(200),
	maxMana(200),
	potionCount(5),
	shield(false),
	shieldCount(0),
	spellbook{
		Ability("Fireball", 24, 0, 45),
		Ability("Mana Shield", 20),
		Ability("Heal", 32) }
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

void Sorceress::PrintStats(bool art) const
{
	if (art == false)
	{
		std::cout << "\r\033[8C\033[35m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
		std::cout << "\r\033[8C\033[35m||\033[0m\r\033[25C\033[35m" << GetName() << "\r\033[49C\033[35m||\033[0m" << std::endl;
		std::cout << "\r\033[8C\033[35m||\033[0m Health: \r\033[41C\033[1;32m" << std::setw(3) << std::setfill('0') << GetHealth() << "/" << GetMaxHealth() << "\033[0m\r\033[49C\033[35m||\033[0m" << std::endl;
		std::cout << "\r\033[8C\033[35m||\033[0m Mana: \r\033[41C\033[1;35m" << std::setw(3) << std::setfill('0') << mana << "/" << maxMana << "\033[0m\r\033[48C\033[35m || \033[0m" << std::endl;
		std::cout << "\r\033[8C\033[35m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
	}
	else
	{
		Art::SorceressIcon();
		std::cout << "\r\033[8C\033[35m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
		std::cout << "\r\033[8C\033[35m||\033[0m\r\033[25C\033[35m" << GetName() << "\r\033[49C\033[35m||\033[0m" << std::endl;
		std::cout << "\r\033[8C\033[35m||\033[0m Health: \r\033[41C\033[1;32m" << std::setw(3) << std::setfill('0') << GetHealth() << "/" << GetMaxHealth() << "\033[0m\r\033[49C\033[35m||\033[0m" << std::endl;
		std::cout << "\r\033[8C\033[35m||\033[0m Mana: \r\033[41C\033[1;35m" << std::setw(3) << std::setfill('0') << mana << "/" << maxMana << "\033[0m\r\033[48C\033[35m || \033[0m" << std::endl;
		std::cout << "\r\033[8C\033[35m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
	}
}


std::string Sorceress::TakeDmg(float _physical, float _elemental)
{
	std::string result;
	int shieldResistance = rand() % 5;										// 20% chance

	if (shield && shieldCount > 0)											// if shielded
	{	
		float elemental = _elemental;

		Character::TakeDmg(_physical / 1.11);								// physical damage taken is reduced by 10%
		Character::TakeDmg(0, elemental = elemental / 5);					// elemental damage taken is reduced by 80%

		if (shieldResistance != 1)
		{
			if (mana <= _elemental / 2.5)									// if current mana is less than or equal to both dmg types
			{
				mana = 0;													// set mana to 0
				shield = false;												// breaks the shield
				result = "\033[31m destroys your mana shield!\033[0m::";
			}
			else
			{
				int total = (_elemental / 2.5);
				mana = mana - total;										// else lose mana based off %40 of the elemental damage taken
				result = " hits you through your shield::"
					"\r\033[2K\t::\033[31mYou lose " + std::to_string(total) + " mana\033[0m::";
			}
		}
		else
		{
			shield = false;
			result = "\033[31m disrupts your mana shield!\033[0m::";
		}
	}
	else
	{
		Character::TakeDmg(_physical * 1.25);								// else if not shielded, take 25% more physical damage
		Character::TakeDmg(0, _elemental * 1.25);							// and take 25% more elemental damage
	}
	return result;
}


std::string Sorceress::TakeTurn(Character& target)
{
	std::cout << "\t1. Attack" << std::endl;								// print menu
	std::cout << "\t2. [Spell Book]" << std::endl;
	std::cout << "\t3. Mana Potion" << "\r\033[23C{" << potionCount << "}" << std::endl;
	std::cout << "\t4. Flee" << std::endl;
	
	bool running = true;													// variables
	bool inMenu = true;
	int damage = Helper::RandomNumberGenerator(1,10) + GetAttackPower();
	int hitChance = Helper::RandomNumberGenerator(1, 10);					// 10% chance
	int critChance = Helper::RandomNumberGenerator(1, 10);					// 10% chance
	int critDamage = damage * 2;
	int flee = Helper::RandomNumberGenerator(1, 3);							// 50% chance
	int before = 0;
	int after = 0;
	int total = 0;
	int esc = 27;
	std::string result;

	while (running)															// start of the loop
	{
		int key = _getch();
		std::cout << "\r\033[2K";

		if (key == '1')	//======================== Attack ========================
		{
			Helper::ErasePreviousLines(4);

			if (hitChance != 1)												// chance to miss
			{
				if (critChance == 1)										// chance to crit
				{
					before = target.GetHealth();
					target.TakeDmg(0, critDamage);							// deal twice the normal damage
					after = target.GetHealth();
					total = before - after;

					if (total >= before)
					{
						result = "\t::Critical Hit!::"
							"\r\033[2K\t::You WHIRL a PRECISE spell for \033[33m" + std::to_string(critDamage) + " \033[35mmagic\033[0m damage!::";
					}
					else if (total >= critDamage)
					{
						result = "\t::Critical Hit!::"
							"\r\033[2K\t::You WHIRL a PRECISE spell for \033[33m" + std::to_string(total) + " \033[35mmagic\033[0m damage!::";
					}
					else
					{
						result = "\t::You WHIRL a spell forward::"
							"\r\033[2K\t::But only deals " + std::to_string(total) + " \033[35mmagic\033[0m damage::";
					}
				}
				else
				{
					before = target.GetHealth();
					target.TakeDmg(0, damage);								// else do normal damage
					after = target.GetHealth();
					total = before - after;

					if (total >= before)
					{
						result = "\t::You shoot your wand for " + std::to_string(damage) + " \033[35mmagic\033[0m damage::";
					}
					else if (total >= damage)
					{
						result = "\t::You shoot your wand for " + std::to_string(total) + " \033[35mmagic\033[0m damage::";
					}
					else
					{
						result = "\t::You whip a spell from your wand::"
							"\r\033[2K\t::But only deals " + std::to_string(total) + " \033[35mmagic\033[0m damage::";
					}
				}
			}
			else
			{
				result = "\t::You missed::";
			}
			break;
		}

		if (key == '2')	//======================== [Spell Book] ========================
		{
			Helper::ErasePreviousLines(4);

			int counter = 1;

			for (const Ability& ability : spellbook)
			{
				std::cout << "\t" << counter++ << ". " << ability.GetAbilityName() << "\r\033[40CCost: \033[1;35m" << std::setw(2) << std::setfill('0') << ability.GetAbilityCost() << "\033[0m" << std::endl;
			}

			inMenu = true;

			while (inMenu)
			{
				int key = _getch();
				int index = key - '0' - 1;									// turns the key press into the index position: key '1'(ascii value 49) - '0'(ascii value 48) - 1 = 0(index position)
				std::cout << "\r\033[2K";

				if (key == 8)												// if key press is backspace - exit skills menu
				{
					Helper::ErasePreviousLines(counter - 1);
					std::cout << "\t1. Attack" << std::endl;				// print menu
					std::cout << "\t2. [Spell Book]" << std::endl;
					std::cout << "\t3. Mana Potion" << "\r\033[23C{" << potionCount << "}" << std::endl;
					std::cout << "\t4. Flee" << std::endl;
					break;
				}

				switch (index)
				{
				case FIREBALL:	//======================== Fireball ========================
					
					if (mana < spellbook[FIREBALL].GetAbilityCost())					// if you have no mana
					{
						std::cout << "\r\033[2K";
						result = "\t::\033[31mNot enough mana!\033[0m::";
						Helper::Type(result, 45);
						continue;
					}
					else
					{
						Helper::ErasePreviousLines(counter - 1);
						mana = mana - spellbook[FIREBALL].GetAbilityCost();

						if (hitChance != 1)												// chance to miss
						{
							damage = Helper::RandomNumberGenerator(1, 10) + spellbook[FIREBALL].GetElemental();
							critDamage = damage * 2;

							if (critChance == 1)										// chance to crit
							{
								before = target.GetHealth();
								target.TakeDmg(0, critDamage);							// deal twice the normal damage
								after = target.GetHealth();
								total = before - after;

								if (total >= before)
								{
									result = "\t::Critical Hit!::"
										"\r\033[2K\t::You UNLEASH a MASSIVE Fireball for \033[33m" + std::to_string(critDamage) + " \033[31mfire\033[0m damage!::";
								}
								else if (total >= critDamage)
								{
									result = "\t::Critical Hit!::"
										"\r\033[2K\t::You UNLEASH a MASSIVE Fireball for \033[33m" + std::to_string(total) + " \033[31mfire\033[0m damage!::";
								}
								else
								{
									result = "\t::You UNLEASH a MASSIVE Fireball::"
										"\r\033[2K\t::But only deals " + std::to_string(total) + " \033[31mfire\033[0m damage::";
								}
							}
							else
							{
								before = target.GetHealth();
								target.TakeDmg(0, damage);								// else do normal damage
								after = target.GetHealth();
								total = before - after;

								if (total >= before)
								{
									result = "\t::You cast a Fireball for " + std::to_string(damage) + " \033[31mfire\033[0m damage::";
								}
								else if (total >= damage)
								{
									result = "\t::You cast a Fireball for " + std::to_string(total) + " \033[31mfire\033[0m damage::";
								}
								else
								{
									result = "\t::You cast a Fireball::"
										"\r\033[2K\t::But only deals " + std::to_string(total) + " \033[31mfire\033[0m damage::";
								}
							}
						}
						else
						{
							result = "\t::You missed::";
						}
					}
					running = false;
					inMenu = false;
					break;

				case SHIELD:	//======================== Mana Shield ========================

					if (mana < spellbook[SHIELD].GetAbilityCost())			// if mana is greater than or equal to shield cost
					{
						std::cout << "\r\033[2K";
						result = "\t::\033[31mNot enough mana!\033[0m::";
						Helper::Type(result, 45);
						continue;
					}
					else													// else choose from the menu again 
					{
						Helper::ErasePreviousLines(counter - 1);
						mana = mana - spellbook[SHIELD].GetAbilityCost();
						
						shieldCount = 1;

						shield = true;										// shield is up 
						result = "\t::You cast \033[1;35mMana Shield\033[0m::";
						running = false;
						inMenu = false;
						break;
					}

				case HEAL:	//======================== Heal ========================

					if (mana < spellbook[HEAL].GetAbilityCost())			// if you have no mana
					{
						std::cout << "\r\033[2K";
						result = "\t::\033[31mNot enough mana!\033[0m::";
						Helper::Type(result, 45);
						continue;
					}
					else if (GetHealth() >= GetMaxHealth())
					{
						std::cout << "\r\033[2K";
						result = "\t::\033[31mHealth is full\033[0m::";
						Helper::Type(result, 45);
						continue;
					}
					else
					{
						mana = mana - spellbook[HEAL].GetAbilityCost();		// uses mana up

						before = GetHealth();
						Heal(Helper::RandomNumberGenerator(1, 40) + 25);	// heals 25 + (1 out 0f 40)
						after = GetHealth();
						total = after - before;

						Helper::ErasePreviousLines(counter - 1);
						result = "\t::You cast Heal for \033[1;32m+" + std::to_string(total) + " Health\033[0m::";
						running = false;
						inMenu = false;
						break;
					}

				}

			}

		}

		if (key == '3')	//======================== Mana potion ========================
		{
			if (potionCount <= 0)											// if you have no potions left
			{
				potionCount = 0;
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
				result = "\t::You restore \033[1;35m+" + std::to_string(total) + " Mana\033[0m::";
				Helper::Type(result, 45);

				std::cout << "\r\033[2A\033[23C{" << potionCount << "}\033[2B" << std::endl;
				std::cout << "\r\033[07A\033[41C\033[1;35m" << std::setw(3) << std::setfill('0') << mana << "\033[0m\033[06B" << std::flush;
				continue;
			}

		}

		if (key == '4')	//======================== Flee ========================
		{
			Helper::ErasePreviousLines(4);

			if (flee == 1)
			{
				std::cout << "\r\033[2K";
				result = "\t::You fled the battle!::";
				break;
			}
			else
			{
				std::cout << "\r\033[2K";
				result = "\t::You failed to flee::";
				break;
			}

		}

	}
	Helper::Type(result, 45);
	return result;
}


void Sorceress::TurnOver()
{
	if (mana != maxMana)
	{
		int before = mana;
		RecoverMana(Helper::RandomNumberGenerator(1,5) + 5);
		int after = mana;
		int total = after - before;

		std::cout << "\r\033[2K";
		Helper::ErasePreviousLines(4);
		Helper::Type("\t::You recovered \033[1;35m+" + std::to_string(total) + " mana\033[0m::", 45);
		Helper::Pause();
	}
	if (shield)
	{
		shieldCount++;
	}
	if (shieldCount > 3)
	{
		shield = false;
		shieldCount = 0;
		std::cout << "\r\033[2K";
		Helper::ErasePreviousLines(3);
		Helper::Type("\t::\033[31mMana shield wore off\033[0m::", 45);
		Helper::Pause();
	}
}




