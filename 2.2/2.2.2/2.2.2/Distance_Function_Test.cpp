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

	Point point1;	// Create a point object by using the default constructor
					// Set the coordinates entered by the user.
	point1.SetX(x1);
	point1.SetY(y1);
	// Display the coordinate of the point
	cout << point1.ToString() << endl << point1.GetX() << " is the x-coordinate of point1" << endl << point1.GetY() << " is the y-coordinate of point1" << endl;
	// Print the distance between the origin and point1.
	cout << point1.DistanceOrigin() << " is the distance of point to the orign point." << endl;


	cout << "Please input x2 and y2 in the following format:" << endl << "x2 y2" << endl;
	//Ask users to set the point coordinates
	if (!(cin >> x2 >> y2))
	{
		cout << "Error in Input" << endl;
		return;
	}
	Point point2;	// Create a point object by using the default constructor
					// Set the coordinates entered by the user.
	point2.SetX(x2);
	point2.SetY(y2);
	// Display the coordinate of the point
	cout << point2.ToString() << endl << point2.GetX() << " is the x-coordinate of point2" << endl << point2.GetY() << " is the y-coordinate of point2" << endl;
	// Print the distance between the origin and point2.
	cout << point2.DistanceOrigin() << " is the distance of point to the orign point." << endl;
	// Print the distance between point1 and point2.
	cout << point1.Distance(point2) << " is the distance of point between point1 and point2." << endl;
}