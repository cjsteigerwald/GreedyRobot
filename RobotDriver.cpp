/*
	@file RobotDriver.cpp
	@author Chris Steigerwald CSS 342A
	Description:  RobotDriver class contains main() and is the driver for 
		Robot.cpp and Robot.h.  Displays prompt to user in console to enter 2 
		ordered	pairs in the form of x1 y1 x2 y2 and uses cin to to populate 
		variables and passes them to the Robot constructor and uses overloaded <<
		to display Robot to console that shows how many unique paths and the
		directions of each path. Includes "Robot.h"
	Assumptions:  that user knows how to enter data correctly (there is no
		error checking) and that amount of unique routes does not exceed
		the number of characters that can be held in a string, and that
		user will not enter coordinates sufficiently far apart that cause a
		stack overflow.
*/
#include <iostream>
#include "Robot.h"

int main()
{
	using std::cout;
	using std::cin;
	// local variables
	int x1;
	int y1;
	int x2;
	int y2;

	// user prompts for program
	cout << "\t\tWelcom to Greedy Robot!\n\n";
	cout << "Greedy Robot will take in two coordinates and display the" << endl
		<< "number of unique paths and directions between start location"
		<< " and goal.\n\n\n";
	cout << "Enter coordinates for robot to start and search for: \n";
	cout << "<x1 y1 x2 y2> and program will display results!\n";
	cin >> x1 >> y1 >> x2 >> y2;

	Robot rb(x1, y1, x2, y2);
	cout << rb << endl;

	cout << "Press any key to quit:";
	getchar();
	getchar();
	return 0;
}