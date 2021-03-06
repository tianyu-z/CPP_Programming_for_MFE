//Purpose: The head file of Base class for out of bound exception
//Author: Tianyu Zhang
//Date: 07/01/18
#ifndef OutOfBoundsException_H
#define OutOfBoundsException_H

#include "ArrayException.h"
#include <sstream>
#include <iostream>
using namespace std;

class OutOfBoundsException : public ArrayException
{
private:
	int m_index;

public:
	// Constructors and destructor
	OutOfBoundsException() : ArrayException()
	{ // Default constructor
	}

	OutOfBoundsException(int index) : ArrayException()
	{ // Constructor accepting erroneous array index
		m_index = index;
	}

	virtual ~OutOfBoundsException()
	{ // Destructor
	}

	string GetMessage()
	{
		stringstream stream;

		stream << "Index " << m_index << " is out of bound.";

		return stream.str();
	}
};

#endif