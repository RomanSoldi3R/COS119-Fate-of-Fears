#pragma once
#include "Hero.h"
#include "Enemy.h"


namespace Battle
{

	inline bool Sequence(Hero& _hero, Enemy& _enemy)
	{
		bool winner = true;												// variables
		std::string action;

		while (true)		//================================== Battle Sequence ==================================
		{
			Helper::clearScreen();
			_hero.PrintStats();
			_enemy.PrintStats();

			action = _hero.TakeTurn(_enemy);							// returns a string which is stored in action
			
			if (action == "\t::You fled the battle!::")					// if string matches
			{
				Helper::Pause();										// pause for the player to read
				break;													// exit the battle sequence
			}

			Helper::clearScreen();
			_hero.PrintStats();
			_enemy.PrintStats();
			
			std::cout << action << std::endl;							// print out the combat result
			Helper::Pause();											// pause for effect

			if (!_enemy.IsAlive())										// if the enemy is not alive
			{
				winner = true;											// you win!
				
				Helper::clearScreen();
				_hero.PrintStats();
				_enemy.PrintStats();

				action =  "\n\r\033[2K\033[34C::\033[32m" + _enemy.GetName() + " Has Been Defeated, Congradulations!\033[0m::";		// store the win screen

				Helper::Type(action, 45);								// print the win screen
				Helper::Pause();
				break;													// exit the battle sequence
			}

			Helper::clearScreen();
			_hero.PrintStats();
			_enemy.PrintStats();

			action = _enemy.TakeTurn(_hero);
			
			Helper::clearScreen();
			_hero.PrintStats();
			_enemy.PrintStats();
			
			std::cout << action << std::endl;
			Helper::Pause();

			if (!_hero.IsAlive())										// if the hero is not alive
			{
				winner = false;											// you lose!

				Helper::clearScreen();
				_hero.PrintStats();
				_enemy.PrintStats();

				action = "\n\r\033[2K\033[50C::\033[31m...You Died...\033[0m::";		// store the lose screen

				Helper::Type(action, 45);								// print the win screen
				Helper::Pause();
				break;													// exit the battle sequence
			}
			_hero.TurnOver();											// resource regen if possible
		}
		return winner;
	}

};

