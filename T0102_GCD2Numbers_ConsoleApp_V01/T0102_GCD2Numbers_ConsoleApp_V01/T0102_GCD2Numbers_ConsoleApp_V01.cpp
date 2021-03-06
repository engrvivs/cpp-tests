// T0102_GCD2Numbers_ConsoleApp_V01.cpp - GCD / GCF / GCM / HCD / HCF 
// find Greatest Common Divisor of any two given positive integers

#include "stdafx.h"
#include <iostream>

int main()
{
	// get the two inputs
	unsigned int lui_Num1 = 1,
				 lui_Num2 = 1;
	std::cout << "Number 1: "; std::cin >> lui_Num1;
	std::cout << "Number 2: "; std::cin >> lui_Num2;

	// calculate GCD
	// initialize with smallest of the two input numbers
	unsigned int lui_GCD = (lui_Num1 < lui_Num2) ? lui_Num1
												 : lui_Num2;
    // check for GCD
	for (; lui_GCD > 0; --lui_GCD)
	{
		// if BOTH numbers are divisible
		if ((lui_Num1 % lui_GCD == 0)
		 && (lui_Num2 % lui_GCD == 0))
		{
			std::cout << "GCD = " << lui_GCD << "\n";
			//
			// break out of the loop - no need to check further
			break;
		}
	}

	return 0;
}

