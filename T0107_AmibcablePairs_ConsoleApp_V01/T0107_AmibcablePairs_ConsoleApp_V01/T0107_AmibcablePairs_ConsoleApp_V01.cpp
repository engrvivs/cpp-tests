// T0107_AmibcablePairs_ConsoleApp_V01.cpp 
// print pairs of Amicable numbers, upto a certain limit

#include "pch.h"
#include <iostream>

// functions' declarations
unsigned long ful_SumOfProperDivisors(unsigned long const);

int main()
{
	// get the maximum limit
	unsigned long lul_Limit = 1000000;
	std::cout << "Maximum Limit (0 to EXIT): "; std::cin >> lul_Limit;

	while (lul_Limit > 0)
	{
		std::cout << "\nAmicable Pairs: ";

		unsigned long lul_SumOfProperDivisors = 1;
		//
		// go through all abundant numbers, upto the given limit
		for (unsigned long lul_Num = 2; lul_Num < lul_Limit; ++lul_Num)
		{
			// get sum of proper divisors
			lul_SumOfProperDivisors = ful_SumOfProperDivisors(lul_Num);
			//
			if ((lul_SumOfProperDivisors > lul_Num)
			 && (lul_SumOfProperDivisors < lul_Limit))
			{
				if (ful_SumOfProperDivisors(lul_SumOfProperDivisors) == lul_Num)
					std::cout << "  (" << lul_Num << ", " << lul_SumOfProperDivisors << "),";
			}
		}
		//
		std::cout << "\n\nMaximum Limit (0 to EXIT): "; std::cin >> lul_Limit;
	}

	return 0;
}

// functions' definitions
unsigned long ful_SumOfProperDivisors(unsigned long const pulc_Num)
{
	// calculate sum of proper divisors of the given number
	unsigned long rul_SumOfProperDivisors = 1;
	//
	for (unsigned long lul_Divisor = sqrt(pulc_Num); lul_Divisor > 1; --lul_Divisor)
	{
		// if it is divisible
		if (pulc_Num % lul_Divisor == 0)
		{
			rul_SumOfProperDivisors += lul_Divisor;
			//
			unsigned long lul_OtherDivisor = pulc_Num / lul_Divisor;
			if (lul_OtherDivisor != lul_Divisor)
			{
				// add the other proper divisor
				rul_SumOfProperDivisors += lul_OtherDivisor;
			}
		}
	}
	//
	return (rul_SumOfProperDivisors);
}