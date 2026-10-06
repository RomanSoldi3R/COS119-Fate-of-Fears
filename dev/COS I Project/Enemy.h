#pragma once
#include "Character.h"


class Enemy : public Character
{


public:

	Enemy(const std::string& _name, int _health, int _attackPower);		// constructor

	virtual void TurnOver();											// virtual method so only some enemy types can have special effects

};

