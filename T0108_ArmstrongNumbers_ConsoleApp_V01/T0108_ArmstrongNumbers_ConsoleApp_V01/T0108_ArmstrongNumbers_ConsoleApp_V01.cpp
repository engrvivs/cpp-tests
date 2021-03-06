// T0108_ArmstrongNumbers_ConsoleApp_V01.cpp 
// display all 3-digit Armstrong numbers

#include "pch.h"
#include <iostream>

// functions' definitions
bool fb_IsArmstrong(unsigned int const);

int main()
{
	// get the maximum limit
	unsigned int lui_Limit = 1000;
	std::cout << "Maximum Limit (0 to EXIT): "; std::cin >> lui_Limit;

	while (lui_Limit > 0)
	{
		std::cout << "\nArmstrong Numbers: ";
		//
		for (unsigned int lui_Num = 1; lui_Num < lui_Limit; ++lui_Num)
		{
			if (fb_IsArmstrong(lui_Num) == true)
				std::cout << lui_Num << ", ";
		}
		//
		std::cout << "\n\nMaximum Limit (0 to EXIT): "; std::cin >> lui_Limit;
	}
	//
	return (0);
}

// functions' declarations
bool fb_IsArmstrong(unsigned int const puic_Num)
{
	bool lb_GetNumOfDigits = true;
	unsigned short lusi_NumOfDigits = 0;
	unsigned int lui_SumOfDigitPower = 0;
	//
	// go through the number's digits
	do
	{
		unsigned int lui_Num = puic_Num;
		unsigned short lusi_Digit = 0;
		//
		while (lui_Num > 0)
		{
			// NOTE: but multiplications are FASTER than divisions and modulus
			//
			// extract last digit
			lusi_Digit = lui_Num % 10;
			//
			if (lb_GetNumOfDigits == true)
			{
				// get number of digits
				++lusi_NumOfDigits;
			}
			else if (lb_GetNumOfDigits == false)
			{
				// add this digit, powered by the number of digits
				lui_SumOfDigitPower += pow(lusi_Digit, lusi_NumOfDigits);
			}
			//
			// leave out this digit from the number
			lui_Num /= 10;
		}
		//
		// in the next iteration, get sum of digits, powered by the number of digits
		lb_GetNumOfDigits = false;
		//
	} while (lui_SumOfDigitPower == 0);
	//
	// is Armstrong?
	return (lui_SumOfDigitPower == puic_Num);
}