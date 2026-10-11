#include "Ability.h"


Ability::Ability(const std::string& _name, int _cost, int _physical, int _elemental) :
	name(_name),
	cost(_cost),
	physical(_physical),
	elemental(_elemental)
{}

std::string Ability::GetAbilityName() const { return name; }
int Ability::GetAbilityCost() const { return cost; }
int Ability::GetPhysical() const { return physical; }
int Ability::GetElemental() const { return elemental; }


