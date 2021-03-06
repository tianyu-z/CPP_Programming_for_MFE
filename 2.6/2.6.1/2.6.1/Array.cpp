//Purpose: The Source file of Array Class
//Author: Tianyu Zhang
//Date: 06/22/18

#include <iostream>
#include "Point.h"
#include "Array.h"
#include <cmath>
using namespace std;

namespace ZTY
{
	namespace Containers
	{
		Array::Array() :m_data(new CAD::Point[10]), m_size(10)
		{
		}

		Array::Array(int size) : m_data(new CAD::Point[size]), m_size(size)
		{
		}

		Array::Array(const Array& source) : m_data(source.m_data), m_size(source.m_size)
		{
			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = source.m_data[i];
			}
		}
		Array::~Array()
		{
			delete[] m_data;
		}

		int Array::Size() const
		{
			return m_size;
		}

		void Array::SetElement(int index, const CAD::Point& newPoint)
		{
			if (index >= m_size)
			{
				return;
			}
			m_data[index] = newPoint;

		}
		CAD::Point& Array::GetElement(int index) const
		{
			if (index >= m_size)
			{
				return m_data[0];
			}
			return m_data[index];
		}
		Array& Array::operator =(const Array& source)
		{
			if (this == &source)
			{
				return *this;
			}
			else
			{
				delete[] m_data;

				m_data = new CAD::Point[source.m_size];
				m_size = source.m_size;
				for (int i = 0; i < m_size; i++)
				{
					m_data[i] = source.m_data[i];
				}
				return *this;
			}

		}
		CAD::Point& Array::operator [](int index)
		{
			if (index >= m_size)
			{
				return m_data[0];
			}

			else { return m_data[index]; }
		}

		const CAD::Point& Array::operator [] (int index) const
		{
			// Purpose: 
			// 1) Allow the user to read, but not to write.
			// 2) Allow Array objects declared as const to work.

			if (index >= m_size)
			{
				return m_data[0];
			}

			return m_data[index];
		}
	}
}
