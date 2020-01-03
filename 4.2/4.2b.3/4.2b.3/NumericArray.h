//Purpose: The head file of Base class for NumericArray class
//Author: Tianyu Zhang
//Date: 07/01/18
#ifndef NumericArray_h
#define NumericArray_h

#include "Array.h"

template <typename T>
class NumericArray : public Array<T>
{
public:
	// Constructors
	NumericArray();
	NumericArray(int size);
	NumericArray(const NumericArray<T>& pn);

	// Destructor
	~NumericArray();

	// Member operator overloading
	NumericArray<T>& operator = (const NumericArray<T>& source);
	NumericArray<T> operator * (const T& factor) const;
	NumericArray<T> operator + (const NumericArray<T>& n2) const;

	// Numeric functionality
	T DotProduct(const NumericArray<T>& n2) const;
};

#endif