//Purpose: The source file of Circles in 2 dimensions
//Author: Tianyu Zhang
//Date: 06/12/18

#define _USE_MATH_DEFINES
#include <sstream>
#include "Point.h"
#include "Circle.h"
#include <cmath>

using namespace std;

Circle::Circle() : Shape()
{
	m_c = Point(0.0, 0.0);
	m_r = 1.0;
}

Circle::Circle(const Circle &circle) :Shape(),m_c(circle.m_c), m_r(circle.m_r)
{
}

Circle::Circle(Point centrepoint, double radius) : Shape(),m_c(centrepoint), m_r(radius) // Constructor that accepts centrepoint and radius
{
}

Circle::~Circle()	// Destructor
{
	cout << "Circle destructor activated." << endl;
}

Point Circle::CentrePoint() const
{
	return m_c;
}

double Circle::Radius() const
{
	return m_r;
}

void Circle::CentrePoint(const Point &newC)
{
	m_c = newC;
}

void Circle::Radius(const double newR)
{
	m_r = newR;
}

string Circle::ToString() const
{
	stringstream s_string;
	std::string s = Shape::ToString();
	s_string << "Circle:{" << m_c.ToString() <<  ",Radius:" << m_r<< "}";
	return s_string.str();
}

double Circle::Diameter() const
{
	return 2 * m_r;
}

double Circle::Area() const
{
	return M_PI*pow(m_r,2);
}

double Circle::Circumference() const
{
	return 2 * m_r*M_PI;
}

bool Circle:: operator == (const Circle& c) const		 // Equally compare operator.
{
	if (m_c == c.m_c&&m_r == c.m_r)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Circle& Circle::operator = (const Circle& source)	// Assignment operator.
{
	m_c = source.m_c;
	m_r = source.m_r;
	return *this;
}

ostream& operator << (ostream& os, const Circle& c)	// Send to ostream
{

	os << "Circle:{" << c.m_c << ",Radius:" << c.m_r << "}" << endl;

	return os;
}

void Circle::Draw() const
{
	cout << "Draw a circle." << endl;
}