//Purpose: The source file of Points in 2 dimensions with distance function
//Author: Tianyu Zhang
//Date: 05/12/18

#include <sstream>
#include "Point.h"
#include <cmath>

using namespace std;

Point::Point()	// Default constructor
{
	cout << "Default constructor activated." << endl;
}

Point::Point(const Point &point):m_x(point.m_x),m_y(point.m_y)
{
	cout << "Copy constructor activated." << endl;
}
Point::Point(double xValue, double yValue) : m_x(xValue), m_y(yValue) // Constructor that accepts x-coordinates and y-coordinates
{
	cout << "Constructor that accepting x-coordinates and y-coordinates activated." << endl;
}

Point::~Point()	// Destructor
{
	cout << "Destructor activated." << endl;
}

double Point::X() const	//Get X and Y from the private variables
{
	return m_x;
}

double Point::Y() const
{
	return m_y;
}

void Point::X(double newX)
{
	m_x = newX;
}

void Point::Y(double newY)
{
	m_y = newY;
}

string Point::ToString() const
{
	stringstream s_string;
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