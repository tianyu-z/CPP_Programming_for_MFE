//Purpose: The head file of Array Class
//Author: Tianyu Zhang
//Date: 06/22/18

#ifndef Array_h
#define Array_h

#include "Point.h"
using namespace std;

class Array
{
private:
	int m_size;
	Point* m_data;

public:
	// Constructors and destructors
	Array();
	Array(int size);
	Array(const Array& source);
	~Array();
	// SizeGetter
	int Size() const;
	// Setter
	void SetElement(int index, const Point& newPoint);
	// Getter
	Point& GetElement(int index) const;
	// Operator
	Array& operator =(const Array& source);
	Point& operator [] (int index);
	const Point& operator [] (int index) const;
	
};


#endif