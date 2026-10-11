#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Helper.h"
#include "Art.h"
#include "Ability.h"


class Sorceress : public Hero
{
	int mana;
	int maxMana;
	bool shield;
	int potionCount;
	const int shieldCost = 50;
	std::vector<Ability> spellbook;

	enum spellList
	{
		FIREBALL,
		SHIELD,
		HEAL
	};

public:

	Sorceress(const std::string& _name, int _health, int _attackPower);		// constructor

	void RecoverMana(int amount);											// recover mana method

	void PrintStats() const override;										// overrides
	void TakeDmg(float physical, float elemental = 0.0f) override;
	std::string TakeTurn(Character& target) override;
	void TurnOver() override;

};

