# CIS-25-Lab-3: Temperature Logger and Analyzer

## Overview
This lab consists of two C++ programs: a temperature logger that records daily high temperatures to a file, and an analyzer that reads the file and calculates the average temperature.

## Program 1: TempLogger.cpp

```cpp
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int numDays;
	
	cout << "How many days of temperatures would you like to record? ";
	cin >> numDays;
	
	ofstream outputFile("temperatures.txt");
	
	for (int i = 1; i <= numDays; i++)
	{
		double temperature;
		cout << "Enter temperature for Day " << i << ": ";
		cin >> temperature;
		outputFile << temperature << endl;
	}
	
	outputFile.close();
	
	return 0;
}
```

## Program 2: TempAnalyzer.cpp

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inFile("temperatures.txt");
	
	if (!inFile.is_open())
	{
		cout << "Error temperatures.txt not found. Please run TempLogger first." << endl;
		return 1;
	}
	
	double temp;
	int count = 0;
	double sum = 0.0;
	
	while (inFile >> temp)
	{
		sum += temp;
		count++;
	}
	
	inFile.close();
	
	if (count > 0)
	{
		double average = sum / count;
		cout << "Temperatures analyzed for " << count << " days." << endl;
		cout << "The average temperature was: " << fixed << setprecision(1) << average << endl;
	}
	else
	{
		cout << "No temperatures found in the file." << endl;
	}
	
	return 0;
}
```

## Expected Output

When running with 5 temperature readings (22.5, 23.1, 21.8, 24.0, 22.3):

```
Temperatures analyzed for 5 days.
The average temperature was: 22.7
```

