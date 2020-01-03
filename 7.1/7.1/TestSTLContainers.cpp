//Purpose: The test file of STL Containers
//Author: Tianyu Zhang
//Date: 06/22/18


#include <iostream>

#include <list>
#include <vector>
#include <map>

using namespace std;

void main()
{
	//Create A list
	list<double> l1;
	for (int i = 0; i < 20; i++)
	{
		l1.push_back(i + 0.1);
	}


	cout << "The first element: " << l1.front()
		<< ", the last element: " << l1.back() << endl;

	//Create A vector
	vector<double> v1(5);
	for (int i = 0; i < 20; i++)
	{
		v1.push_back(i + 0.1);
	}

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << ",";
	}

	cout << endl;

	//Create A map
	map<string, double> m1;
	string str[5] = { "1", "2", "3", "4", "5" };

	for (int i = 0; i < 5; i++)
	{
		m1[str[i]] = i + 0.1;
	}

	for (int i = 0; i < m1.size(); i++)
	{
		cout << m1[str[i]] << ",";
	}
}