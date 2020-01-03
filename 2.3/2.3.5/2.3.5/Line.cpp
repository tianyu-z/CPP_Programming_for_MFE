//Purpose: The source file of Line
//Author: Tianyu Zhang
//Date: 05/12/18

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