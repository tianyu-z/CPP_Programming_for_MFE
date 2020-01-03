//Purpose: The head file of Base class for Array exception
//Author: Tianyu Zhang
//Date: 07/01/18

#ifndef ArrayException_h
#define ArrayException_h

#include <iostream>
using namespace std;

class ArrayException
{
public:
	// Constructor and destructor
	ArrayException()	// Default constructor
	{ 
	}

	virtual ~ArrayException()	// Destructor
	{ 
	}

	virtual string GetMessage() = 0;
};

#endif