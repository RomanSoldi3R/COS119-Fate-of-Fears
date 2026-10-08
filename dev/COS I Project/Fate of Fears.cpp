#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <memory>
#include "Helper.h"
#include "Art.h"
#include "Character.h"
#include "Knight.h"
#include "Sorceress.h"
#include "Goblin.h"
#include "Battle.h"


int main()
{
	srand(time(NULL));
	
	Knight joel("Knight", 100, 25);
	Goblin poop("Goblin", 50, 15);

	Art::TitleArt();
	joel.PrintStats();
	poop.PrintStats();
	Helper::Pause();

	bool titleMenu = true;														// variables
	bool heroMenu = true;
	int esc = 27;

	while (titleMenu)															// start of the title menu loop
	{
		system("cls");															// clear screen
		Art::TitleArt();
		
		std::cout << "\033[49C" << "Enter: Start Game" << std::endl;
		std::cout << "\033[53C" << "Esc: Exit" << std::endl;

		if (Helper::EnterEsc())													// if player presses enter continue to hero menu
		{
			heroMenu = true;													// resets the heroMenu variable to true in case the player hits esc changing it to false, you can enter the hero menu again
			std::unique_ptr<Hero> hero;

			// (Intro dialog coded here)

			while (heroMenu)													// start of the hero menu loop
			{
				system("cls");													// clear screen
				Art::KnightArt();
				std::cout << "\033[50C" << "Select Class" << std::endl;
				std::cout << "\033[18C" << "1: Knight" << "\033[60C" << "2: Sorceress" << std::endl;

				int key = _getch();												// accepts one key press

				if (key == '1')													// if key press is 1 - create knight
				{
					
					hero = std::make_unique<Knight>("Knight", 100, 25);
					heroMenu = false;
					
				}
				if (key == '2')													// if key press is 2 - create sorcerer
				{
					hero = std::make_unique<Sorceress>("Sorceress", 100, 10);
					heroMenu = false;
				}
				if (key == esc)													// if key press is esc - hero menu is set to false which goes back to the title menu
				{
					heroMenu = false;
				}
				
			}

			if (hero != nullptr)
			{
				// (Castle entrance and paths start here)
				bool castle = true;

				while (castle)
				{
					bool result = true;

					Goblin goblin("Weak Goblin", 50, 15);
					result = Battle::Sequence(*hero, goblin);

					if (result == false)
					{
						castle = false;
					}
				}

			}

		}
		else																	// else set title menu to false which exits the game
		{
			titleMenu = false;
		}

	}



	  

}


// intro dialog plays
// you select your class
// paths open up for you to choose from
// run into empty rooms or enemies to fight
// paths open up again
// this loop repeats until you encounter the boss chamber
// which then you can decide to fight the final boss or not
// once the final boss is defeated, you win
// if you die, return to the main menu

