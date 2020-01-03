//Purpose: The test file of tuple
//Author: Tianyu Zhang
//Date: 07/05/18

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <string>
#include <iostream>

using namespace std;

void Print(const boost::tuple<string, int, int>& person)
{
	cout << "Name: " << person.get<0>() << "; Age: "
		<< person.get<1>() << "; Length: " << person.get<2>() << endl;
}

void main()
{
	using boost::tuple;
	typedef boost::tuple<string, int, int> Person;

	// Create person instances.
	Person person1 = boost::make_tuple(string("Bob"), 10, 145);
	Person person2 = boost::make_tuple(string("Kat"), 22, 161);
	Person person3 = boost::make_tuple(string("William"), 18, 170);

	// Increment the age of one person.
	person2.get<1>() += 3;

	Print(person1);
	Print(person2);
	Print(person3);
}