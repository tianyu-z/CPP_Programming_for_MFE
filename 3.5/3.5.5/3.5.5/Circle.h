//Purpose: The head file of Circles in 2 dimensions with distance function
//Author: Tianyu Zhang
//Date: 05/12/18

#ifndef Circle_h
#define Circle_h

#include <iostream>
#include "Point.h"
#include "Shape.h"

using namespace std;

class Circle :public Shape//Set Circle class
{
private:
	Point m_c;
	double m_r;

public:
	Circle();	// Default constructor
	Circle(const Circle &circle);	// Constructor with a center point and radius
	Circle(Point CentrePoint, double r);	// Copy constructor
	virtual ~Circle();	// Destructor
	Point CentrePoint() const; double Radius() const;	// Getter functions for center and radius
	void CentrePoint(const Point &newC); void Radius(const double newR);	// Setter functions for center and radius

	// Getter functions for Diameter, Area and Circumference
	double Diameter() const;
	double Area() const;
	double Circumference() const;

	string ToString() const;	// Return description of the circle.
	bool operator == (const Circle& c) const; // Equally compare operator.
	Circle& operator = (const Circle& source); // Assignment operator.
	friend ostream& operator << (ostream& os, const Circle& c); // Send to ostream.

	void Draw() const;
};

#endif