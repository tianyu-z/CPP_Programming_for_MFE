//Purpose: The test file of Variant
//Author: Tianyu Zhang
//Date: 07/05/18

#include <boost/variant.hpp>
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Visitor.h"
#include <string>
#include <iostream>
using namespace std;

typedef boost::variant<Point, Line, Circle> ShapeType;

ShapeType Create()
{
	ShapeType shape;

	// Requisite the user for the shape type to create.
	cout << "Please choose the shape:" << endl << "a Point; b Line; c Circle" << endl;
	char visitorchoice;
	cin >> visitorchoice;

	// Requested shape and return.
	switch (visitorchoice)
	{
	case 'a':
		shape = Point();
		break;
	case 'b':
		shape = Line();
		break;
	case 'c':
		shape = Circle();
		break;
	default:
		break;
	}

	return shape;
}

void main()
{
	using boost::variant;

	ShapeType result = Create();
	cout << result << endl;

	try
	{
		Line l1 = boost::get<Line>(result);
	}
	catch (boost::bad_get& err)
	{
		cout << "Error: " << err.what() << endl;
	}




	// Move the shape.
	Visitor visitor(5.1, 6.2);
	boost::apply_visitor(visitor, result);
	cout << result << endl;
}