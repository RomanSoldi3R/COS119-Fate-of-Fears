#include <iostream>
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
#include "FinalBoss.h"


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
			std::unique_ptr<Hero> hero;											// unique_ptr: automatically manages the lifetime of a heap-allocated object

			while (heroMenu)		//================================== Class Selection ==================================
			{
				Menu::HeroMenu();

				int key = _getch();												// accepts one key press
				if (key == '1')													// if key press is 1 - create knight
				{
					hero = std::make_unique<Knight>("Knight", 100, 25);			// make_unique: safely constructs an new object on the heap and returns an std::make_unique<T>(args...) wrapped inside a unique_ptr<T>
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

			if (hero != nullptr)												// if a hero was created
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
					if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5')		// if key press is 1-5
					{
						int index = key - '0' - 1;												// key press is then converted to the correct position ( '1' (ascii value: 49) - '0' (ascii value: 48) = 1 - 1 = 0 (position) then stores that in index
						int fightChance = Helper::RandomNumberGenerator(1, 3);					// 33% fight chance

						castle.Move(index);

						if (castle.GetCurrentRoom() == THRONEROOM)
						{
							FinalBoss boss("Wrath", 300, 25);
							result = Battle::Sequence(*hero, boss);
							
							if (result == false)												// if you lose
							{
								inCastle = false;												// return to the main menu
								break;
							}
							if (result == true)													// if you win
							{
								inCastle = false;												// return to the main menu (for now)
								break;
							}
						}
						else if (fightChance == 1)												// if fight happens
						{
							Dialog::FightDialog();

							Goblin goblin("Goblin", 100, 10);									// create a goblin object
							result = Battle::Sequence(*hero, goblin);							// battle sequence returns a true/false for whoever wins

							if (result == false)												// if you lose
							{
								inCastle = false;												// return to the main menu
								break;
							}
						}
					}
					if (key == esc)																// if key press is esc
					{
						inCastle = Menu::Options(key);											// options returns a bool so if the key press returns a false, return to the main menu
					}

				}		

			}

		}
		if (key == c)															// if key press is 'c'
		{
			int controlsMenu = true;
			while (controlsMenu)		//================================== Controls Menu (Main Menu) ==================================
			{
				Menu::ControlsMenu();

				int key = _getch();
				if (key == esc || key == c)										// go back to the main menu
				{
					controlsMenu = false;
				}
			}
		}
		if (key == esc)															// if key press is esc
		{
			titleMenu = false;													// exit the game
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

