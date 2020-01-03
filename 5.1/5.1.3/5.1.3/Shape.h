//Purpose: The head file of Shape
//Author: Tianyu Zhang
//Date: 07/01/18

#ifndef Shape_H
#define Shape_H

#include <iostream>
using namespace std;

class Shape
{
private:
	int m_id; // ID

public:
	// Constructors and destructor
	Shape(); // Constructor
	Shape(const Shape& source); // Copy constructor
	virtual ~Shape(); // Destructor

					  // Operator overloading
	Shape& operator = (const Shape& source); // Assignment operator

	virtual string ToString() const;

	// Accessing functions
	int ID() const;

	// Functionalities
	virtual void Draw() const = 0;

	void Print() const;
};

#endif