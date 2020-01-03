
//Purpose: The head file of Stack Class
//Author: Tianyu Zhang
//Date: 07/02/18

#ifndef Stack_h
#define Stack_h

#include "Array.cpp"
template <typename T>


class Stack
{
private:
	Array<T> m_array;
	int m_current;
public:
	// Constructors
	Stack();
	Stack(int size);
	Stack(const Stack<T>& ps);

	// Destructor
	~Stack();

	// Member operator overloading
	Stack<T>& operator = (const Stack<T>& source);

	// Functionalities
	T& Pop();
	void Push(const T& newT);
};

#endif
