//Purpose: The head file of Points in 2 dimensions with distance function and inline function
//Author: Tianyu Zhang
//Date: 06/12/18

#ifndef Point_h
#define Point_h

#include <iostream>
#include "Shape.h"
using namespace std;

class Point:public Shape	//Set a new class
{
private:	//construct private variables
	double m_x;	//x-coordinate
	double m_y;	//y-coordinate


public:		
	Point();//Default constructor
	virtual ~Point();	//Destructor

	Point(const Point &point); // Copy constructor
	Point(double xValue, double yValue); // Constructor that accepts x-coordinates and y-coordinates

	double X() const; double Y() const;	//The function to get the value of X and Y

	void X(double newX){ m_x = newX; }; 
	void Y(double newY){ m_y = newY; };	//The function to set the value of X and Y

	string ToString() const;	//To display the point by string

	double Distance() const; // Calculate the distance to the origin (0, 0)
	double Distance(const Point &p) const; // Calculate the distance between two points

	Point operator - () const; // Negate the coordinates.
	Point operator * (double factor) const; // Scale the coordinates.
	Point operator + (const Point& p) const; // Add coordinates.
	bool operator == (const Point& p) const; // Equally compare operator.
	Point& operator = (const Point& source); // Assignment operator.
	Point& operator *= (double factor); // Scale the coordinates & assign.

	void Draw() const;
};
ostream& operator << (ostream& os, const Point& p); // Send to ostream.
inline double Point::X() const { return m_x; }
inline double Point::Y() const { return m_y; }
#endif