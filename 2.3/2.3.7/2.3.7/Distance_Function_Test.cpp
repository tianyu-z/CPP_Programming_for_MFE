//Purpose: Test the source file of Points in 2 dimensions with distance function
//Author: Tianyu Zhang
//Date: 05/12/18

#include "Point.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	double x1, y1;
	double x2, y2;
	cout << "Please input x1 and y1 in the following format:" << endl << "x1 y1" << endl;
	//Ask users to set the point coordinates
	if (!(cin >> x1 >> y1))
	{
		cout << "Error in Input" << endl;
		return;
	}

	Point point1(x1,y1);	// Create a point object by using the default constructor
					// Set the coordinates entered by the user.
	// Display the coordinate of the point
	cout << point1.ToString() << endl << point1.X() << " is the x-coordinate of point1." << endl << point1.Y() << " is the y-coordinate of point1." << endl;
	// Print the distance between the origin and point1.
	cout << point1.Distance() << " is the distance of point to the orign point." << endl;


	cout << "Please input x2 and y2 in the following format:" << endl << "x2 y2" << endl;
	//Ask users to set the point coordinates
	if (!(cin >> x2 >> y2))
	{
		cout << "Error in Input" << endl;
		return;
	}
	Point point2(x2,y2);	// Create a point object by using the default constructor
					// Set the coordinates entered by the user.

	// Display the coordinate of the point
	cout << point2.ToString() << endl << point2.X() << " is the x-coordinate of point2." << endl << point2.Y() << " is the y-coordinate of point2." << endl;
	// Print the distance between the origin and point2.
	cout << point2.Distance() << " is the distance of point to the orign point." << endl;
	// Print the distance between point1 and point2.
	cout << point1.Distance(point2) << " is the distance of point between point1 and point2." << endl;
	const Point cp(1.5, 3.9);
	//cp.X(0.3); ERROR
	cout << cp.X() << endl;
}

    // Result of running times of constructors and destructor:
	// Constructor that accepts x-coordinates and y-coordinates: 3 times
	// Destructor: 3 times
	// Sum of constructors running times = Sum of destructor running times 