// Purpose: Exchange the value of two variables.
//
// Author: Tianyu Zhang
// 26/04/18

#include <stdio.h>

void main()
{
	double i, j;
	// pi is the pointer to the first number
	// pj is the pointer to the second number
	void Swap(double* pi, double* pj);
	// Ask the user to input two numbers.
	printf("Please input two numbers in the following format:\ni j\n");
	if (scanf_s("%lf %lf", &i, &j))// Eusure the inputs are numbers
	{
		printf("i = %lf, j = %lf.\n", i, j);
		// Swap i and j.
		Swap(&i, &j);
		printf("If we swap i and j, then i = %lf, j = %lf.\n", i, j);
	}
	else
	{
		printf("Input Error.\n");
	}
}

void Swap(double* pi, double* pj)
{
	double tmp;
	tmp = (*pi);
	(*pi) = (*pj);
	(*pj) = tmp;
}