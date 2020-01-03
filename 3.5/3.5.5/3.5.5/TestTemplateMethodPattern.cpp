//Purpose: The test file of Template Method Pattern
//Author: Tianyu Zhang
//Date: 07/01/18


#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Point p(0.1, 0.2);
	Line l(Point(0.0, 0.5), Point(2.1, 3.3));
	p.Print();
	l.Print();
	// It prints the right information even when point and line do not have the Print() function.
}