/*
	@file Robot.cpp
	@name Chris Steigerwald CSS 342A
	Description:  the Robot.cpp classes implements the Robot.h.  Included are
		constructors, public and private methods.
	Assumptions:  that user knows how to enter data correctly (there is no
		error checking) and that amount of unique routes does not exceed
		the number of characters that can be held in a string, and that
		user will not enter coordinates sufficiently far apart that cause a
		stack overflow.
*/
#include "Robot.h"
/*
	****************** Class Constructors ***************************
*/
// Robot class default constructor
Robot::Robot()
{
	startX = 0;
	startY = 0;
	goalX = 0;
	goalY = 0;
	count = 0;	
	ptr = &path;
	ptrCount = &count;	
	CheckInput(startX, startY, goalX, goalY, ptrCount, answer, ptr);
}	// end constructor
// Robot class override constructor
Robot::Robot(int x1, int y1, int x2, int y2)
{
	startX = x1;
	startY = y1;
	goalX = x2;
	goalY = y2;
	count = 0;	
	ptr = &path;
	ptrCount = &count;
	CheckInput(startX, startY, goalX, goalY, ptrCount, answer, ptr);
}	// end constructor
// Robot class destructor
Robot::~Robot()
{
}	// end destructor
/*
	******************** Class: Private Methods *********************
*/
// Validates input, if start and stop coordinates are equal returns 0 paths, else
// if start and stop coordinates are not equal passes all parameters to FindPaths()
void Robot::CheckInput(int startX, int startY, int goalX, int goalY, int *ptrCount, string &ans, string *ptr )
{
	if ( (startX == goalX) && (startY == goalY) )
	{
		*ptrCount = 0;
		*ptr = "Start and Goal are the same!";
	}
	else
		return FindPaths(startX, startY, goalX, goalY, ptrCount, ans, ptr);
}	// end CheckInput

// Simulates moving Robot North and returns to FindPaths()
void Robot::RobotNorth(int x1, int y1, int x2, int y2, int *ptrCount, string &ans, string *ptr)
{
	FindPaths(x1, y1 + 1, x2, y2, ptrCount, ans + "N", ptr);
}	// end RobotNorth

// Simulates moving Robot South and returns to FindPaths()
void Robot::RobotSouth(int x1, int y1, int x2, int y2, int *ptrCount, string &ans, string *ptr)
{
	return FindPaths(x1, y1 - 1, x2, y2, ptrCount, ans + "S", ptr);
}	// end RobotSouth

// Simulates moving Robot East and returns to FindPaths()
void Robot::RobotEast(int x1, int y1, int x2, int y2, int *ptrCount, string &ans, string *ptr)
{
	return FindPaths(x1 + 1, y1, x2, y2, ptrCount, ans + "E", ptr);
}	// end RobotEast

// Simulates moving Robot West and returns to FindPaths()
void Robot::RobotWest(int x1, int y1, int x2, int y2, int *ptrCount, string &ans, string *ptr)
{
	return FindPaths((x1 - 1), y1, x2, y2, ptrCount, ans + "W", ptr);
}	// end RobotWest

// FindPaths() is a recursive function that solves how many unique paths are 
// between the start coordinates and goal coordinates.  It makes calls to:
// RobotNorth to simulate moving North, RobotSouth to simulate moving South
// RobotEast to simulate moving East, and RobotWest to simulate moving West.
// Each time the function finds a unique path the counter is updated through
// *ptrCount (pointer to class int count) and the directions are saved using 
// *ptr (pointer to class string path)
void Robot::FindPaths(int x1, int y1, int x2, int y2, int *ptrCount, string &ans, string *ptr)
{
	// if unique path is found update class variables: counter and path
	if(x1 == x2 && y1 == y2)
	{
		*ptrCount += 1;
		// adding new line character to ans string
		ans = ans + "\n";
		// using pointer to fill paths string in main
		*ptr += ans;		
	}
		// if Robot is South of Target
		if (y1 < y2) 
		{
			if (x1 < x2)
			{
				// move East				
				RobotEast(x1, y1, x2, y2, ptrCount, ans, ptr);
			}
			else if (x1 > x2)
			{
				// move West
				RobotWest(x1, y1, x2, y2, ptrCount, ans, ptr);
			}
			// move North			
			return RobotNorth(x1, y1, x2, y2, ptrCount, ans, ptr);
			
		} // end if (y1 < y2) 

		// if Robot is South of Target
		else if (y1 > y2)
		{
			if (x1 < x2)
			{
				// move East				
				RobotEast(x1, y1, x2, y2, ptrCount, ans, ptr);
			}
			else if (x1 > x2)
			{
				// move West
				RobotWest(x1, y1, x2, y2, ptrCount, ans, ptr);
			}
			// move South			
			return RobotSouth(x1, y1, x2, y2, ptrCount, ans, ptr);
		} // end else if (y1 > y2)

		// if Robot is West of Target
		else if ( x1 < x2) 
		{
			if (y1 < y2)
			{
				// move North				
				RobotNorth(x1, y1, x2, y2, ptrCount, ans, ptr);
			}
			else if (y2 > y2)
			{
				// move South
				return RobotSouth(x1, y1, x2, y2, ptrCount, ans, ptr);
			}
			
			// move East				
			return RobotEast(x1, y1, x2, y2, ptrCount, ans, ptr);
		} // end else if ( x1 < x2) 
			
		// if Robot is East of Target
		else if (x1 > x2)
		{
			if (y1 < y2)
			{
				// move North			
				return RobotNorth(x1, y1, x2, y2, ptrCount, ans, ptr);
			}
			else if (y1 > y2)
			{
				// move South
				return RobotSouth(x1, y1, x2, y2, ptrCount, ans, ptr);
			}
			// move West
			RobotWest(x1, y1, x2, y2, ptrCount, ans, ptr);
		} // else if (x1 > x2)		
}	// FindPaths
/*
	*************** Class: Public / Friend Method *****************
*/

// overloaded << friend function for printing a robot object to console
std::ostream & operator<<(std::ostream & os, Robot & rb)
{
	os << "Number of Paths: " << rb.count << endl;
	os << rb.path << endl;
	return os;
} // end operator<<