//Purpose: The Source file of Stack
//Author: Tianyu Zhang
//Date: 07/02/18



#ifndef Stack_CPP
#define Stack_CPP
#include "Array.h"
#include "Stack.h"
#include "StackException.h"

// Constructors
template <typename T, int size>
Stack<T, size>::Stack() : m_current(0), m_array(size)	// Default constructor.
{ 
}

template <typename T, int size>
Stack<T, size>::Stack(const Stack<T, size>& source) : m_current(source.m_current), m_array(source.m_array)	// Copy constructor
{ 
}

template <typename T, int size>	
Stack<T, size>::~Stack()	// Destructor
{ 
}

template <typename T, int size>
Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source0)	// Assignment operator
{ 
	if (this == &source0)
	{
		return *this;
	}

	m_current = source0.m_current;
	m_array = source0.m_array;

	return *this;
}




template <typename T, int size>
T& Stack<T, size>::Pop()
{
	T t;

	try
	{
		t = m_array[m_current - 1];
	}
	catch (ArrayException& ex)
	{
		throw StackEmptyException();
	}

	m_current--;
	return t;
}

template <typename T, int size>
void Stack<T, size>::Push(const T& newT)
{
	try
	{
		m_array[m_current] = newT;
	}
	catch (ArrayException& ex)
	{
		throw StackFullException();
	}
	m_current++;
}

#endif