#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
#include <vector>


class Sorcerer : public Hero
{
	int mana = 100;
	int potionCount;

public:

	Sorcerer(const std::string& _name, int _health, int _attackPower);		// constructor

	void RecoverMana(int amount);											// recover mana method

	void TakeDmg(int dmg) override;											// overrides
	void PrintStats() const override;
	void TakeTurn(Character& target) override;
	void TurnOver() override;

};

