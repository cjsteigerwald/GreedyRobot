/*
	@file Robot.h
	@name Chris Steigerwald CSS 342A
	Description:  the Robot.h is the header file for the Robot class.  The Robot
		class takes in 4 int parameters startX, startY, goalX, goalY and creates
		ordered pairs for a start location (startX, startY) and goal location
		(goalX, goalY).  The Robot class contains a default constructor that
		sets both ordered pairs to 0,0.  The overloaded constructor takes in
		4 int parameters and sets them in this order: startX, startY, goalX,
		and goalY.  Constructors passes user input into CheckInput() to 
		validate that ordered pairs are not the same.  If the same message is
		sent to console for user.  If ordered pairs are different ordered pairs
		are sent to  FindPaths() a recursive function that determine the number
		of unique paths and directions for each unique path between start
		position and goal.
	Assumptions:  that user knows how to enter data correctly (there is no
		error checking) and that amount of unique routes does not exceed
		the number of characters that can be held in a string, and that
		user will not enter coordinates sufficiently far apart that cause a
		stack overflow.
*/

#ifndef ROBOT_H_
#define ROBOT_H_
#include <iostream>
#include <string>
using namespace std;

class Robot
{
public:
	Robot();
	Robot(int x1, int y1, int x2, int y2);	
	friend std::ostream & operator<<(std::ostream & is, Robot & rb);
	void FindPaths(int x1, int y1, int x2, int y2, int *count, string &answer, string *ptr);
	~Robot();

private:
	int startX;
	int startY;
	int goalX;
	int goalY;
	int count;
	int *ptrCount;
	string *ptr;
	string path;
	string answer;
	void CheckInput(int x1, int y1, int x2, int y2, int *count, string & ans, string *ptr);
		
	void RobotNorth(int x1, int y1, int x2, int y2, int *count, string &ans, string *ptr);
	void RobotSouth(int x1, int y1, int x2, int y2, int *count, string &ans, string *ptr);
	void RobotEast(int x1, int y1, int x2, int y2, int *count, string &ans, string *ptr);
	void RobotWest(int x1, int y1, int x2, int y2, int *count, string &ans, string *ptr);
};
#endif // !ROBOT_H_