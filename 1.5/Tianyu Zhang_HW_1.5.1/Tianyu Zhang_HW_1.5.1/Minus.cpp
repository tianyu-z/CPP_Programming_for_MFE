/*Purpose: Caculate the difference of two numbers.*/
/*Author: Tianyu Zhang*/
/*Date: 04/19/18*/

#include <stdio.h>

float minus(float num1, float num2)/*Define the minus function.*/
{
	return num1 - num2;
}

int main()
{
	float a, b;
	printf("Please enter the first number and the second number.\n");
	if ((scanf_s("%f", &a))&&(scanf_s("%f", &b)))/*Ensure the inputd are float numbers.*/
	{
		printf("The difference of a and b is %f.", minus(a, b));
	}
	else
	{
		printf("The inputs are not numbers.");
	}
	return 0;
}

