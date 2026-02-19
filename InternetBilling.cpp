#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char package;
	int hours;
	double bill_total;

	// Print the menu package
	cout << "Internet Service Provider Billing" << endl;
	cout << "Package A: For $9.95 per month 10 hours of access are provided. Additional hours are $2.00 per hour." << endl;
	cout << "Package B: For $14.95 per month 20 hours of access are provided. Additional hours are $1.00 per hour." << endl;
	cout << "Package C: For $19.95 per month unlimited access is provided." << endl;
	cout << "----------------------------------------------" << endl;

	// Ask the user to enter the package choice
	cout << "Select a subscription package (A, B, or C): ";
	cin >> package;

	// Validate the package choice
	if (package != 'A' && package != 'B' && package != 'C' &&
		package != 'a' && package != 'b' && package != 'c') {
		cout << "Invalid package choice. Please run the program again and select A, B, or C." << endl;
		return 1; // Finish the program
	}

	// Ask the user to enter the number of hours used
	cout << "Enter the number of hours used: ";
	cin >> hours;

	// Validate the numbers of hours used
	if (hours < 0 || hours > 744) {
		cout << "Invalid number of hours." << endl;
		return 1; // Finish the program
	}

	// Calculate the total bill based on the package choice
	if (package == 'A' || package == 'a') {
		bill_total = 9.95;
		if (hours > 10) {
			bill_total += (hours - 10) * 2.00;
		}
	}
	else if (package == 'B' || package == 'b') {
		bill_total = 14.95;
		if (hours > 20) {
			bill_total += (hours - 20) * 1.00;
		}
	}
	else { // Package C
		bill_total = 19.95;
	}

	// Display the total bill, formatted to two decimal places
	cout << fixed << setprecision(2);
	cout << "\nYour total amount due is: $" << bill_total << endl;

	return 0;
}

// Example Output 1 (Package B with overage):
// Select a subscription package (A, B, or C): B
// Enter the number of hours used: 25
//
// Your total amount due is: $19.95
//
// Example Output 2 (Invalid Input):
// Select a subscription package (A, B, or C): Z
// Invalid package choice. Please run the program again and select A, B, or C.