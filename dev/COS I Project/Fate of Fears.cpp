#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <memory>
#include "Helper.h"
#include "Art.h"
#include "Menus.h"
#include "Castle.h"
#include "Character.h"
#include "Knight.h"
#include "Sorceress.h"
#include "Battle.h"
#include "Goblin.h"


int main()
{
	int esc = 27;																// variables
	int backspace = 8;
	int enter = 13;
	int c = 99;
	bool titleMenu = true;
	std::string dialog;

	while (titleMenu)															// start of the title menu loop
	{
		Menu::TitleMenu();

		int key = _getch();
		if (key == enter)														// if player presses enter continue to hero menu
		{
			bool heroMenu = true;												// resets the heroMenu variable to true in case the player hits esc changing it to false, you can enter the hero menu again
			std::unique_ptr<Hero> hero;

			while (heroMenu)													// start of the hero menu loop
			{
				Menu::HeroMenu();

				int key = _getch();												// accepts one key press
				if (key == '1')													// if key press is 1 - create knight
				{
					
					hero = std::make_unique<Knight>("Knight", 100, 25);
					heroMenu = false;
					
				}
				if (key == '2')													// if key press is 2 - create sorcerer
				{
					hero = std::make_unique<Sorceress>("Sorceress", 100, 5);
					heroMenu = false;
				}
				if (key == esc)													// if key press is esc - hero menu is set to false which goes back to the title menu
				{
					heroMenu = false;
				}
				
			}

			if (hero != nullptr)
			{
				Helper::clearScreen();
				Art::CastleGateArt();
				
				dialog = "\r\033[15A\033[38CYou approach the Main Gate to the Castle...\n\n"
					"\033[41C\033[31mFear\033[0m can be your greatest strength,\n\n" 
					"\033[42CBut if you let it consume you...\n\n"
					"\033[37CYour \033[1;33mFate\033[0m will be decided before it begins...\n";

				Helper::Type(dialog, 85);
				Helper::Pause();

				Castle castle;
				bool result = true;
				bool inCastle = true;
				while (inCastle)		//================================== CASTLE ==================================
				{
					Helper::clearScreen();

					castle.InView(*hero);

					int key = _getch();
					if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5')
					{
						int index = key - '0' - 1;

						castle.Move(index);

						int fightChance = Helper::RandomNumberGenerator(1, 4);
						if (fightChance == 1)
						{
							Goblin goblin("Goblin", 100, 10);
							result = Battle::Sequence(*hero, goblin);

							if (result == false)
							{
								inCastle = false;
								break;
							}
						}
					}
					if (key == esc)
					{
						inCastle = Menu::Options(key);
					}


				}		//================================== CASTLE ==================================

			}

		}
		if (key == c)															// controls menu at the main menu
		{
			int controlsMenu = true;
			while (controlsMenu)
			{
				Menu::ControlsMenu();

				int key = _getch();
				if (key == esc || key == c)										// go back to the main menu
				{
					controlsMenu = false;
				}
			}
		}
		if (key == esc)															// else set title menu to false which exits the game
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

