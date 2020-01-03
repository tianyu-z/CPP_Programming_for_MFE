//Purpose: Test the source file of Circles in 2 dimensions with distance function
//Author: Tianyu Zhang
//Date: 05/12/18

#include "Point.h"
#include "Circle.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	double x,y;
	double r;
	cout << "Please input x and y of the centre point in the following format:" << endl << "x y" << endl;
	//Ask users to set the point coordinates
	if (!(cin >> x >> y))
	{
		cout << "Error in Input" << endl;
		return;
	}

	//Ask users to set the Radius
	cout << "Please input radius of the circle" << endl;
	if (!(cin >> r))
	{
		cout << "Input Error." << endl;
		return;
	}

	Point centrepoint(x, y);	// Create a point object by using the default constructor
	

	// Create the line object.
	Circle circle(centrepoint, r);

	cout << circle.ToString() << endl;
	cout << "Diameter: " << circle.Diameter() << endl;
	cout << "Area: " << circle.Area() << endl;
	cout << "Circumference: " << circle.Circumference() << endl;

}