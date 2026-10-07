#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Helper.h"


class Knight : public Hero
{
	int stamina;
	bool blocking;
	int potionCount;

public:

	Knight(const std::string& _name, int _health, int _attackPower);	// constructor

	void RecoverStamina(int amount);									// recover stamina method

	void TakeDmg(int dmg) override;										// overrides
	void PrintStats() const override;
	void TakeTurn(Character& target) override;
	void TurnOver() override;

};

