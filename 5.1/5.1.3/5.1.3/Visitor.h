//Purpose: The head file of Visitor
//Author: Tianyu Zhang
//Date: 07/05/18

#ifndef Visitor_h
#define Visitor_h

#include <boost/variant/static_visitor.hpp>
#include "Point.h"
#include "Line.h"
#include "Circle.h"

class Visitor : public boost::static_visitor<void>
{
private:
	double m_dx;	// x-coordinate
	double m_dy;	// y-coordinate

public:
	// Constructors and destructor
	Visitor();	// Default constructor
	Visitor(const Visitor& source);		// Copy constructor
	Visitor(double xValue, double yValue);	// Constructor accepting x- and y-coordinates
	~Visitor();		// Destructor

					// Member operator overloading
	Visitor& operator = (const Visitor& source);	// Assignment operator
	void operator () (Point& p) const;	// () operator for Point
	void operator () (Line& p) const;	// () operator for Line
	void operator () (Circle& p) const;	// () operator for Circle
};

#endif