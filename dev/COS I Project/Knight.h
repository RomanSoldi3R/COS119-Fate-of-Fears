#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include "Helper.h"
#include "Art.h"
#include "Ability.h"


class Knight : public Hero
{
	int stamina;
	bool blocking;
	int potionCount;
	const int blockCost = 24;
	std::vector<Ability> skills;

	enum skillList
	{
		SHIELD
	};

public:

	Knight(const std::string& _name, int _health, int _attackPower);	// constructor

	void RecoverStamina(int amount);									// recover stamina method

	void PrintStats() const override;									// overrides
	void TakeDmg(float physical, float elemental = 0.0f) override;
	std::string TakeTurn(Character& target) override;
	void TurnOver() override;

};

