//Purpose: Test the source file of Points in 2 dimensions with distance function
//Author: Tianyu Zhang
//Date: 05/12/18

#include "Point.h"
#include "Line.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	double x1, y1;
	double x2, y2;
	cout << "Please input x and y of the start point in the following format:" << endl << "x y" << endl;
	//Ask users to set the point coordinates
	if (!(cin >> x1 >> y1))
	{
		cout << "Error in Input" << endl;
		return;
	}

	// Ask the user for the x- and y-coordinates of the end point.
	cout << "Please input x and y of the end point in the following format:"
		<< endl << "x y" << endl;

	if (!(cin >> x2 >> y2))
	{
		cout << "Input Error." << endl;
		return;
	}

	Point point1(x1, y1);	// Create a point object by using the default constructor
	Point point2(x2, y2);

	// Create the line object.
	Line line(point1, point2);

	cout << line.ToString() << ", " << "the length is " << line.Length() << "." << endl;
}