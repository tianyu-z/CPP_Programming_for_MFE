// Purpose: Calculate the length of a string.
// Author: Tianyu Zhang
// 26/04/18

#include <stdio.h>
#define MAXLINE 30

// String length declaration.
int Length(char str[]);
int main()
{
	char string[MAXLINE + 1]; // Line of maxium 30 chars + \0
	int c; // The input character
	int i = 0; // The counter

	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
	// Get the characters.
	while ((c = getchar()) != EOF && i < MAXLINE)
	{
	// Append characters to string.
		string[i++] = (char)c;
	}
	string[i] = '\0'; 
	// String must be end with \0.
	printf("String length is %d\n", Length(string));
	return 0;
}
int Length(char str[])
{
	int length = 0;
	//Initializing a variable to count the length of the string.
	while (str[length] != '\0')
	{
		length++;
	}
	return --length;
}
