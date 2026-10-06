#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>
#include <random>


namespace Helper
{


	static bool IsInteger(char* input)
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

	static void PrintIntegerBinary(int* num)
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

	static void NumberSort(int* array, int size)
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

	static int RandomNumberGenerator(int min, int max)
	{
		if (min > max)
		{
			std::cout << "\nERROR: Invalid Range!";
			return 0;
		}
		else
		{
			srand(time(nullptr));
			int randomNumber = rand() % (max - min + 1) + min;
			std::cout << "\nRandomNumberGenerator: " << randomNumber;
			return randomNumber;
		}
	}

	static int VectorSum(std::vector<int>* vec)
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

	static int GetValidIndex(int min, int max)
	{
		int input;

		while (true)
		{
			std::cin >> input;
			
			if (input >= min && input <= max)
			{
				return input;
			}
			else
			{
				std::cout << "Invalid Input: Please try again" << std::endl;
			}
		}
	}

	static bool CoinFlip()
	{
		std::random_device rd;  // Obtain a seed from the system
		std::mt19937 gen(rd()); // Seed the generator
		std::uniform_int_distribution<> distrib(0, 1); // Define the range
		int random_number = distrib(gen); // Generate the number

		return random_number;
	}

	static bool EnterEsc()
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

