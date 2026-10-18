#pragma once
#include "Helper.h"
#include "Art.h"


namespace Menu
{

	inline void TitleMenu()
	{
		Helper::clearScreen();
		Art::TitleArt();

		std::cout << "\r\033[49C" << "Enter: Start Game" << std::endl;
		std::cout << "\r\033[52C" << "C: Controls" << std::endl;
		std::cout << "\r\033[53C" << "Esc: Exit" << std::endl;
	}

	inline void HeroMenu()
	{
		Helper::clearScreen();
		Art::KnightArt();

		std::cout << "\r\033[26A\033[50C" << "Select Class" << "\033[26B" << std::endl;
		std::cout << "\r\033[18C" << "1: Knight" << "\033[60C" << "2: Sorceress" << std::endl;
	}

	inline void OptionsMenu()
	{
		Helper::clearScreen();

		std::cout << "\r\033[10B\033[35C\033[31m   =><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m   " << std::endl;
		std::cout << "\r\033[35C\033[31m   ||\033[0m                \033[1;4;33mOPTIONS\033[0m                \r\033[79C\033[31m||   \033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m   ||\033[0m 1.           [Controls]               \r\033[79C\033[31m||   \033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m   ||\033[0m 2.           [Beastiary]              \r\033[79C\033[31m||   \033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m   ||\033[0m 3.        Exit to Main Menu           \r\033[79C\033[31m||   \033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m   =><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m   " << std::endl;
	}

	inline void ControlsMenu()
	{
		std::cout << "\r\033[3J\033[H";

		std::cout << "\r\033[10B\033[35C\033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m                  \033[1;4;33mControls\033[0m                  \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m \033[33mEnter\033[0m: Continue or accept                      \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m \033[33mESC\033[0m: Go back to the previous menu              \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m \033[33mBackspace\033[0m: Previous menu(Combat)               \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m                   \033[1;4;33mLegend\033[0m                   \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m \033[33m[...]\033[0m: Has a menu within that option           \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m \033[33m{...}\033[0m: Doesn't use up a turn                   \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
	}

	inline bool Options(char key)
	{
		int esc = 27;

		if (key == esc)
		{
			int optionsMenu = true;
			while (optionsMenu)
			{
				Menu::OptionsMenu();

				int key = _getch();
				if (key == '1')										// controls menu
				{
					int controlsMenu = true;
					while (controlsMenu)
					{
						Menu::ControlsMenu();

						int key = _getch();
						if (key == esc || key == '1')				// go back to options menu
						{
							controlsMenu = false;
						}
					}
				}
				if (key == '2')										// beastiary menu
				{
					int beastiaryMenu = true;
					while (beastiaryMenu)
					{
						// beastiary menu goes here

						int key = _getch();
						if (key == esc || key == '2')				// go back to options menu
						{
							beastiaryMenu = false;
						}
					}
				}
				if (key == '3')										// exit game
				{
					optionsMenu = false;
					return false;
				}
				if (key == esc)										// go back to game
				{
					optionsMenu = false;
				}
			}
		}
		return true;
	}




}