#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <memory>
#include "Helper.h"
#include "Art.h"
#include "Menus.h"
#include "Dialog.h"
#include "Battle.h"
#include "Castle.h"
#include "Character.h"
#include "Knight.h"
#include "Sorceress.h"
#include "Goblin.h"


int main()
{
	int esc = 27;																// variables
	int backspace = 8;
	int enter = 13;
	int c = 99;
	bool titleMenu = true;
	
	while (titleMenu)		//================================== Main Menu ==================================
	{
		Menu::TitleMenu();

		int key = _getch();
		if (key == enter)														// if player presses enter continue to hero menu
		{
			bool heroMenu = true;												// resets the heroMenu variable to true in case the player hits esc changing it to false, you can enter the hero menu again
			std::unique_ptr<Hero> hero;

			while (heroMenu)		//================================== Class Selection ==================================
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
				Dialog::CastleDialog();

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

						int fightChance = Helper::RandomNumberGenerator(1, 3);
						if (fightChance == 1)
						{
							Dialog::FightDialog();

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


				}		

			}

		}
		if (key == c)		//================================== Controls Menu (Main Menu) ==================================
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
		}		//================================== Exit Game (Main Menu) ==================================
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

