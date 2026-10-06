#pragma once
#include "Enemy.h"


class Goblin : public Enemy
{

public:

	Goblin(const std::string& _name, int _health, int _attackPower);
	
	void TakeTurn(Character& target) override;							// overrides

};

