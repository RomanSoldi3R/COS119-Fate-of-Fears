#pragma once
#include "Character.h"
#include <iostream>
#include <string>


class Hero : public Character 
{

public:

	Hero(const std::string& _name, int _health, int _attackPower);		// constructor

	virtual void PrintStats() const = 0;								// pure virtual method to print stats
	virtual std::string TakeTurn(Character& target) = 0;				// pure virtual method makes it so it distinguishes between each units abilities and stops any derived class that doesn't have its own TakeTurn method.
	virtual void TurnOver() = 0;										// pure virtual method to end the turn for a knight/sorcerer

};

