//Purpose: The Source file of Stack
//Author: Tianyu Zhang
//Date: 07/02/18



#ifndef Stack_CPP
#define Stack_CPP
#include "Array.h"
#include "Stack.h"

// Constructors
template <typename T>
Stack<T>::Stack() : m_current(0)	// Default constructor.
{ 
}


template <typename T>
Stack<T>::Stack(int size) : m_current(0), m_array(size)
{
}

template <typename T>
Stack<T>::Stack(const Stack<T>& source) : m_current(source.m_current), m_array(source.m_array)	// Copy constructor
{ 
}

template <typename T>	
Stack<T>::~Stack() // Destructor
{
}


template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& source0)	// Assignment operator
{ 
	if (this == &source0)
	{
		return *this;
	}
	m_current = source0.m_current;
	m_array = source0.m_array;

	return *this;
}



template <typename T>
T& Stack<T>::Pop()
{
	if (m_current < 1)
	{
		return m_array[m_current - 1];
	}
	else
	{
		m_current--;
		return m_array[m_current];
	}
}

template <typename T>
void Stack<T>::Push(const T& newT)
{
	m_array[m_current] = newT;
	m_current++;
}

#endif