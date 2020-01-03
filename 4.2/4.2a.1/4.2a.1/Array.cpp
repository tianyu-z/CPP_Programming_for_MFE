//Purpose: The Source file of Array Class
//Author: Tianyu Zhang
//Date: 06/22/18

#ifndef Array_CPP
#define Array_CPP

#include "Array.h"
#include <cmath>
#include "OutOfBound.h"


template <typename T>
Array<T>::Array() :m_data(new T[10]), m_size(10)
{
}

template <typename T>
Array<T>::Array(int size) : m_data(new T[size]), m_size(size)
{
}

template <typename T>
Array<T>::Array(const Array<T>& source0) : m_data(source0.m_data), m_size(source0.m_size)
{
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = source0.m_data[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_data;
}


template <typename T>
void Array<T>::SetElement(int index, const T& newT)
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}
	m_data[index] = newT;

}

template <typename T>
T& Array<T>::GetElement(int index) const
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}
	return m_data[index];
}

template <typename T>
Array<T>& Array<T>::operator =(const Array<T>& source)
{
	if (this == &source)
	{
		return *this;
	}
	else
	{
		delete[] m_data;

		m_data = new T[source.m_size];
		m_size = source.m_size;
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = source.m_data[i];
		}
		return *this;
	}

}

template <typename T>
T& Array<T>::operator [](int index)
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}
	else { return m_data[index]; }
}

template <typename T>
const T& Array<T>::operator [] (int index) const
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	return m_data[index];
}

#endif