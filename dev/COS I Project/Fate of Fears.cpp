#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "Character.h"
#include "Knight.h"
#include "Sorcerer.h"
#include "Art.h"
#include "Menu Functions.h"


int main()
{
	srand(time(NULL));

	Art::TitleArt();
	if (!MenuFunctions::EnterEsc())
	{
		return 0;
	}

	bool titleMenu = true;														// variables
	bool heroMenu = true;
	int esc = 27;

	while (titleMenu)															// start of the loop
	{
		system("cls");
		Art::TitleArt();

		std::cout << "\033[47C" << "Enter: Select Hero" << std::endl;
		std::cout << "\033[51C" << "Esc: Exit" << std::endl;

		if (MenuFunctions::EnterEsc())
		{
			heroMenu = true;

			while (heroMenu)
			{
				system("cls");
				std::cout << "\033[50C" << "Select Hero" << std::endl;
				std::cout << "\033[45C" << "1: Knight" << "\t2: Sorcerer" << std::endl;
				
				int key = _getch();

				if (key == '1')
				{
					std::cout << "create knight" << std::endl;
				}
				if (key == '2')
				{
					std::cout << "create sorcerer" << std::endl;
				}
				if (key == esc)
				{
					heroMenu = false;
				}

			}

		}
		else
		{
			titleMenu = false;
		}

	}

}


// see the Title Screen - press enter to continue/ esc to exit
// choose hero: Knight/Sorcerer
// turn based style combat
// return to title screen after battle

