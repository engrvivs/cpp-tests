// T0102_GCD2Numbers_ConsoleApp_V01.cpp - GCD / GCF / GCM / HCD / HCF 
// find Greatest Common Divisor of any two given positive integers
// provides various different options for calcuation

#include "stdafx.h"
#include <iostream>

// functions' declarations
unsigned int fui_GCD(unsigned int const, unsigned int const);
unsigned int fui_EuclidGCD(unsigned int, unsigned int);
unsigned int fui_EuclidGCD_Recursive(unsigned int const, unsigned int const);

int main()
{
	// get the two inputs
	unsigned int lui_Num1 = 1,
				 lui_Num2 = 1;
	std::cout << "Positive Number 1: "; std::cin >> lui_Num1;
	std::cout << "Positive Number 2: "; std::cin >> lui_Num2;

	// get GCD calculation option
	unsigned short int lusi_Option = 1;
	std::cout << "\n\n*** GCD Calculation ***";
	std::cout << "\n1. Normal Looping"; 
	std::cout << "\n2. Euclid's Algo - Non-recursive";
	std::cout << "\n3. Euclid's Algo - Recursive Function Calls";
	std::cout << "\nEnter 0 to EXIT";
	//
	std::cout << "\nEnter your option: "; std::cin >> lusi_Option;
	//
	while (lusi_Option > 0)
	{
		// calculate GCD
		unsigned int lui_GCD = 1;
		switch (lusi_Option)
		{
			case 1:
				lui_GCD = fui_GCD(lui_Num1, lui_Num2);
				break;
			case 2:
				lui_GCD = fui_EuclidGCD(lui_Num1, lui_Num2);
				break;
			default:
				lui_GCD = fui_EuclidGCD_Recursive(lui_Num1, lui_Num2);
		}
		//
		std::cout << "GCD = " << lui_GCD << "\n";
		//
		std::cout << "\nEnter your option: "; std::cin >> lusi_Option;
	}

	return 0;
}

// functions' definitions
unsigned int fui_GCD(unsigned int const puic_Num1, unsigned int const puic_Num2)
{
	// initialize with smallest of the two input numbers
	unsigned int rui_GCD = (puic_Num1 < puic_Num2) ? puic_Num1
												   : puic_Num2;
	// check for GCD
	for (; rui_GCD > 0; --rui_GCD)
	{
		// if BOTH numbers are divisible
		if ((puic_Num1 % rui_GCD == 0)
		 && (puic_Num2 % rui_GCD == 0))
		{
			// GCD found
			return (rui_GCD);
		}
	}

	return (1);
}

unsigned int fui_EuclidGCD(unsigned int pui_Num1, unsigned int pui_Num2)
{
	unsigned int lui_Remainder = 0;

	while (pui_Num2 != 0)
	{
		lui_Remainder = pui_Num1 % pui_Num2;
		//
		pui_Num1 = pui_Num2;
		//
		pui_Num2 = lui_Remainder;
	}

	return (pui_Num1);
}

unsigned int fui_EuclidGCD_Recursive(unsigned int const puic_Num1, unsigned int const puic_Num2)
{
	// terminating condition
	if (puic_Num2 == 0)
		return (puic_Num1);

	return (fui_EuclidGCD_Recursive(puic_Num2, puic_Num1 % puic_Num2));
}