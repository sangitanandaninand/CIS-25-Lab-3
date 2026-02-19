# CIS-25-Lab-3: Temperature Logger and Analyzer

## Program 1: TempLogger.cpp

```cpp
# CIS-25-Lab-3: Temperature Logger, Analyzer, and Sum of Numbers

This repository contains three C++ programs for the lab assignment:

- `TempLogger.cpp` — prompts for daily high temperatures and writes them to `temperatures.txt`.
- `TempAnalyzer.cpp` — reads `temperatures.txt` and computes the average temperature.
- `SumOfNumbers.cpp` — sums positive integers until a negative sentinel is entered.

### TempLogger.cpp
```cpp
#include <iostream>
#include <fstream>
#include <limits>

int main()
{
	int userInput = 0;
	double temps[999];

	std::cout << "How many days? ";
	if (!(std::cin >> userInput)) return 1;
	if (userInput <= 0 || userInput > 999) return 1;

	for (int i = 0; i < userInput; ++i) {
		std::cout << "Enter temperature for day " << (i + 1) << ": ";
		if (!(std::cin >> temps[i])) return 1;
	}

	std::ofstream outputFile("temperatures.txt");
	if (!outputFile) return 1;

	for (int i = 0; i < userInput; ++i) outputFile << temps[i] << '\n';
	return 0;
}
```

### TempAnalyzer.cpp
```cpp
#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	std::ifstream inFile("temperatures.txt");
	if (!inFile) return 1;

	double temp; int count = 0; double sum = 0.0;
	while (inFile >> temp) { sum += temp; ++count; }
	if (count > 0) {
		double average = sum / count;
		std::cout << "Temperatures analyzed for " << count << " days." << std::endl;
		std::cout << "The average temperature was: " << std::fixed << std::setprecision(1) << average << std::endl;
	}
	return 0;
}
```

### SumOfNumbers.cpp
```cpp
#include <iostream>

int main()
{
	int value = 0; int sum = 0;
	while (true) {
		std::cout << "Enter a positive number to add to the sum, or a negative number to quit: ";
		if (!(std::cin >> value)) return 1;
		if (value < 0) break;
		sum += value;
	}
	std::cout << "\nThe final sum is: " << sum << std::endl;
	return 0;
}
```

## Contributors

- **Sangita Nandan** — Implemented `TempLogger.cpp`, `TempAnalyzer.cpp`, and `SumOfNumbers.cpp`. Prepared README and project structure.


```cpp

#include <iostream>

