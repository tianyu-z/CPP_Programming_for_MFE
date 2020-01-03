/*Purpose: Caculate the factorials of an integer.*/
/*Author: Tianyu Zhang*/
/*Date: 04/19/18*/

#include <stdio.h>

void print(float a);

int main()
{
	float i;
	printf("Please enter a number for calculation.\n");
	scanf_s("%f",&i);/*Input a number for calculation and print.*/
	print(i);
	return 0;
}