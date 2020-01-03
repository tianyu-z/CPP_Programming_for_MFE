/*Purpose: predict the priority of simple math operators.*/
/*Author: Tianyu Zhang*/
/*Date:04/11/18*/

#include <stdio.h>

int main()
{
	int x;
	x = -3 + 4 * 5 - 6;/*x=11*/
	printf("x=%d\n", x);

	x = 3 + 4 % 5 - 6;/*x=1*/
	printf("x=%d\n", x);

	x = -3 * 4 % -6 / 5;/*x=0*/
	printf("x=%d\n", x);

	x = (7 + 6) % 5 / 2;/*x=1*/
	printf("x=%d\n", x);

	return 0;
}