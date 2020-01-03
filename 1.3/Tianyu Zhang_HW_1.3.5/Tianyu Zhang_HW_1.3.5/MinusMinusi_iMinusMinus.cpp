/*Purpose: Show the difference between i-- and --i.*/
/*Author: Tianyu Zhang*/
/*Date:04/11/18*/

#include <stdio.h>

void main()
{
	long long int i; /* number input */
	long long int original_i; /* record the value of i */
	long long int i_minus_minus; /* i-- */
	long long int minus_minus_i; /* i++ */

	/* Ask user to input an integer. */
	printf("Please input an integer.\n");


	if (scanf_s("%lld", &i))/*Check if the user inputs an integer.*/
	{
		/* Record the value of i in original_i. */
		original_i = i; 

		/* i_minus_minus = i, then i = i - 1. */
		i_minus_minus = i--;

		/* Recover the value of i. */
		i = original_i;

		/* i = i - 1, then minus_minus_i = i. */
		minus_minus_i = --i;

		/* Display the result of i_minus_minus and minus_minus_i. */
		printf("i equals to %lld.\nIf we assign i-- to a, then a equals to %lld.\nElse if we assign --i to a, then a equals to %lld.\n", original_i, i_minus_minus, minus_minus_i);
	}
	else
	{
		/* If the input is not an integer, send an error message. */
		printf("Input Error.");
		return;
	}	

	fflush(stdin);
}