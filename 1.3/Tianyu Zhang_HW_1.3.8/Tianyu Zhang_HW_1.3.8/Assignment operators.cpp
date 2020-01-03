/*Purpose: Show the priority of assignment operators.*/
/*Author: Tianyu Zhang*/
/*Date:04/13/18*/

#include <stdio.h>
int main()
{
	int x = 2;
	int y;
	int z;
	x *= 3 + 2;				/* x=10; + is prior to *= */
	printf("x=%d\n", x); 
	x *= y = z = 4;			/* x=40; = is prior to *= */
	printf("x=%d\n", x);
	x = y == z;				/* x=1; == is prior to *= and y==z is ture so x=1 */
	printf("x=%d\n", x);
	return 0;
}