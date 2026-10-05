#pragma once
#include <conio.h>

namespace MenuFunctions
{

	bool EnterEsc()
	{
		while (true)
		{
			int key = _getch();		// _getch() = accepts one key press

			if (key == 13)			// Enter
			{
				return true;
			}
			if (key == 27)			// Esc
			{
				return false;
			}
		}
	}











}