#pragma once
#include <iostream>
#include <string>


class Character
{
	std::string name;							// private member variables
	int health;
	int maxHealth;
	int attackPower;

public:

	Character(const std::string& _name, int _health, int _attackPower);		// constructor

	virtual void TakeDmg(int dmg);				// method to control the private variable "health" when a character takes damage
	virtual void PrintStats() const;			// method to print stats

	void Heal(int heal);						// method to control the private variable "health" when a character heals

	bool IsAlive() const;						// method to check the status of the character

	std::string GetName() const;				// getters
	int GetHealth() const;
	int GetMaxHealth() const;
	int GetAttackPower() const;

	virtual ~Character();						// virtual destructor so when my Hero* gets destroyed, it runs from knight/sorcerer -> hero -> character. Without virtual it would start at hero, skipping knight/sorcerer.

};

