//Purpose: The source file of functionobject
//Author: Tianyu Zhang
//Date: 07/03/18

#ifndef FunctionObj_CPP
#define FunctionObj_CPP

#include "FunctionObj.h"


template <typename T>	// Constructors
FunctionObj<T>::FunctionObj()	// Default constructor.
{ 
}

template <typename T>
FunctionObj<T>::FunctionObj(const T& t) : limit(t)	// Constructor with the limit value as input.
{ 
}

template <typename T>
FunctionObj<T>::FunctionObj(const FunctionObj<T>& source) : limit(source.limit)	// Copy constructor.
{ 
}

template <typename T>
FunctionObj<T>::~FunctionObj()	// Destructor.
{ 
}

template <typename T>
FunctionObj<T>& FunctionObj<T>::operator = (const FunctionObj<T>& source)	// Assignment operator
{ 
	if (this == &source)
	{
		return *this;
	}

	limit = source.limit;
	return *this;
}

template <typename T>
int FunctionObj<T>::operator () (const T& t) const	// () operator
{ 
	return t < limit;
}

#endif