// T0104_LargestPrime_ConsoleApp_V01.cpp 
// find Largest Prime number smaller than a given positive integer

#include "stdafx.h"
#include <iostream>

// functions' declarations
bool fb_IsPrime(unsigned int const);

int main()
{
	// get the maximum limit
	unsigned int lui_Limit = 1;
	std::cout << "Maximum Limit (0 to EXIT): "; std::cin >> lui_Limit;

	do
	{
		// get largest prime, less than the given limit
		for (unsigned int lui_Num = (lui_Limit - 1); lui_Num > 1; --lui_Num)
		{
			// if Prime number found
			if (fb_IsPrime(lui_Num) == true)
			{
				std::cout << "Largest Prime = " << lui_Num << "\n";
				//
				break;
			}
		}
		//
		std::cout << "Maximum Limit (0 to EXIT): "; std::cin >> lui_Limit;
	} while (lui_Limit > 0);

	return 0;
}

// functions' definitions
bool fb_IsPrime(unsigned int const puic_Num)
{
	// check if this number is prime
	if (puic_Num < 4)
	{
		return (puic_Num > 1);
	}
	//
	if ((puic_Num % 2 == 0)
	 || (puic_Num % 3 == 0))
	{
		return (false);
	}
	//
	//for (unsigned int lui_Divisor = (puic_Num / 2); lui_Divisor > 1; --lui_Divisor)
	for (unsigned int lui_Divisor = 5; lui_Divisor * lui_Divisor <= puic_Num; lui_Divisor += 6)
	{
		// if it is divisible
		if ((puic_Num % lui_Divisor == 0)
		 || (puic_Num % (lui_Divisor + 2) == 0))
		{
			// DE-BUG
			std::cout << "\n" << puic_Num << " divided by " << lui_Divisor << " OR " << (lui_Divisor + 2) << "\n";
			// NOT a prime
			return (false);
		}
	}
	//
	return (true);
}