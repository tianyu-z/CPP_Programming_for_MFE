//Purpose: The source file of Line
//Author: Tianyu Zhang
//Date: 06/12/18

#include <sstream>
#include "Point.h"
#include "Line.h"
#include <cmath>

using namespace std;

Line::Line():m_s(0,0),m_e()
{
}

Line::Line(const Line &line):m_s(line.m_s),m_e(line.m_e)
{
}

Line::Line(Point start, Point end) : m_s(start), m_e(end)
{
}

Line::~Line()
{
}

Point Line::P1() const
{
	return m_s;
}

Point Line::P2() const
{
	return m_e;
}
void Line::P1(const Point &newS)
{
	m_s = newS;
}
void Line::P2(const Point &newE)
{
	m_e = newE;
}
string Line::ToString() const
{
	stringstream s0_string;
	s0_string << "Line:" << m_s.ToString() << "-" << m_e.ToString();
	return s0_string.str();
}
double Line::Length()
{
	return m_s.Distance(m_e);
}

//If we regard lines as vectors in Cartesian coordinates, then -,*,+,*= are all applicable to lines.
Line Line:: operator - () const	// Negate the coordinates.
{
	return Line(-m_s, -m_e);
}

Line Line:: operator * (double factor) const	// Scale the coordinates.
{
	return Line(m_s*factor, m_e*factor);
}

Line Line:: operator + (const Line& l) const	// Add coordinates.
{
	return Line(m_s + l.m_s, m_e + l.m_e);
}

bool Line:: operator == (const Line& l) const		 // Equally compare operator.
{
	if (m_s == l.m_s&&m_e == l.m_e)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Line& Line::operator = (const Line& source)	// Assignment operator.
{
	m_s = source.m_s;
	m_e = source.m_e;
	return *this;
}

Line& Line:: operator *= (double factor)	// Scale the coordinates & assign.
{
	m_s *= factor;
	m_e *= factor;
	return *this;
}

ostream& operator << (ostream& os, const Line& l)	// Send to ostream
{

	os << "Line:" << l.m_s << "-" << l.m_e << endl;

	return os;
}