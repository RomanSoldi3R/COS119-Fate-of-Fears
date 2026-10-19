#pragma once
#include "Helper.h"
#include "Art.h"

namespace Dialog
{

	inline void CastleDialog()
	{
		std::string dialog;

		Helper::clearScreen();
		Art::CastleGateArt();

		dialog = "\r\033[15A\033[38CYou approach the Main Gate to the Castle...\n\n"
			"\033[41C\033[31mFear\033[0m can be your greatest strength,\n\n"
			"\033[42CBut if you let it consume you...\n\n"
			"\033[37CYour \033[1;33mFate\033[0m will be decided before it begins...\n";

		Helper::Type(dialog, 85);
		Helper::Pause();
	}


	inline void FightDialog()
	{
		std::string dialog;

		Helper::clearScreen();
		dialog = "\r\033[13B\033[50C\033[1;33mPrepare for \033[0m\033[31mBattle!\033[0m\n";
		Helper::Type(dialog, 45);
		Helper::Pause();
	}










}