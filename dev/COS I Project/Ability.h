#pragma once
#include <string>


class Ability
{
	std::string name;
	int cost;
	int physical;
	int elemental;

public:

	Ability(const std::string& _name, int _cost, int _physical = 0, int _elemental = 0);

	std::string GetAbilityName() const;
	int GetAbilityCost() const;
	int GetPhysical() const;
	int GetElemental() const;

};

