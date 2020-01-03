/*Purpose: Create a C-program that prints two columns on the screen
with the temperature in degrees Fahrenheit and the equivalent temperature in degrees Celsius.*/
/*Author: Tianyu Zhang*/
/*Date: 04/17/18*/

#include <stdio.h>

int main()
{
	float f, cmin = 0, cmax = 19, c = cmin, step = 1;/*Initializing variables.*/
	printf("     Celsius\t   Fahrenheit\n");/*Set the header.*/
	for(c=cmin;c<=cmax;c=c+step)/*The condition for a loop stop.*/
	{
		f = (9.0 / 5.0)*c + 32;
		printf("%10.1f\t%10.1f\n", c, f);
	}
	return 0;
}