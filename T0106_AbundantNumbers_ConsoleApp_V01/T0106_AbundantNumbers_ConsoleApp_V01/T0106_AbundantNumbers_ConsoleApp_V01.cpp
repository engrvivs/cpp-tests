// T0106_AbundantNumbers_ConsoleApp_V01.cpp : 
// print Abundant numbers and their respective abundance, upto a certain limit

#include "pch.h"
#include <iostream>

// functions' declarations
long fl_GetAbundance(unsigned int const);

int main()
{
	// get the maximum limit
	unsigned int lui_Limit = 1;
	std::cout << "Maximum Limit (0 to EXIT): "; std::cin >> lui_Limit;

	while (lui_Limit > 0)
	{
		std::cout << "\n------\t---------";
		std::cout << "\nNumber\tAbundance"; 
		std::cout << "\n------\t---------";

		long ll_Abundance = 0;
		//
		// get all abundant numbers, upto the given limit
		for (unsigned int lui_Num = 2; lui_Num < lui_Limit; ++lui_Num)
		{
			// get abundance
			ll_Abundance = fl_GetAbundance(lui_Num);
			//
			// is it abundant?
			if (ll_Abundance > 0)
			{
				std::cout << "\n  " << lui_Num << "\t  " << ll_Abundance;
			}
		}
		std::cout << "\n------\t---------";
		//
		std::cout << "\n\nMaximum Limit (0 to EXIT): "; std::cin >> lui_Limit;
	}

	return 0;
}

// functions' definitions
long fl_GetAbundance(unsigned int const puic_Num)
{
	// calculate sum of proper divisors of the given number
	unsigned long lul_SumOfProperDivisors = 1;
	//
	//for (unsigned int lui_Divisor = (puic_Num / 2); lui_Divisor > 1; --lui_Divisor)
	for (unsigned int lui_Divisor = sqrt(puic_Num); lui_Divisor > 1; --lui_Divisor)
	{
		// if it is divisible
		if (puic_Num % lui_Divisor == 0)
		{
			lul_SumOfProperDivisors += lui_Divisor;
			//
			unsigned int lui_OtherDivisor = puic_Num / lui_Divisor;
			if (lui_OtherDivisor != lui_Divisor)
			{
				// add the other proper divisor
				lul_SumOfProperDivisors += lui_OtherDivisor;
			}
		}
	}
	//
	// abundance
	return (lul_SumOfProperDivisors - puic_Num);
}