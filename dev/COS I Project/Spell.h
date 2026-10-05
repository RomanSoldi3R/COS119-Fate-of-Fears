#pragma once
#include <iostream>
#include <string>
#include <vector>


class Spell
{
	std::vector<Spell*> spellBook;

public:

	Spell(const std::string& _name, int _manaCost);

	std::vector<Spell*> GetSpellBook() const;

};

