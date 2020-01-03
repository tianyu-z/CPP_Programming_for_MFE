//Purpose: The head file of Base class for incompatible size exception
//Author: Tianyu Zhang
//Date: 07/01/18
#ifndef IncompatibleSizeException_h
#define IncompatibleSizeException_h

#include "ArrayException.h"
#include <sstream>
#include <iostream>
using namespace std;

class IncompatibleSizeException : public ArrayException
{
public:
	// Constructors and destructor
	IncompatibleSizeException() : ArrayException()	// Default constructor
	{ 
	}

	~IncompatibleSizeException()	// Destructor
	{ 
	}

	string GetMessage()
	{
		stringstream stream;

		stream << "It is an incompatible size of arrays.";

		return stream.str();
	}
};

#endif