//Purpose: The source file of Points in 2 dimensions with distance function
//Author: Tianyu Zhang
//Date: 06/12/18

#include <sstream>
#include "Point.h"
#include <cmath>

using namespace std;

Point::Point():Shape()	// Default constructor
{

}

Point::Point(const Point &point): Shape(),m_x(point.m_x),m_y(point.m_y)
{

}
Point::Point(double xValue, double yValue) : Shape(),m_x(xValue), m_y(yValue) // Constructor that accepts x-coordinates and y-coordinates
{

}

Point::~Point()	// Destructor
{

}

string Point::ToString() const
{
	stringstream s_string;
	std::string s = Shape::ToString();
	s_string << "Point(" << m_x << "," << m_y << ")";
	return s_string.str();
}

double Point::Distance() const
{
	double distanceorigin= sqrt(pow(m_x,2) + pow(m_y,2));
	return distanceorigin;
}

double Point::Distance(const Point &p) const
{
	double distance = sqrt(pow(m_x - p.m_x,2) + pow(m_y - p.m_y,2));
	return distance;
}

Point Point:: operator - () const	// Negate the coordinates.
{
	return Point(-m_x, -m_y);
}

Point Point:: operator * (double factor) const	// Scale the coordinates.
{
	return Point(factor*m_x, factor*m_y);
}

Point Point:: operator + (const Point& p) const	// Add coordinates.
{
	return Point(m_x + p.m_x, m_y + p.m_y);
}

bool Point:: operator == (const Point& p) const		 // Equally compare operator.
{
	if (m_x == p.m_x&&m_y == p.m_y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Point& Point::operator = (const Point& source)	// Assignment operator.
{
	m_x = source.m_x;
	m_y = source.m_y;
	return *this;
}

Point& Point:: operator *= (double factor)	// Scale the coordinates & assign.
{
	m_x *= factor;
	m_y *= factor;
	return *this;
}

ostream& operator << (ostream& os, const Point& p)	// Send to ostream
{ 

	os << p.ToString();

	return os;
}

