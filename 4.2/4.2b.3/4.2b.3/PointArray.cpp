//Purpose: The source file of PointArray
//Author: Tianyu Zhang
//Date: 06/12/18

#include "PointArray.h"
#include "Point.h"

// Constructors
PointArray::PointArray() : Array()	// Default constructor.
{ 
}

PointArray::PointArray(int size) : Array(size)
{
}

PointArray::PointArray(const PointArray& pp) : Array(pp)	// Copy constructor.
{ 
}

PointArray::~PointArray()	// Destructor.
{ 
}

PointArray& PointArray::operator = (const PointArray& source)	// Assignment operator
{ 

  // Exit if same
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Array<Point>::operator = (source);

	return *this;
}

double PointArray::Length() const
{
	double length = 0.0;

	for (int i = 0; i < Array<Point>::Size() - 1; i++)
	{
		length += (Array<Point>:: operator [] (i)).Distance(Array<Point>:: operator [] (i + 1));
	}

	return length;
}
