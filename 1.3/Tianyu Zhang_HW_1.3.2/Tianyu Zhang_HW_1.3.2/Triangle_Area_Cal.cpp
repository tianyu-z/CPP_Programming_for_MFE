/*Purpose: Calculate the area of triangle by its base and its height.*/
/*Author: Tianyu Zhang*/
/*Date:04/10/18*/

#include <stdio.h>

int main()
{
	/*Define float varibles*/
	float base,height,area;
	
	/*Ask users to enter the base of a triangle.*/
	printf("Please enter the base of a triangle.\n");
	scanf_s("%f",&base);
	/*Ask users to enter the height of a triangle.*/
	printf("Please enter the height of a triangle.\n");
	scanf_s("%f",&height);
	
	/* The formular of the area of the triangle.*/
	area = 0.5*base*height;
	
	/*Print the area of the triangle.*/
	printf("The area of the triangle is %.1f.\n",area);

	return 0;
	fflush(stdin);
}