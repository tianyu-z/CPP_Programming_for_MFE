//Purpose: The source file of Points in 2 dimensions
//Author: Tianyu Zhang
//Date: 05/12/18

#include <sstream>
#include "Point.h"

using namespace std;

Point::Point()	// Default constructor
{

}

Point::~Point()	// Destructor
{

}

double Point::GetX()	//Get X and Y from the private variables
{
	return m_x;
}

double Point::GetY()
{
	return m_y;
}

void Point::SetX(double newX)
{
	m_x = newX;
}

void Point::SetY(double newY)
{
	m_y = newY;
}

string Point::ToString()
{
	stringstream s_string;
	s_string << "Point(" << m_x << "," << m_y << ")";
	return s_string.str();
}