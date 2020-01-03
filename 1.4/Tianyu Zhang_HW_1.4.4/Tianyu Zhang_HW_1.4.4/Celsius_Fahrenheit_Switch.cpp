/*Purpose: Create a C-program that prints two columns on the screen 
with the temperature in degrees Fahrenheit and the equivalent temperature in degrees Celsius.*/
/*Author: Tianyu Zhang*/
/*Date: 04/16/18*/

#include <stdio.h>

int main()
{
	float c, fmin = 0, fmax = 300, f = fmin, step = 20;/*Initializing variables.*/
	printf("   Fahrenheit\t    Celsius\n");/*Set the header.*/
	while (f <= fmax)/*The condition for a loop stop.*/
	{
		c = (5.0 / 9.0)*(f - 32.0);
		printf("%10.1f\t%10.1f\n", f, c);
		f = f + step;
	}
	return 0;
}