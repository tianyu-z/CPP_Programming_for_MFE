//Purpose: The Test file of Array class
//Author: Tianyu Zhang
//Date: 06/22/18

#include "Array.cpp"
#include <iostream>
using namespace std;

void main()
{
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;
	cout << intArray1.DefaultSize() << endl; // 10, because the default size is 10.
	cout << intArray2.DefaultSize() << endl; // 10, because the default size is 10.
	cout << doubleArray.DefaultSize() << endl; // 10, because the default size is 10.
	intArray1.DefaultSize(15);
	// We change the default size of intArray1 is set to 15.
	cout << intArray1.DefaultSize() << endl; // 15
											 // Because static data member is independent of any particular object of the class Array<int>,
											 // so when the default size of intArray1 is set to 15, the default size of intArray2 is also 15.
	cout << intArray2.DefaultSize() << endl; // 15
											 // Because doubleArray is an instance of class Array<double> rather than Array<int>,
											 // so when the default size of intArray1 is set to 15, the default size of doubleArray is still 10.
	cout << doubleArray.DefaultSize() << endl; // 10
}
