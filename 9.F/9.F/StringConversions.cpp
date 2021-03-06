// Handy string functions
//
// Last Modification Dates:07/07/18
// Modified by: Tianyu Zhang
// (C) Datasim Education BV 2006
//

#ifndef StringConversions_CPP
#define StringConversions_CPP

#define _CRT_SECURE_NO_WARNINGS

#include "UtilitiesDJD/BitsAndPieces/StringConversions.hpp"

// Simple and useful string converters
std::string getString(long j)
{
	char str[200];
	sprintf(str, "%d", j);
	std::string result(str);
	return result;
}

std::string getString(int j)
{
	char str[200];
	sprintf(str, "%d", j);
	std::string result(str);
	return result;
}
std::string getString(size_t j)
{
	char str[200];
	sprintf(str, "%d", j);
	std::string result(str);
	return result;
}

std::string getString(double d)
{
	char str[200];
	sprintf(str, "%f", d);
	std::string result(str);
	return result;
}

std::list<std::string> convertToString(const Vector<double, long>& arr)
{

	std::list<std::string> result;

	for (long j = arr.MinIndex(); j <= arr.MaxIndex(); j++)
	{
		result.push_back(getString(arr[j]));
	}
	return result;
}

#endif