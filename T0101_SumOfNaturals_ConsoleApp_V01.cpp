// T0101_SumOfNaturalNumbers_ConsoleAppl_V01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	// get maximum limit
	unsigned int lui_Div1 = 3,
				 lui_Div2 = 5,
				 lui_Limit = 0;
	std::cout << "Enter maximum limit: ";
	std::cin >> lui_Limit;

	// calculate sum of natural numbers divisible by either of the two divisors
	unsigned long long lull_Sum = 0; // to overcome any overflow
	for (int lui_Num = ((lui_Div1 < lui_Div2) ? lui_Div1: lui_Div2); 
			 lui_Num <= lui_Limit; 
		   ++lui_Num)
	{
		if ((lui_Num % lui_Div1 == 0)
		 || (lui_Num % lui_Div2 == 0))
		{
			//DEBUG: std::cout << lui_Num << " + ";
			lull_Sum += lui_Num;
		}
	}
	std::cout << "\nSum = " << lull_Sum << "\n";

    return 0;
}

