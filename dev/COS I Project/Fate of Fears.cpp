#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "Character.h"
#include "Knight.h"
#include "Sorceress.h"
#include "Art.h"
#include "Helper.h"


int main()
{
	srand(time(NULL));

	Art::TitleArt();															
	if (!Helper::EnterEsc())													// if player doesn't press enter...
	{
		return 0;																// ...exit the game
	}

	bool titleMenu = true;														// variables
	bool heroMenu = true;
	int esc = 27;

	while (titleMenu)															// start of the title menu loop
	{
		system("cls");															// clear screen
		Art::TitleArt();

		std::cout << "\033[47C" << "Enter: Play" << std::endl;
		std::cout << "\033[51C" << "Esc: Exit" << std::endl;

		if (Helper::EnterEsc())													// if player presses enter continue to hero menu
		{
			heroMenu = true;													// resets the heroMenu variable to true in case the player hits esc changing it to false, you can enter the hero menu again

			while (heroMenu)													// start of the hero menu loop
			{
				system("cls");													// clear screen
				Art::KnightArt();
				std::cout << "\033[50C" << "Select Class" << std::endl;
				std::cout << "\033[18C" << "1: Knight" << "\033[60C" << "2: Sorceress" << std::endl;
				
				int key = _getch();												// accepts one key press

				if (key == '1')													// if key press is 1 - create knight
				{
					Knight* knight = new Knight("Knight", 100, 25);
				}
				if (key == '2')													// if key press is 2 - create sorcerer
				{
					std::cout << "create sorceress" << std::endl;// (placeholder)
				}
				if (key == esc)													// if key press is esc - hero menu is set to false which goes back to the title menu
				{
					heroMenu = false;
				}

			}

		}
		else																	// else set title menu to false which exits the game
		{
			titleMenu = false;
		}

	}



	  

}


// see the Title Screen - press enter to continue/ esc to exit
// choose hero: Knight/Sorcerer
// turn based style combat
// return to title screen after battle

