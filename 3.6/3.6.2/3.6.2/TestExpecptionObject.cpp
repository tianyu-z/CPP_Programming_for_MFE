//Purpose: The test file of Base class bound exception objects
//Author: Tianyu Zhang
//Date: 07/01/18

#include "Array.h"
#include "ArrayException.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Array array(3);

	try
	{
		cout << array[4] << endl;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}
}