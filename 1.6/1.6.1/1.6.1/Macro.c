// Purpose: Print two variables using macros.
// Author: Tianyu Zhang
// Date: 04/22/18

#include <stdio.h>
#include "Defs.h"

void main()
{
	double a, b;

	
	printf("Please input two numbers using the following format:\na b\n");
	// Ask the user to input a and b.
	if (scanf_s("%lf %lf", &a, &b))// Ensure the inputs are numbers.
	{
		// Use PRINT1 to a.
		PRINT1(a);

		// Use PRINT2 to a and b.
		PRINT2(a, b);
	}
	else
	{
		printf("Input Error.\n");
	}
}