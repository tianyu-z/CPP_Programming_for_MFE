/*Purpose: Write a recursive function printnumber() which gets the number to be printed.
This number is an integer. The function should print the number digit by digit by using 
the putchar() function. Don¡¯t use printf().*/
/*Author: Tianyu Zhang*/
/*Date: 04/20/18*/

#include<stdio.h>
#include<stdlib.h>/*The _itoa_s() function needs stdlib.h*/

int i = 0;
char str[100];
void printnumber(int a)/*Set the recursive function to print the integer digit by digit.*/
{
	_itoa_s(a, str, 10);/*Transfer a integal number into a string.*/
	putchar(str[i]);
	i++;
	if (str[i] != NULL)/*Set the ending condition for recursion.*/
	{
		printnumber(a);
	}
	else
	{
		putchar('\n');
	}
}
int main()
{
	printf("Please enter an integer.\n");
	int n;
	if (scanf_s("%d", &n))
	{
		printnumber(n);
	}/*Input an integer to be printed.*/
	else
	{
		printf("Error in inputs.\n");
	}
	return 0;
}