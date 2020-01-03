//Purpose: Test the source file of Points in 2 dimensions
//Author: Tianyu Zhang
//Date: 05/12/18

#include "Point.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	double newX, newY;
	cout << "Please input x and y in the following format:" << endl << "x y" << endl;
	//Ask users to set the point coordinates
	if (!(cin >> newX >> newY))
	{
		cout << "Error in Input" << endl;
		return;
	}

	Point point;	// Create a point object by using the default constructor
					// Set the coordinates entered by the user.
	point.SetX(newX);
	point.SetY(newY);
					// Display the coordinate of the point
	cout << point.ToString() << endl << point.GetX() << " is the x-coordinate of the point" << endl << point.GetY() << " is the y-coordinate of the point" << endl;
}