/*Purpose: Adopt the fact that 1 stands for ture and 0 stands for false.*/
/*Author: Tianyu Zhang*/
/*Date:04/11/18*/

#include <stdio.h>

int main()
{
	/*Define the varible whether one married or not.*/
	float married;/* The reason why I use float here is that if one input 0.5 to int married, the machine 
				  will recognize int married as 0 to continue the program without an error warning. */

	/*Ask the users to enter 1 or 0 to indicate whether they are married or not.*/
	printf("Please enter 1 if you are married or 0 if you are not married.\n");
	/*Check if the user inputs 0 or 1.*/
	scanf_s("%f", &married);
	if ((married == 0) || (married == 1))
	{
		/*Adopt the the fact that 1 stands for ture and 0 stands for false to display whether the user is married or not.*/
		printf(married ? "You are married.\n" : "you are not married.\n");
	}
	else
	{
		/*If the user does not input 0 or 1, send an error message.*/
		printf("ERROR: The integer or character you input is not 0 or 1.\n");
	}
	return 0;
	fflush(stdin);
}