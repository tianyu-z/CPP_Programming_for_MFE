// Purpose: Create a C-program that has a function DayName()which can print the day of a given day-number.
// Author: Tianyu Zhang
// Date: 04/26/18

#include <stdio.h>

int main()
{
	int num_day = 0; // day-number input

	void Dayname(int num_day);

	// Ask the user to input the day number.
	printf("Please input a day number which is an integer from 1 to 7.\n");

	if ((scanf_s("%d", &num_day))&& (num_day<=7)&& (num_day >= 1))
	{
		// Call DayName to print the day number and day name.
		Dayname(num_day);
	}
	else
	{
		printf("Input Error.\n");
	}
	return 0;
}


void Dayname(int num_day)
{
	// Using a two-dimensional array storing the day name.
	char name_day[7][10] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	printf("Day %d is a %s.\n", num_day, name_day[num_day]);
	return;
}