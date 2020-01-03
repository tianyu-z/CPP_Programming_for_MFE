//Purpose: The test file for bound checking array
//Author: Tianyu Zhang
//Date: 07/01/18

#include "Array.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Array array(3);
	//cout << array[4] << endl; // An exception is thrown.

	try
	{
		cout << array[4] << endl;
	}
	catch (int err)
	{
		if (err == -1)
		{
			cout << "Index out of bound." << endl;
		}
	}
}