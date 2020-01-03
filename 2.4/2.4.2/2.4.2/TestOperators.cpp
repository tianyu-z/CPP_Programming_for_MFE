//Purpose: To test Operators in Point, Line and Circle class
//Author: Tianyu Zhang
//Date: 06/18/18

#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void main()
{
	//Test Point class
	cout << "Test Point class:" << endl;
	Point p1(1, 1);
	Point p2(2, -3);
    cout <<"Input:"<<p1.ToString() << "," << p2.ToString() << endl;
	Point p3 = -p1;
	cout << "-" << p1.ToString()  << "=" << p3.ToString() << endl;
	Point p4 = p1*2;
	cout << p1.ToString() << "*" << 2 << "=" << p4.ToString() << endl;
	Point p5 = p1 + p2;
	cout << p1.ToString() << "+" << p2.ToString() << "=" << p5.ToString() << endl;
	bool q1 = (p1 == p2);
	char str1[10];
	if (q1 == 1)
	{
		strcpy_s(str1, "true");
	}
	else
	{
		strcpy_s(str1, "false");
	}
	cout << "p1=p2 is " << str1 << endl;
	Point p6 = p1;
	cout << p1.ToString() << "=" << p6.ToString() << endl;
	p1 *= 2;
	cout << p6.ToString() << "*" << 2 << "=" << p1.ToString() << endl << endl;

	// Test << operator in Point class.
	cout << "p1:" << endl;
	cout << p1;

	//Test Line class
	//If we regard lines as vectors in Cartesian coordinates, then -,*,+,*= are all applicable to lines.
	cout << "Test Line class:" << endl;
	Line l1(p1, p2);
	Line l2(p3, p4);
	cout << "Input:" << l1.ToString() << "," << l2.ToString() << endl;
	Line l3 = -l1;
	cout << "-" << l1.ToString() << "=" << l3.ToString() << endl;
	Line l4 = l1 * 2;
	cout << l1.ToString() << "*" << 2 << "=" << l4.ToString() << endl;
	Line l5 = l1 + l2;
	cout << l1.ToString() << "+" << l2.ToString() << "=" << l5.ToString() << endl;
	bool q2 = (l1 == l2);
	char str2[10];
	if (q2 == 1)
	{
		strcpy_s(str2, "true");
	}
	else
	{
		strcpy_s(str2, "false");
	}
	cout << "l1=l2 is " << str2 << endl;
	Line l6 = l1;
	cout << l1.ToString() << "=" << l6.ToString() << endl;
	l1 *= 2;
	cout << l6.ToString() << "*" << 2 << "=" << l1.ToString() << endl << endl;

	// Test << operator in Line class.
	cout << "l1:" << endl;
	cout << l1;

	//Test Circle class
	cout << "Test Circle class:" << endl;
	Circle c1(p1, 1);
	Circle c2(p2, 2);
	bool q3 = (c1 == c2);
	char str3[10];
	if (q3 == 1)
	{
		strcpy_s(str3, "true");
	}
	else
	{
		strcpy_s(str3, "false");
	}
	cout << "c1=c2 is " << str3 << endl;
	Circle c3 = c1;
	cout << c1.ToString() << "=" << c3.ToString() << endl;

	// Test << operator in Circle class.
	cout << "c1:" << endl;
	cout << c1;
}