#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "Helper.h"
#include "Art.h"


class Sorceress : public Hero
{
	int mana = 100;
	bool shield;
	int potionCount;

public:

	Sorceress(const std::string& _name, int _health, int _attackPower);		// constructor

	void RecoverMana(int amount);											// recover mana method

	void PrintStats() const override;										// overrides
	void TakeDmg(int dmg) override;
	std::string TakeTurn(Character& target) override;
	void TurnOver() override;

};

