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


namespace Helper
{

	inline bool IsInteger(char* input)
	{
		if (input == nullptr || *input == '\0')
		{
			return false;
		}
		char* endPtr;
		long result = strtol(input, &endPtr, 10);

		if (endPtr == input)
		{
			return false;
		}
		if (*endPtr != '\0')
		{
			return false;
		}
		return true;
	}

	inline void PrintIntegerBinary(int* num)
	{
		int result = *num;

		for (int c = 31; c >= 0; c--)
		{
			if (result & (1 << c))
			{
				std::cout << '1';
			}
			else
			{
				std::cout << '0';
			}
		}
	}

	inline void NumberSort(int* array, int size)
	{
		for (int c = 0; c < size; c++)
		{
			for (int c2 = 0; c2 < size - 1 - c; c2++)
			{
				if (array[c2] > array[c2 + 1])
				{
					int temp = array[c2];
					array[c2] = array[c2 + 1];
					array[c2 + 1] = temp;
				}
			}
		}
	}

	inline int VectorSum(std::vector<int>* vec)
	{
		if (vec == nullptr)
		{
			return 0;
		}
		int sum = 0;
		
		for (int c = 0; c < vec->size(); c++)
		{
			sum += (*vec)[c];
		}
		return sum;
	}

	inline int GetValidIndex(int min, int max)
	{
		std::string input;
		int result;

		while (true)
		{
			getline(std::cin, input);

			try
			{
				result = std::stoi(input);
			}
			catch (const std::exception&)
			{

			}
			
			if (result >= min && result <= max)
			{
				return result;
			}
			else
			{
				std::cout << "Invalid Input: Please try again" << std::endl;
			}
		}
	}

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

	inline bool CoinFlip()
	{
		std::random_device rd;									// Obtain a seed from the system
		std::mt19937 gen(rd());									// Seed the generator
		std::uniform_int_distribution<> distrib(0, 1);			// Define the range
		int random_number = distrib(gen);						// Generate the number

		return random_number;
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
		std::cout << "\033[2J\033[1;1H";		// \033[2J clears the screen | \033[1;1H moves cursor to row 1, col 1
	}







}

