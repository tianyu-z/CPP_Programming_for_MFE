/*Purpose: Show the calculate rule of the conditional expressions.*/
/*Author: Tianyu Zhang*/
/*Date:04/13/18*/

#include <stdio.h>
int main()
{
	int x = 1;
	int y = 1;
	int z = 1;
	x += y += x;/* First, we calclulate y=y+x. So y==2. Then, we calclulate x=x+y. So x==3. */
	printf("%d\n\n", (x<y) ? y : x); /* x<y is false, so the result is 3. */
	printf("%d\n", (x<y) ? x++ : y++); /* x<y is false, so the result is 2 and y=y+1 after showing the result of 2. */
	printf("%d\n", x); /* From the above, we know x==3 which is the result. */
	printf("%d\n", y); /* From the above, we know y==3 which is the result. */
	return 0;
}