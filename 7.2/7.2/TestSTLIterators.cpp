//Purpose: The Test file of STL Iterators
//Author: Tianyu Zhang
//Date: 06/22/18

#include <iostream>


#include <list>
#include <vector>
#include <map>

using namespace std;


template <typename T>	
double Sum(const T& t)	// The sum of the elements in a container
{
	typename T::const_iterator i;
	double sum = 0.0;

	for (i = t.begin(); i != t.end(); ++i)
	{
		sum += *i;
	}

	return sum;
}


template <typename T1, typename T2>	// The sum of the elements in a map
double Sum(const map<T1, T2>& t)
{
	typename map<T1, T2>::const_iterator i;
	double sum = 0.0;
	for (i = t.begin(); i != t.end(); ++i)
	{
		sum += (i->second);
	}

	return sum;
}


template <typename T>	// The sum between two iterators in a container 
double Sum(const typename T::const_iterator& start, const typename T::const_iterator& end)
{
	typename T::const_iterator i;
	double sum = 0.0;
	for (i = start; i != end; ++i)
	{
		sum += *i;
	}

	return sum;
}


template <typename T1, typename T2>	// The sum between two iterators in a map 
double Sum(const typename map<T1, T2>::const_iterator& start, const typename map<T1, T2>::const_iterator& end)
{
	typename map<T1, T2>::const_iterator i;
	double sum = 0.0;
	for (i = start; i != end; ++i)
	{
		sum += i->second;
	}

	return sum;
}

void main()
{
	
	list<double> l1;	// The sum of a list
	for (int i = 0; i < 20; ++i)
	{
		l1.push_back(i + 0.1);
	}

	cout << Sum(l1) << ", " << Sum<list<double>>(++l1.begin(), --l1.end()) << endl;

	
	vector<double> v1(5);	// The sum of a vector
	for (int i = 0; i < 20; ++i)
	{
		v1.push_back(i + 0.1);
	}

	cout << Sum(v1) << ", " << Sum<vector<double>>(++v1.begin(), --v1.end()) << endl;

	
	map<string, double> map1;	// The sum of a map
	string str[5] = { "1", "2", "3", "4" , "5" };

	for (int i = 0; i < 5; i++)
	{
		map1[str[i]] = i + 0.1;
	}

	cout << Sum(map1) << ", " << Sum<string, double>(++map1.begin(), --map1.end()) << endl;
}
