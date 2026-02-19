#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	std::ifstream inFile("temperatures.txt");
	if (!inFile) {
		std::cerr << "Error: temperatures.txt not found. Please run TempLogger first." << std::endl;
		return 1;
	}

	double temp;
	int count = 0;
	double sum = 0.0;

	while (inFile >> temp) {
		sum += temp;
		++count;
	}

	if (count > 0) {
		double average = sum / count;
		std::cout << "Temperatures analyzed for " << count << " days." << std::endl;
		std::cout << "The average temperature was: " << std::fixed << std::setprecision(1) << average << std::endl;
	} else {
		std::cout << "No temperatures found in the file." << std::endl;
	}

	return 0;
}