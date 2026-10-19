#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Helper.h"
#include "Art.h"
#include "Ability.h"
#include "Menus.h"


class Sorceress : public Hero
{
	int mana;
	int maxMana;
	int potionCount;
	bool shield;
	int shieldCount;
	std::vector<Ability> spellbook;

	enum SpellList
	{
		FIREBALL,
		SHIELD,
		HEAL
	};

public:

	Sorceress(const std::string& _name, int _health, int _attackPower);		// constructor

	void RecoverMana(int amount);											// recover mana method

	void PrintStats(bool art = true) const override;						// overrides
	std::string TakeDmg(float physical, float elemental = 0.0f) override;
	std::string TakeTurn(Character& target) override;
	void TurnOver() override;

};

