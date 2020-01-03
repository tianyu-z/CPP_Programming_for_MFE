//Purpose: The head file of EuropeanOption
//Author: Tianyu Zhang
//Date: 07/07/18

#ifndef OptionException_HPP
#define OptionException_HPP

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