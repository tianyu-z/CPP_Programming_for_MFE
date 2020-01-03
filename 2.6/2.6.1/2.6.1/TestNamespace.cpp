//Purpose: The test for namespace
//Author: Tianyu Zhang
//Date: 05/12/18

#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Array.h"
#include <iostream>
#include <string>

void main()
{
	// The full namespace for Point class.
	ZTY::CAD::Point p1(1.1, 1.2);
	ZTY::CAD::Point p2(5.5, 6.2);
	cout << p1 << ", " << p2 << endl;

	// Using declaration for using a single class (Line).
	using ZTY::CAD::Line;
	cout << Line(p1, p2);

	// Using declaration for a complete namespace (Containers).
	using namespace ZTY::Containers;
	Array array1(3);
	array1[0] = ZTY::CAD::Point(4.1, 9.5);
	cout << array1[0] << endl;

	// Using the Circle class by creating a shorter alias.
	namespace ZCAD = ZTY::CAD;
	using ZCAD::Circle;
	Circle sc(ZCAD::Point(0, 0), 1);
	cout << sc;
}
