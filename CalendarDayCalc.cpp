// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++: From control structures through objects. Pearson. 
// http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw for output width
#include <string>   // To implement to_string function
using namespace std;

// Global Constant Initialization
const string TITLE = "Virtual Calendar Day Calculator";
const string AUTHOR_LINE = "By Forrest Moulin";
const int MONTH_DAYS = 31;

// Prototype(s) to notify compiler
bool keepLooping();
bool isLeapYear(int year);
int getMonthVal(int month, int year);
int getCenturyVal(int year);
int getYearVal(int year);

int main()
{
	// Dynamic Variable Initialization
	int month, day, monthDays, year;
	int dayVal, monthVal, yearVal, centuryVal;
	bool validDay = false, validMonth = true;
	bool validDate = false;
	bool leapYearBool = false;
	bool keepLoop = true;

	cout << TITLE << endl
		<< AUTHOR_LINE << endl;

	// Program Logic
	while (validDate != 1 || keepLoop != 0)
	{
		// Reset values on each loop iteration
		month = 0, day = 0, monthDays = 31, year = 0;
		dayVal = 0, monthVal = 0; yearVal = 0; centuryVal = 0;
		cout << endl << "Please enter a date in MM DD YYYY format."
			<< endl << "Example: 12 31 2022" << endl << endl;

		// Read date from user input
		cin >> month >> day >> year;

		// Visibility of program status
		cout << endl << left << setw(15) << "Month entered: " << month;
		cout << endl << left << setw(15) << "Day entered: " << day;
		cout << endl << left << setw(15) << "Year entered: " << year
			<< endl << endl;

		// Month validation
		if (month > 0 && month <= 12)
		{
			validMonth = 1;
		}
		else {
			cout << "Invalid month." << endl
				<< "(The month should be and integer from 1 to 12)"
				<< endl;
			validMonth = 0;
			continue;
		}

		// Day validation
		if (day <= 0 || day > 31)
		{
			cout << "Invalid day." << endl
				<< "(The day should be an integer from 1 to 31)"
				<< endl;
			validDay = 0;
			continue;
		}
		else {
			// Cases 1, 3, 5, 7, 8, 10, 12
			// have 31 days
			monthDays = MONTH_DAYS;
			switch (month)
			{
			case 1:
				break;
			case 2: 
				if (leapYearBool == 1)
				{
					monthDays -= 2;
				}
				else
				{
					monthDays -= 3;
				}
				break;
			case 3:
				break;
			case 4:
				monthDays -= 1;
				break;
			case 5:
				break;
			case 6: 
				monthDays -= 1;
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				monthDays -= 1;
				break;
			case 10:
				break;
			case 11:
				monthDays -= 1;
				break;
			case 12:
				break;
			default:
				monthDays = 0;
			}

			if (monthDays >= day) {
				validDay = 1;
			}
			else {
				cout << "Invalid days for the month entered." << endl;
				validDay = 0;
				continue;
			}
		}
		// Check for Leap Year/Day
		if (leapYearBool == 1)
		{
			cout << "It's a valid Leap Year!" << endl << endl;
		}
		if (day >= 29 && month == 2)
		{
			if (day == 29 && leapYearBool == 1)
			{
				cout << "Happy Leap Day!" << endl << endl;
			}
			else
			{
				validDay = 0;
				cout << "February cannot have more than 28 days,"
					<< endl << "except for Leap Year (29 days)."
					<< endl;
				continue;
			}
		}
		// Year validation
		if (year < 0)
		{
			cout << "Invalid year." << endl
				<< "The year must be an integer greater than"
				<< endl << "or equal to 0 (YYYY)."
				<< endl;
			continue;
		}
		else {
			if (validDay == 1 && validMonth == 1)
			{
				cout << "Date is valid :)" << endl
					<< endl;
				validDate = 1;

				// Function calls
				monthVal = getMonthVal(month, year);
				leapYearBool = isLeapYear(year);
				yearVal = getYearVal(year);
				centuryVal = getCenturyVal(year);

				// Calculate the day value to determine day of week
				dayVal = day + monthVal + yearVal + centuryVal;
				// Get the remainder of sum divided by 7
				// Resulting int is the day of the week
				// 0 - Sun, 1 - Mon, etc.
				dayVal %= 7;

				cout << "Day of the week: ";
				// Switch actions based on dayVal (0-6)
				switch (dayVal)
				{
				case 0:
					cout << "Sunday" << endl << endl;
					break;
				case 1:
					cout << "Monday" << endl << endl;
					break;
				case 2:
					cout << "Tuesday" << endl << endl;
					break;
				case 3:
					cout << "Wednesday" << endl << endl;
					break;
				case 4:
					cout << "Thursday" << endl << endl;
					break;
				case 5:
					cout << "Friday" << endl << endl;
					break;
				case 6:
					cout << "Saturday" << endl << endl;
					break;
				default:
					cout << "ERROR" << endl << endl;
					break;
				}
			}
		}
		// Reset bool variables
		validDay = 0;
		validMonth = 0;
		validDate = 0;
		keepLoop = keepLooping();
		// Keep looping if users enters y
		if (keepLoop == 0)
		{
			break;
		}
	}
}
// Returns boolean value designating leap year
// 0 - Not Leap Year, 1 - Leap Year
bool isLeapYear(int year)
{
	static bool isLeap = 0;
	if (year % 400 == 0 || 
		(year % 4 == 0 && year % 100 != 0))
	{
		isLeap = 1;
	}
	return isLeap;
}
// Returns integer for calculated month value
int getMonthVal(int month, int year)
{
	static int monthVal = 0;
	static bool isLeap = 0;
	isLeap = isLeapYear(year);

	switch (month)
	{
	// Month values are affected on leap years
    // only in Jan and Feb
	case 1:
		if (isLeap == 0)
		{
			monthVal = 0;
		}
		else {
			monthVal = 6;
		}
		break;
	case 2:
		if (isLeap == 0)
		{
			monthVal = 3;
		}
		else {
			monthVal = 2;
		}
		break;
	case 3:
		monthVal = 3;
		break;
	case 4:
		monthVal = 6;
		break;
	case 5:
		monthVal = 1;
		break;
	case 6:
		monthVal = 4;
		break;
	case 7:
		monthVal = 6;
		break;
	case 8:
		monthVal = 2;
		break;
	case 9:
		monthVal = 5;
		break;
	case 10:
		monthVal = 0;
		break;
	case 11:
		monthVal = 3;
		break;
	case 12:
		monthVal = 5;
		break;
	default:
		monthVal = 0;
		break;
	}
	return monthVal;
}
// Returns integer for calculated year value
int getYearVal(int year)
{
	static int yearVal = 0;
	static int quarterVal = 0;
	// Remove first 2 digits
	yearVal = year % 100;
	quarterVal = yearVal / 4;
	// Account for Leap Year
	yearVal += quarterVal;
	return yearVal;
}
// Returns integer for calculated century value
int getCenturyVal(int year)
{
	static int centuryVal = 0;
	static int remainder = 0;
	// Remove last 2 digits 
	centuryVal = year / 100;
	// Find remainder after dividing by 4
	remainder = centuryVal % 4;
	// Subtract remainder from 3, 
	// multiply result by 2
	centuryVal = (3 - remainder) * 2;
	return centuryVal;
}
// Returns boolean value (0 stop, 1 keep looping)
bool keepLooping()
{
	static bool keepLoopBool;
	static bool validEntry = 0;
	static char userInputChar;
	// Loop until entry is valid
	while (validEntry == 0)
	{
		cout << "Would you like to enter another date?"
			<< endl << "(Y for yes, N for no)"
			<< endl << endl;
		cin >> userInputChar;
		// User enters Y or y
		if (userInputChar == 'y'
			|| userInputChar == toupper('y'))
		{
			validEntry = 1;
			keepLoopBool = 1;
		}
		// User enters N or n
		else if (userInputChar == 'n'
			|| userInputChar == toupper('n')) {
			validEntry = 1;
			cout << endl << "Closing the program..." << endl
				<< "Until next time!" << endl;
			keepLoopBool = 0;
		}
		// Invalid data handling
		else {
			cout << endl << "Invalid entry." << endl;
		}
	}
	// Reset valid entry bool after loop finishes
	validEntry = 0;
	return keepLoopBool;
}

