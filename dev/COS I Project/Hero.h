#pragma once
#include "Character.h"
#include <iostream>
#include <string>


class Hero : public Character 
{

public:

	Hero(const std::string& _name, int _health, int _attackPower);		// constructor

	virtual void TurnOver() = 0;										// pure virtual method to end the turn for a knight/sorcerer

};

