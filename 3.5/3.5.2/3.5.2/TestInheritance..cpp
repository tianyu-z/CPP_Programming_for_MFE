//Purpose: Test program for inheritance.
//Author: Tianyu Zhang
//Date: 07/01/18

#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	Line l(Point(1, 2), Point(3, 4)); // Create line.

	cout << s.ToString() << endl; // Print shape.

								  // ID printed when printing a point.
	cout << p.ToString() << endl; // Print point.

								  // ID printed when printing a line.
	cout << l.ToString() << endl; // Print line

	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work? This works.
	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work? This works.
	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible? This is possible.

			 // The ToString() function of Point is called when using a Shape* that contains a Point
			 // ID printed when printing a point.
	cout << sp->ToString() << endl; // What is printed? Point(10,20)

									// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call
										   // the base class assignment in point?
										   // Yes, the ID is copied.
}