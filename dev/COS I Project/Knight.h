#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Helper.h"
#include "Art.h"
#include "Ability.h"
#include "Menus.h"


class Knight : public Hero
{
	int stamina;
	int maxStamina;
	int staminaCount;
	int potionCount;
	bool blocking;
	std::vector<Ability> skills;

	enum SkillList
	{
		BLOCK
	};

public:

	Knight(const std::string& _name, int _health, int _attackPower);		// constructor

	void RecoverStamina(int amount);										// recover stamina method

	void PrintStats(bool art = true) const override;						// overrides
	std::string TakeDmg(float _physical, float _elemental = 0.0f) override;
	std::string TakeTurn(Character& target) override;
	void TurnOver() override;
	
};

