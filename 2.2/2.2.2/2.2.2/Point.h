//Purpose: The head file of Points in 2 dimensions with distance function
//Author: Tianyu Zhang
//Date: 05/12/18

#ifndef Point_h
#define Point_h

#include <iostream>
using namespace std;

class Point	//Set a new class
{
private:	//construct private variables
	double m_x;	//x-coordinate
	double m_y;	//y-coordinate


public:		
	Point();//Default constructor
	~Point();	//Destructor

	double GetX(); double GetY();	//A function to get the value of X and Y

	void SetX(double newX); void SetY(double newY);	//A function to set the value of X and Y

	string ToString();	//To display the point by string

	double DistanceOrigin(); // Calculate the distance to the origin (0, 0)
	double Distance(Point p); // Calculate the distance between two points
};
#endif