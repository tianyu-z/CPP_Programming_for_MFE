//Purpose: The head file of NoImplementationException
//Author: Tianyu Zhang
//Date: 07/06/18

#ifndef NoImplementationException_h
#define NoImplementationException_h

#include "OptionException.h"
#include <sstream>
#include <iostream>
using namespace std;

class NoImplementationException : public OptionException
{
private:
	string m_functionName;

public:
	// Constructors and destructor
	NoImplementationException() : OptionException()
	{ // Default constructor
	}

	NoImplementationException(string functionName) : OptionException()
	{ // Constructor accepting erroneous function name

		m_functionName = functionName;
	}

	virtual ~NoImplementationException()
	{ // Destructor
	}

	string GetMessage()
	{
		stringstream stream;

		stream << "No implementation of the " << m_functionName << " function in the derived class";

		return stream.str();
	}
};

#endif