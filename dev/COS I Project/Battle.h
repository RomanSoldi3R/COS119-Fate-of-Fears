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
				break;
			}

			system("cls");
			_hero.PrintStats();
			_enemy.PrintStats();
			Helper::Pause();
			action = _enemy.TakeTurn(_hero);
			system("cls");
			_hero.PrintStats();
			_enemy.PrintStats();
			std::cout << action << std::endl;
			Helper::Pause();

			if (!_hero.IsAlive())
			{
				winner = false;
				break;
			}

			_hero.TurnOver();
		}
		return winner;
	}






};

