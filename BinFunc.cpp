#include <iostream>
#include "BinConstants.h"

int bin_digit()						// Function for entering a number
{
	int digit = 0;

	do
	{
		std::cout << "Enter a digit (0 - 65535)\n";
		std::cin >> digit;
		if (digit < 0 || digit > 65536)
		{
			std::cout << "Error. Enter a digit (0 - 65535)\n";
		}
	} while (digit < 0 || digit > 65536);

	return digit;
}

// Function for converting a number to binary code
void convert_bin(int num, int* arr, const int SIZE)
{
	int i, bin;
	bin = 32768;

	for (i = 0; i < SIZE; )
	{
		if (num >= bin)
		{
			num = num - bin;
			bin = bin / 2;
			arr[i] = 1;
			i++;
		}
		else
		{
			arr[i] = 0;
			bin = bin / 2;
			i++;
		}
	}
}

// The output function of a binary number
void print_bin(int* arr, const int SIZE)
{
	int countSapce = 0;				// To divide a number into 4 digits for whitespace 
	int countStr = 0;				// To divide a number into 8 digits for ' 
	int countZers = 0;				// To avoid displaying zeros in the highest binary digit

	// Counting zeros of the highest binary digit
	for (int i = 0; i < 8; i++)
	{
		if (arr[i] == 0)
		{
			countZers++;
		}
	}

	int i = 0;

	// If all zeros are in the highest binary digit
	if (countZers == 8)
	{
		i = 8;
	}

	for ( ; i < SIZE; i++)
	{
		std::cout << arr[i];

		++countSapce;
		++countStr;

		if ((countSapce) == 4)		// Entet  whitespace
		{
			std::cout << " ";
			countSapce = 0;
		}

		if (i == SIZE - 1)			// Crutch for blocking output in end '
		{
			continue;
		}

		if ((countStr) == 8)		// output ' between 8 digit
		{
			std::cout << "\' ";
		}

	}
	std::cout << std::endl;
}

void binstart()
{
	int num = bin_digit();			// input digit

	int arr[BinConst::SIZE]{};		// array for convert digit to binary code

	std::cout << "\nDigit = " << num << std::endl;

	// Converting a number to binary code
	convert_bin(num, arr, BinConst::SIZE);
	std::cout << num << " in bin ";

	print_bin(arr, BinConst::SIZE);
}