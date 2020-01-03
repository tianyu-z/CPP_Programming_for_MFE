//Purpose: The test file of PointArray
//Author: Tianyu Zhang
//Date: 07/01/18


#include "PointArray.h"
#include <iostream>
using namespace std;

void main()
{
	// constructors.
	PointArray expa0;
	cout << "PointArray0: " << endl << "size = " << expa0.Size() << endl;

	PointArray expa1(10);
	cout << "PointArray1: " << endl;
	for (int i = 0; i < expa1.Size(); i++)
	{
		expa1[i] = Point(i, i + 1);
		cout << expa1[i] << endl;
	}

	PointArray expa2(expa1);
	cout << "PointArray2: " << endl;
	for (int i = 0; i < expa2.Size(); i++)
	{
		cout << expa2[i] << endl;
	}

	// assignment operator.
	PointArray expa3 = expa1;
	cout << "PointArray3: " << endl;
	for (int i = 0; i < expa3.Size(); i++)
	{
		cout << expa3[i] << endl;
	}

	// Length() function.
	cout << "Length of PointArray1 = " << expa1.Length() << endl;
}