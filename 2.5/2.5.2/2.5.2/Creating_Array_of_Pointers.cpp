//Purpose: Creating Array of Pointers for Point Class
//Author: Tianyu Zhang
//Date: 06/12/18

#include "Point.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	const int size=3;
	// Create an array of Point pointers with 3 elements on the heap.
	Point** arraypoint = new Point*[size];

	// Create for each element in the array a point on the heap.

	arraypoint[0] = new Point(0.0, 0.0);
	arraypoint[1] = new Point(1.0, 0.5);
	arraypoint[2] = new Point(2.0, 1.0);

	// Iterate the array and print each point in the array.
	for (int i = 0; i < 3; i++)
	{
		cout << *arraypoint[i] << endl;
	}
	// Iterate the array again and delete each point in the array.
	for (int i = 0; i < 3; i++)
	{
		delete arraypoint[i];
	}
	// Delete the array itself.
	delete[] arraypoint;
	// Please check memory layout in "Memory_Layout.pdf"
}
