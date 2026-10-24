#pragma once
#include "Enemy.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "Helper.h"
#include "Art.h"


class FinalBoss : public Enemy
{
	int rage;
	bool shield;
	int shieldCount;

public:

	FinalBoss(const std::string& _name, int _health, int _attackPower);

	void PrintStats() const override;											// overrides
	std::string TakeDmg(float physical, float elemental = 0.0f) override;
	std::string TakeTurn(Character& target) override;
	void TurnOver() override;

};

