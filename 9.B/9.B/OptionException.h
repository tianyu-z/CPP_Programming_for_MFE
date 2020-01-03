//Purpose: The head file of OptionException
//Author: Tianyu Zhang
//Date: 07/06/18


#ifndef OptionException_h
#define OptionException_h

#include <iostream>
using namespace std;

class OptionException
{
public:
	// Constructor and destructor
	OptionException()
	{ // Default constructor
	}

	virtual ~OptionException()
	{ // Destructor
	}

	virtual string GetMessage() = 0;
};

#endif