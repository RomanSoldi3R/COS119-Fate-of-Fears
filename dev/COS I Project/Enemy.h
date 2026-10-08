#pragma once
#include "Character.h"
#include <iostream>
#include <string>


class Enemy : public Character
{


public:

	Enemy(const std::string& _name, int _health, int _attackPower);		// constructor

	virtual void PrintStats() const = 0;								// pure virtual method to print stats
	virtual std::string TakeTurn(Character& target) = 0;				// pure virtual method makes it so it distinguishes between each units abilities and stops any derived class that doesn't have its own TakeTurn method.
	virtual void TurnOver();											// virtual method so only some enemy types can have special effects

};

