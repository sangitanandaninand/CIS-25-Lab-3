
#include <iostream>
#include <fstream>
#include <limits>

int main()
{
	int userInput = 0;
	double temps[999];

	std::cout << "How many days? ";
	if (!(std::cin >> userInput)) {
		std::cerr << "Invalid input.\n";
		return 1;
	}
	if (userInput <= 0 || userInput > 999) {
		std::cerr << "Number of days must be between 1 and 999.\n";
		return 1;
	}

	for (int i = 0; i < userInput; ++i) {
		std::cout << "Enter temperature for day " << (i + 1) << ": ";
		if (!(std::cin >> temps[i])) {
			std::cerr << "Invalid temperature input.\n";
			return 1;
		}
	}

	std::ofstream outputFile("temperatures.txt");
	if (!outputFile) {
		std::cerr << "Failed to open temperatures.txt for writing.\n";
		return 1;
	}

	for (int i = 0; i < userInput; ++i) {
		outputFile << temps[i] << '\n';
	}

	return 0;
}