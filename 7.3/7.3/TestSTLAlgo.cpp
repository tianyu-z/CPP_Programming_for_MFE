//Purpose: The test file of STLAlgorithem
//Author: Tianyu Zhang
//Date: 07/03/18

#include <algorithm>
#include <vector>

#include <iostream>
#include "FunctionObj.cpp"

using namespace std;


int LessThanLimit(double input)	// A global function to check the input is less than a certain value.
{
	const double limit = 20.0;
	return input < limit;
}

void main()
{
	// Create a vector with 20 elements.
	vector<double> v1;
	for (int i = 0; i < 20; i++)
	{
		v1.push_back(i + 0.1);
	}

	// Adopt the global function to get the number of elements less than a certain value.
	int result1 = count_if(v1.begin(), v1.end(), LessThanLimit);
	cout << "The number of elements that are less than 20 is " << result1 << endl;

	// Adopt the function object to get the number of elements less than a certain value.
	double limit = 20.0;
	int result2 = count_if(v1.begin(), v1.end(), FunctionObj<double>(limit));
	cout << "The number of elements that are less than " << limit << " is " << result2 << endl;
}
