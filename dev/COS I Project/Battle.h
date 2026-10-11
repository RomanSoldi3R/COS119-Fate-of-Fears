#pragma once
#include "Hero.h"
#include "Enemy.h"


namespace Battle
{

	static bool Sequence(Hero& _hero, Enemy& _enemy)
	{
		bool winner = true;
		std::string action;

		while (true)
		{
			system("cls");
			_hero.PrintStats();
			_enemy.PrintStats();

			action = _hero.TakeTurn(_enemy);
			
			system("cls");
			_hero.PrintStats();
			_enemy.PrintStats();
			
			std::cout << action << std::endl;
			Helper::Pause();

			if (!_enemy.IsAlive())
			{
				winner = true;
				
				system("cls");
				_hero.PrintStats();
				_enemy.PrintStats();

				std::cout << "\n\r\033[2K\033[34C::\033[32m" + _enemy.GetName() + " Has Been Defeated, Congradulations!\033[0m::" << std::endl;
				
				Helper::Pause();
				break;
			}

			system("cls");
			_hero.PrintStats();
			_enemy.PrintStats();

			action = _enemy.TakeTurn(_hero);
			
			system("cls");
			_hero.PrintStats();
			_enemy.PrintStats();
			
			std::cout << action << std::endl;
			Helper::Pause();

			if (!_hero.IsAlive())
			{
				winner = false;

				system("cls");
				_hero.PrintStats();
				_enemy.PrintStats();

				std::cout << "\n\r\033[2K\033[50C::\033[31m...You Died...\033[0m::" << std::endl;

				Helper::Pause();
				break;
			}

			_hero.TurnOver();
		}
		return winner;
	}






};

