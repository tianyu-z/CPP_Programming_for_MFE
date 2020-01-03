/*Purpose: Show the result of the integer after shifting.*/
/*Author: Tianyu Zhang*/
/*Date:04/13/18*/


#include <stdio.h>

void main()
{
	long long int i; /* Input an integer. */
	long long int i_rs2; /* The result of shifting i two places to the right */

	/* Ask the user to input an integer. */
	printf("Please input an integer.\n");
	if (scanf_s("%lld", &i))
	{
		/* Get the result after shifting. */
		i_rs2 = i >> 2;

		/* Print the result after shifting on screen. */
		printf("Shift %lld two places to the right, then we get %lld.\n", i, i_rs2);

		/* i is a signed integer, so an arithmetic shift is performed. */
		printf("An arithmetic shift if performed.\n");
	}
	else
	{
		/* If the user's input is not an integer, send an error message. */
		printf("Input Error: Input is not an integer.\n");
		return;
	}
	fflush(stdin);
}