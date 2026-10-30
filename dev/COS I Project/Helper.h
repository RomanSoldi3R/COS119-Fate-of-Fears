#pragma once
#include <iostream>		// standard I/O stream library
#include <string>		// std::string
#include <vector>		// std::vector
#include <cstdlib>		// srand
#include <ctime>		// time
#include <random>		// std::random_device
#include <conio.h>		// _getch() / _kbhit()
#include <thread>		// std::this_thread::sleep_for
#include <chrono>		// std::chrono::milliseconds(...)
#include <iomanip>		// std::setw(3) << std::setfill('0')
#include <Windows.h>	// FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE))
#include <algorithm>	// std::shuffle
#include <format>		// std::format(...)


namespace Helper
{

	inline std::mt19937& Engine()
	{
		static std::mt19937 gen(std::random_device{}());
		return gen;
	}

	inline int RandomNumberGenerator(int min, int max)
	{
		if (min > max)
		{
			return 0;
		}
		else
		{
			std::uniform_int_distribution<> distrib(min, max);		// Define the range
			int random_number = distrib(Engine());					// Generate the number

			return random_number;
		}
	}

	inline bool EnterEsc()
	{
		while (true)
		{
			int key = _getch();									// _getch() = accepts one key press

			if (key == 13)										// Enter
			{
				return true;
			}
			if (key == 27)										// Esc
			{
				return false;
			}
		}
	}

	inline void Pause()
	{
		std::cout << "\r\n\033[54C" << "C\033[31m=\033[0m|======>\n" << std::endl;

		while (true)
		{
			int key = _getch();
			
			if (key == 13)
			{
				break;
			}
			else
			{
				std::cout << "\r\033[2K";
				std::cout << "\033[47C" << "Press enter to continue...";
			}
		}
	}

	inline void Type(const std::string& message, int delay)
	{
		bool skip = false;

		for (char letter : message)
		{
			if (_kbhit())						// if Keyboard hit was pressed --> (returns an integer (non-zero if a key is pressed, 0 otherwise)
			{
				if (_getch() == 13)				// if Enter was pressed --> (returns the ASCII value of the key that was pressed)
				{
					skip = true;
				}
			}
			if (skip)
			{
				std::cout << letter;
				continue;
			}

			std::cout << letter << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));			// removes text that is input while waiting for type
	}

	inline void ErasePreviousLines(int amount)
	{
		for (int c = 0; c < amount; c++)
		{
			std::cout << "\r\033[1A\033[2K";
		}
	}

	inline void clearScreen()
	{
		std::cout << "\033[2J\033[3J\033[H";		// \033[2J clears the screen | \033[3J erases the scroll back | \033[H puts the cursor back at row 1, column 1.
	}







}

