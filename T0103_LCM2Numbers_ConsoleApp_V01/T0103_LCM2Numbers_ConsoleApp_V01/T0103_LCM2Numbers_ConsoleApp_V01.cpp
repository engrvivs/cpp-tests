// T0103_LCM2Numbers_ConsoleApp_V01.cpp 
// find Least Common Multiple of any two given positive integers
// provides various different options for calcuation

#include "stdafx.h"
#include <iostream>

// functions' declarations
unsigned int fui_LCM(unsigned int const, unsigned int const);
unsigned int fui_EuclidGCD(unsigned int, unsigned int);
unsigned int fui_LCMfromGCD(unsigned int const, unsigned int const);

int main()
{
	// get the two inputs
	unsigned int lui_Num1 = 1,
				 lui_Num2 = 1;
	std::cout << "Positive Number 1: "; std::cin >> lui_Num1;
	std::cout << "Positive Number 2: "; std::cin >> lui_Num2;

	// get LCM calculation option
	unsigned short int lusi_Option = 1;
	std::cout << "\n\n*** LCM Calculation ***";
	std::cout << "\n1. Normal Looping";
	std::cout << "\n2. from GCD";
	std::cout << "\nEnter 0 to EXIT";
	//
	std::cout << "\nEnter your option: "; std::cin >> lusi_Option;
	//
	while (lusi_Option > 0)
	{
		// calculate LCM
		unsigned int lui_LCM = 1;
		switch (lusi_Option)
		{
			case 1:
				lui_LCM = fui_LCM(lui_Num1, lui_Num2); 
				break;
			default:
				lui_LCM = fui_LCMfromGCD(lui_Num1, lui_Num2);
		}
		//
		std::cout << "LCM = " << lui_LCM << "\n";
		//
		std::cout << "\nEnter your option: "; std::cin >> lusi_Option;
	}

	return 0;
}

// functions' definitions
unsigned int fui_LCM(unsigned int const puic_Num1, 
					 unsigned int const puic_Num2)
{
	// initialize with largest of the two input numbers
	unsigned int rui_LCM = (puic_Num1 > puic_Num2) ? puic_Num1
												   : puic_Num2;
	// check for LCM
	for (; rui_LCM < (puic_Num1 * puic_Num2); ++rui_LCM)
	{
		// if it is divisible by BOTH numbers
		if ((rui_LCM % puic_Num1 == 0)
		 && (rui_LCM % puic_Num2 == 0))
		{
			// LCM found
			return (rui_LCM);
		}
	}

	return (0);
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

unsigned int fui_LCMfromGCD(unsigned int const puic_Num1, 
							unsigned int const puic_Num2)
{
	// get GCD of the two input numbers
	unsigned int lui_GCD = fui_EuclidGCD(puic_Num1, puic_Num2);
	//
	if (lui_GCD > 0)
		return ((puic_Num1 * puic_Num2) / lui_GCD);

	return (0);
}