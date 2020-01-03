//Purpose: The test file of Array Class
//Author: Tianyu Zhang
//Date: 06/22/18

#include "Point.h"
#include "Array.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	// Use default constructor.
	Array array0;
	// Use constructor with size as argument.
	Array array1(2);
	// Test [] operator for writing.
	array1[0] = Point(0.5, 1.5);
	array1[1] = Point(1.5, 2.5);

	// Test assignment operator.
	array0 = array1;
	for (int i=0; i < array0.Size(); i++)
	{
		cout<< array0[i] << endl;
	}
	// Test Size(), [] operator for reading.
	cout << "Size: " << array1.Size() << endl << "Elements: " << array1[0] << ", " << array1[1] << endl;

	// Test GetElement().
	cout << "Size: " << array1.Size() << endl << "Elements: " << array1.GetElement(0) << ", " << array1.GetElement(1) << endl;

	// Test SetElement().
	array1.SetElement(0, Point(10.0, 11.0));
	array1.SetElement(1, Point(11.5, 12.0));
	cout << "Size: " << array1.Size() << endl << "Elements: " << array1[0] << ", " << array1[1] << endl;

	// Using copy constructor.
	Array array2(array1);
	cout << "Size: " << array1.Size() << endl << "Elements: " << array1[0] << ", " << array1[1] << endl;

	// Test [] operator for const Array object.
	const Array array3(array1);
	cout << "Size: " << array3.Size() << endl << "Elements: " << array3[0] << ", " << array3[1] << endl;
}