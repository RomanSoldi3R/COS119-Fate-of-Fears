#include "Character.h"


Character::Character(const std::string& _name, int _health, int _attackPower) :
	name(_name),
	health(_health),
	maxHealth(_health),
	attackPower(_attackPower)
{}

void Character::TakeDmg(float physical, float elemental)
{
	if (physical <= 0)				// if physical damage taken is less than or equal to 0
	{
		physical = 0;				// damage taken gets set to 0
	}
	health = health - physical;		// physical damage taken is stored in health
	
	if (elemental <= 0)				// if elemental damage taken is less than or equal to 0
	{
		elemental = 0;				// damage taken gets set to 0
	}
	health = health - elemental;	// elemental damage taken is stored in health
	
	if (health < 0)					// if health is less than 0 after the damage taken
	{
		health = 0;					// health gets set to 0
	}
}

void Character::Heal(int heal)
{
	if (heal <= 0)					// if healing amount is less than or equal to 0
	{
		heal = 0;					// heal amount gets set to 0
	}
	health = health + heal;			// health + the heal amount gets stored in health

	if (health > maxHealth)			// if health is greater than max health
	{
		health = maxHealth;			// set health to the max health
	}
}

bool Character::IsAlive() const
{
	bool life;

	if (health <= 0)				// if health is less than or equal to 0
	{
		life = false;				// character life is set to false (dead)
	}
	else
	{
		life = true;				// else character life is set to true (alive)
	}
	return life;					// return false/true which as a bool is 0/1
}

std::string Character::GetName() const { return name; }
int Character::GetHealth() const { return health; }
int Character::GetMaxHealth() const { return maxHealth; }
int Character::GetAttackPower() const { return attackPower; }

Character::~Character() {}


