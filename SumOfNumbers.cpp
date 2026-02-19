
#include <iostream>

/*
 SumOfNumbers.cpp

 Objective: Ask the user for a series of positive numbers and calculate their sum.
 The program continues until the user enters a negative number.
*/

int main()
{
	int value = 0;
	int sum = 0;

	while (true) {
		std::cout << "Enter a positive number to add to the sum, or a negative number to quit: ";
		if (!(std::cin >> value)) {
			std::cerr << "Invalid input. Exiting." << std::endl;
			return 1;
		}
		if (value < 0) break; // sentinel: stop and do not include
		sum += value;
	}

	std::cout << "\nThe final sum is: " << sum << std::endl;
	return 0;
}
	}

