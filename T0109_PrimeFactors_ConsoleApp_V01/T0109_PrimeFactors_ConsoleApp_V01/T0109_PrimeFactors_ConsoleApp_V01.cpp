// T0109_PrimeFactors_ConsoleApp_V01.cpp 
// display prime factors of a given number

#include "pch.h"
#include <iostream>

// functions' definitions
bool fb_IsPrime(unsigned int const);

int main()
{
	unsigned int lui_Number = 1000;
	std::cout << "Enter a Number (0 to EXIT): "; std::cin >> lui_Number;

	while (lui_Number > 0)
	{
		std::cout << "\nPrime Factors: ";
		//
		for (unsigned int lui_Divisor = sqrt(lui_Number); lui_Divisor > 1; --lui_Divisor)
		{
			if (lui_Number % lui_Divisor == 0)
			{
				if (fb_IsPrime(lui_Divisor) == true)
					std::cout << lui_Divisor << ", ";
				//
				// check another divisor
				unsigned int lui_OtherDivisor = lui_Number / lui_Divisor;
				if (lui_OtherDivisor != lui_Divisor)
				{
					if (fb_IsPrime(lui_OtherDivisor) == true)
						std::cout << lui_OtherDivisor << ", ";
				}
			}
		}
		//
		std::cout << "\n\nEnter a Number (0 to EXIT): "; std::cin >> lui_Number;
	}
	//
	return (0);
}

// functions' declarations
bool fb_IsPrime(unsigned int const puic_Num)
{
	for (unsigned int lui_Divisor = sqrt(puic_Num); lui_Divisor > 1; --lui_Divisor)
	{
		if (puic_Num % lui_Divisor == 0)
		{
			// NOT prime
			return (false);
		}
	}
	//
	return (true);
}