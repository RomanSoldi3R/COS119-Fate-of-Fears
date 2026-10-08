#pragma once
#include <iostream>
#include <string>
 

class Character
{
	std::string name;									// private member variables
	int health;
	int maxHealth;
	int attackPower;

public:

	Character(const std::string& _name, int _health, int _attackPower);		// constructor

	virtual void TakeDmg(int dmg);						// method to control the private variable "health" when a character takes damage

	void Heal(int heal);								// method to control the private variable "health" when a character heals
	bool IsAlive() const;								// method to check the status of the character

	std::string GetName() const;						// getters
	int GetHealth() const;
	int GetMaxHealth() const;
	int GetAttackPower() const;

	virtual ~Character();								// virtual destructor so when my pointers get destroyed, it runs from the current object back to -> character. Without virtual it would start at hero/enemy, skipping the other classes.

};

