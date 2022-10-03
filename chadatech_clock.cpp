/*
 * CS210_Project_One_DLUDWIG
 * Date: 07/17/2022
 * Name: Deonne Ludwig
 *
 */

#define _CRT_SECURE_NO_WARNINGS // to be able to use localtime without error
#include<iostream> // to be able to use cout, cin, endl, etc.
#include<iomanip> // to be able to use setfill, setw, etc.
#include<ctime> // to be able to use local time information
#include <string> //to be able to use more than one character
#include <Windows.h> // to be able to clear screen

using namespace std; // allow to apply std without typing

void displayClock(double hours, double minutes, double seconds)
{//function to display clock with current time in 12 and 24 hour requested format with stars
	string amPm; // add am and pm to display
	if (hours <= 12)
		amPm = "AM";
	else
		amPm = "PM";

	if (hours > 12) //to change 24 hour to 12 hour
		hours = hours - 12;
	else
		hours = hours;

	cout << setfill('*')
		<< setw(35);
	cout << "          ";
	cout << setfill('*')
		<< setw(26);
	cout << " " << endl;
	cout << "*     12-Hour Clock     *          *     24-Hour Clock     *" << endl;
	cout << setfill('0');
	cout << "*       " << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << " " << amPm << "    "
		<< " *"
		<< "          "
		<< "*       " << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << "        *" << endl;
	cout << setfill('*')
		<< setw(35);
	cout << "          ";
	cout << setfill('*')
		<< setw(26);
	cout << " " << endl;
}


void clockMenu() //function to display menu for input from user
{
	cout << "\n    **************************";
	cout << "\n    * 1-Add One Hour         *";
	cout << "\n ";
	cout << "\n    * 2-Add One Minute       *";
	cout << "\n ";
	cout << "\n    * 3-Add One Second       *";
	cout << "\n ";
	cout << "\n    * 4-Exit Program         *";
	cout << "\n    **************************";
	cout << "\n    Enter your choice : ";
	cout << "\n ";
	cout << "\n ";
}



int main() //beginning of program
{
	time_t currentTime = time(0); // to pull time and assign to variables to use and manipulate
	int hours, minutes, seconds;
	tm* t = localtime(&currentTime);
	hours = t->tm_hour;
	minutes = t->tm_min;
	seconds = t->tm_sec;

	int userChoice = 0; //variable for user input from menu

	while (userChoice != 4) { //while loop for user to choose 1-4 from menu
		displayClock(hours, minutes, seconds); //call function to show clocks
		clockMenu(); //call function to show menu
		Sleep(1000); //wait one second
		system("cls"); //clear screen
		displayClock(hours, minutes, seconds); //call function to show clocks
		clockMenu(); //call function to show menu

		cin >> userChoice; //get user input

		if (userChoice == 1) {
			hours = hours + 1; //increases time by 1 hour
		}
		else if (userChoice == 2) {
			minutes = minutes + 1; //increases minutes by 1 minute
		}
		else if (userChoice == 3) {
			seconds = seconds + 1; //increases seconds by 1 second
		}
		else {
			cout << endl; //invalid input ends
		}

	}

	cout << "Goodbye" << endl; // user choose 4 end statement

	return 0; //ends program
}