//Purpose: The source file of Shape
//Author: Tianyu Zhang
//Date: 07/01/18

#include "Shape.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

Shape::Shape():m_id(rand())
{
}
Shape::Shape(const Shape& source):m_id(source.m_id)
{
}
Shape::~Shape()
{
}
Shape& Shape:: operator = (const Shape& source)
{
	if (this == &source)
	{
		return *this;
	}
	else
	{
		m_id = source.m_id;
		return *this;
	}
}
string Shape::ToString() const
{
	stringstream stream;
	stream << "ID: " << m_id;
	return stream.str();
}
int Shape::ID() const
{
	return m_id;
}

void Shape::Print() const
{
	cout << ToString() << endl;
}