/*Purpose: Efficiently multiplies a number by a factor 2 to the power n.*/
/*Author: Tianyu Zhang*/
/*Date:04/12/18*/


#include <stdio.h>

void main()
{
	long long int i; /* Input an integer. */
	long long int i_ls1; /* The result of shifting i one place to the left */
	long long int i_ls2; /* The result of shifting i two places to the left */
	long long int i_ls3; /* The result of shifting i three places to the left */
	long long int i_lsn; /* The result of shifting i n places to the left */
	long long int n; /* The power of the multiplier */

    /* Ask the user to input an integer. */
	printf("Please first input an integer i which will be multiplied.\n");
	printf("Please second input an integer n as the power n and we can efficiently multiplies i by a factor 2 to the power n.\n");
	if ((scanf_s("%lld", &i))&& scanf_s("%lld", &n))
	{
		
		/* Get the result after shifting. */
		i_ls1 = i << 1;
		i_ls2 = i << 2;
		i_ls3 = i << 3;
		i_lsn = i << n;
		/* Print the result after shifting on screen. */
		printf("Shift %lld for 1 place to the left, then we get %lld, which is the same as multiplying by 2.\n", i, i_ls1);
		printf("Shift %lld for 2 places to the left, then we get %lld which is the same as multiplying by 4.\n", i, i_ls2);
		printf("Shift %lld for 3 places to the left, then we get %lld which is the same as multiplying by 8.\n", i, i_ls3);
		printf("Shift %lld for %lld places to the left, then we get %lld which is the same as multiplying by 2**%lld.\n", i, n, i_lsn, n);
	}
	else
	{
		/* If the user's inputs are not integers, send an error message. */
		printf("Input Error: Some of the inputs are not integers.\n");
		return;
	}
	fflush(stdin);
}