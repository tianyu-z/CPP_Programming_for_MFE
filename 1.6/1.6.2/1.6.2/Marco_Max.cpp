// Purpose: Calculate the Max number using macros.
// Author: Tianyu Zhang
// Date: 04/22/18

#include <stdio.h>
#include "Defs.h"

int main()
{
	double x,y,z;
	// Ask the user to input three numbers.
	printf("Please input three numbers in the following format:\na b c\n");

	if (scanf_s("%lf %lf %lf", &x, &y, &z))
	{
		//Using MAX2 to print the maximum value of a and b 
		printf("The maximum value of %lf and %lf is %lf.\n", x,y,MAX2(x, y));

		//Using MAX3 to print the maximum value of a,b and c
		printf("The maximum value of %lf,%lf and %lf is %lf.\n", x,y,z,MAX3(x, y, z));
	}
	else
	{
		printf("Error in inputs.\n");
	}
}