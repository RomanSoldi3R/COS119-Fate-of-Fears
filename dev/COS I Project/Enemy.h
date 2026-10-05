#pragma once
#include "Character.h"


class Enemy : public Character
{


public:

	Enemy(const std::string& _name, int _health, int _attackPower);		// constructor

	virtual void TakeTurn(Character& target) = 0;						// pure virtual method makes it so it distinguishes between each enemy's abilities and stops any derived class that doesn't have its own TakeTurn method.
	virtual void TurnOver();											// virtual method so only some enemy types can have special effects

};

