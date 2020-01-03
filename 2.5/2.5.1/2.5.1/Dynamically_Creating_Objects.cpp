//Purpose: Test program for dynamically created objects.
//Author: Tianyu Zhang
//Date: 06/12/18

#include "Point.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Point* p1 = new Point();
	Point* p2 = new Point(1, 1);
	Point* p3 = new Point(*p2);

	cout << *p1 << "," << *p2 << "," << *p3 << endl;
	cout << "The distance between " << *p3 << "and" << *p1 << "is" << (*p3).Distance(*p1) << endl;

	delete p1;
	delete p2;
	delete p3;

	cout << "Please input the size of the pointer array" << endl;

	int size;
	if (!(cin >> size))
	{
		cout << "Input Error." << endl;
		return;
	}
	//Point pp[size];	// Compiler error.

	Point* pp = new Point[size];	//Other constructors cannot be used.
	delete[] pp;
}
