//Purpose: The head file of Line
//Author: Tianyu Zhang
//Date: 05/22/18

#ifndef Circle_h
#define Circle_h

#include <iostream>
#include "Point.h"

using namespace std;

class Circle //Set line class
{
private:
	Point m_cp;
	Point m_e;

public:
	Line();
	Line(const Line &line);
	Line(Point start, Point end);
	~Line();
	Point P1() const; Point P2() const;
	void P1(const Point &newS); void P2(const Point &newE);

	string ToString() const;

	double Length();
};
#endif
