#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Helper.h"
#include "Art.h"


class Knight : public Hero
{
	int stamina;
	bool blocking;
	int potionCount;

public:

	Knight(const std::string& _name, int _health, int _attackPower);	// constructor

	void RecoverStamina(int amount);									// recover stamina method

	void PrintStats() const override;									// overrides
	void TakeDmg(int dmg) override;
	std::string TakeTurn(Character& target) override;
	void TurnOver() override;

};

