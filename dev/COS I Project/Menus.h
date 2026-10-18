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

		std::cout << "\r\033[2K" << std::endl;
		std::cout << "\r\033[10B\033[35C\033[31m   =><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m   " << std::endl;
		std::cout << "\r\033[35C\033[31m   ||\033[0m 1.           \033[33m[Controls]\033[0m               \r\033[79C\033[31m||   \033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m   ||\033[0m 2.           \033[33m[Beastiary]\033[0m              \r\033[79C\033[31m||   \033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m   ||\033[0m 3.        \033[33mExit to Main Menu\033[0m           \r\033[79C\033[31m||   \033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m   =><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m   " << std::endl;
		std::cout << "\r\033[2K" << std::endl;
		std::cout << "\r\033[2K" << std::endl;
	}

	inline void ControlsMenu()
	{
		std::cout << "\r\033[3J\033[H";

		std::cout << "\r\033[10B\033[35C\033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m                  \033[4;33mControls\033[0m                   \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m \033[4;33mEnter\033[0m: Continue or accept                   \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m \033[4;33mESC\033[0m: Go back to the previous menu           \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m \033[4;33mBackspace\033[0m: Previous menu(Combat)            \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m                   \033[4;33mLegend\033[0m                    \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m \033[4;33m[...]\033[0m: Has a menu within that option        \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m||\033[0m \033[4;33m{...}\033[0m: Doesn't use up a turn                \r\033[82C\033[31m||\033[0m" << std::endl;
		std::cout << "\r\033[35C\033[31m=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=><=\033[0m" << std::endl;
	}


}