/*
* CONSOLE OUTPUT
* Virtual Calendar Day Calculator
* By Forrest Moulin
*
* Please enter a date in MM DD YYYY format.
* Example: 12 31 2022
*
* 10 23 2022
*
* Month entered: 10
* Day entered:   23
* Year entered:  2022
*
* Date is valid :)
*
* Day of the week: Sunday
*
* Would you like to enter another date?
* (Y for yes, N for no)
*
* y
*
* Please enter a date in MM DD YYYY format.
* Example: 12 31 2022
*
* 40 23 2022
*
* Month entered: 40
* Day entered:   23
* Year entered:  2022
*
* Invalid month.
* (The month should be and integer from 1 to 12)
*
* Please enter a date in MM DD YYYY format.
* Example: 12 31 2022
*
* 10 40 2022
*
* Month entered: 10
* Day entered:   40
* Year entered:  2022
*
* Invalid day.
* (The day should be an integer from 1 to 31)
*
* Please enter a date in MM DD YYYY format.
* Example: 12 31 2022
*
* 10 23 -1000
*
* Month entered: 10
* Day entered:   23
* Year entered:  -1000
*
* Invalid year.
* The year must be an integer greater than
* or equal to 0 (YYYY).
*
* Please enter a date in MM DD YYYY format.
* Example: 12 31 2022
*
* 11 31 2022
*
* Month entered: 11
* Day entered:   31
* Year entered:  2022
*
* Invalid days for the month entered.
*
* Please enter a date in MM DD YYYY format.
* Example: 12 31 2022
*
* 12 31 2022
*
* Month entered: 12
* Day entered:   31
* Year entered:  2022
*
* Date is valid :)
*
* Day of the week: Saturday
*
* Would you like to enter another date?
* (Y for yes, N for no)
*
* n
*
* Closing the program...
* Until next time!
*/
