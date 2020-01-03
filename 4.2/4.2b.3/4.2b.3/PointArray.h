//Purpose: The head file of PointArray
//Author: Tianyu Zhang
//Date: 06/12/18

#ifndef PointArray_h
#define PointArray_h

#include "Array.cpp"
#include "Point.h"

class PointArray : public Array<Point>
{
public:
	// Constructors
	PointArray();
	PointArray(int size);
	PointArray(const PointArray& pp);

	// Destructor
	~PointArray();

	// Member operator overloading
	PointArray& operator = (const PointArray& source);

	// Accessing functions
	double Length() const;
};

#endif