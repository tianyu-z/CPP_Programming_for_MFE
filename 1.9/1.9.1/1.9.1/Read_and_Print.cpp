/*Purpose: Adopt string to print characters one by one.*/
/*Author: Tianyu Zhang*/
/*Date: 04/28/18*/

#include <stdio.h>

#ifndef MAX_LEN
#define MAX_LEN 10000
#endif

void main()
{
	int input; // a character input
	int count = 0; // number of characters in the current line
	char str[MAX_LEN]; // the string to store the characters of the current line

	void PrintOnScreen(char str[MAX_LEN], int count);

	// Ask the user to input characters.
	printf("Please input characters, use ENTER to display characters line by line, use CTRL + A to end. \n(If your Ctrl + A is not ^A, then your Ctrl + A may be 'select all' and Ctrl+ Shift + A may be ^A.)\n");

	// When the user doesn't input CTRL + A, keep reading characters.
	while ((input = getchar()) != 1)
	{
		// When the user press ENTER, print the current line on screen.
		if (input == 10 && count > 0)
		{
			PrintOnScreen(str, count);

			// Intialize the number of characters.
			count = 0;
			continue;
		}
		// Add the character to str.
		str[count] = input;
		count++;
	}

	// When the current line ends with CTRL + A and then ENTER
	if (count > 0)
	{
		// Print the current line.
		PrintOnScreen(str, count);
	}

	// Display the following message, when program ends.
	printf("CTRL + A is a correct ending.\n");
}

void PrintOnScreen(char str[MAX_LEN], int count)
{
	for (int i = 0; i <= count - 1; i++)
	{
		putchar(str[i]);
	}

	putchar('\n');
}