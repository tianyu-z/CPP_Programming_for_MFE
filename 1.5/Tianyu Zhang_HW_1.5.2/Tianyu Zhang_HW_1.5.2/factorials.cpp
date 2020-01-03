/*Purpose: Caculate the factorials of an integer.*/
/*Author: Tianyu Zhang*/
/*Date: 04/19/18*/

#include <stdio.h>

int factorials(int a)/*The recursive function of calculate factorials.*/
{
	if (a == 0 || a == 1)/*Set the ending condition of recursion.*/
	{
		return 1;
	}
	else 
	{
		return a * factorials(a - 1);
	}
}
int main()
{
	int n;
	printf("Please enter a integer. The output will be the factorials of the integer.\n");
	if(scanf_s("%d",&n))/*Ensure the input is a integer.*/
	{
		printf("factorials(n)=%d\n", factorials(n));
	}
	else
	{
		printf("Input error.");
	}
	return 0;
}