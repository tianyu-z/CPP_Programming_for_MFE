//Purpose: The head file of Line
//Author: Tianyu Zhang
//Date: 06/22/18

#ifndef Line_h
#define Line_h

#include <iostream>
#include "Point.h"

using namespace std;

class Line //Set line class
{
private:
	Point m_s;
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

	//If we regard lines as vectors in Cartesian coordinates, then -,*,+,*= are all applicable to lines.
	Line operator - () const; // Negate the coordinates.
	Line operator * (double factor) const; // Scale the coordinates.
	Line operator + (const Line& l) const; // Add coordinates.
	bool operator == (const Line& l) const; // Equally compare operator.
	Line& operator = (const Line& source); // Assignment operator.
	Line& operator *= (double factor); // Scale the coordinates & assign.
};
ostream& operator << (ostream& os, const Line& l); // Send to ostream.
#endif