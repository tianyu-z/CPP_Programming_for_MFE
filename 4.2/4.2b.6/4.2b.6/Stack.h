
//Purpose: The head file of Stack Class
//Author: Tianyu Zhang
//Date: 07/02/18

#ifndef Stack_h
#define Stack_h

#include "Array.cpp"


template <typename T, int size>


class Stack
{
private:
	Array<T> m_array;
	int m_current;
public:
	// Constructors
	Stack();
	
	Stack(const Stack<T, size>& source);

	// Destructor
	~Stack();

	// Member operator overloading
	Stack<T, size>& operator = (const Stack<T, size>& source0);

	// Functionalities
	T& Pop();
	void Push(const T& newT);
};

#endif
