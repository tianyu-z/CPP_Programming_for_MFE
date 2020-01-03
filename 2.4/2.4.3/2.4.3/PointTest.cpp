//Purpose: Test Program for Point Class: Constructors as conversion operator
//Author: Tianyu Zhang
//Date: 06/13/18

#include "Point.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Point p(1.0, 1.0);
	//if (p == 1.0) cout << "Equal!" << endl;
	//else cout << "Not equal" << endl;
	if (p == (Point)1.0) cout << "Equal!" << endl;
}