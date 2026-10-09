#pragma once
#include "Enemy.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Helper.h"
#include "Art.h"


class Goblin : public Enemy
{

public:

	Goblin(const std::string& _name, int _health, int _attackPower);
	
	void PrintStats() const override;									// overrides
	std::string TakeTurn(Character& target) override;

};

