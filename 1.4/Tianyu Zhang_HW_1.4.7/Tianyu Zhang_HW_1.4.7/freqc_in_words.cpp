/*Purpose: Caculate the amount of characters, the amount of words and the amount of
newlines that have been typed, using a while loop.*/
/*Author: Tianyu Zhang*/
/*Date: 04/18/18*/

#include <stdio.h>
#include <string.h>

int main()
{
	int num_0 = 0, num_1 = 0, num_2 = 0, num_3 = 0, num_4 = 0, num_others = 0, num_char = 0;/*Initializing varibles.*/
	char content;


	printf("Please input some characters here. You can tpye Ctrl+Z to exist anytime.\n");

	while (((content = getchar()) != EOF) && (content != 26))/*Set the conditions for the program running.*/
	{
		num_char++;
		switch (content)
		{/*Set the conditions for counting a word.*/
		case '0':
		{
			num_0++;
			break;
		}
		case '1':
		{
			num_1++;
			break;
		}
		case '2':
		{
			num_2++;
			break;
		}
		case '3':
		{
			num_3++;
			break;
		}
		case '4':
		{
			num_4++;
			break;
		}
		default:
			num_others++;
			break;
		}
	}

	switch (num_0)/*Set the print sentence.*/
	{
	case 0:  printf("Number zero appears zero time\n"); break;
	case 1:  printf("Number zero appears one time\n"); break;
	case 2:  printf("Number zero appears two times\n"); break;
	default: printf("Number zero appears more than two times\n"); break;
	}
	switch (num_1)
	{
	case 0:  printf("Number one appears zero time\n"); break;
	case 1:  printf("Number one appears one time\n"); break;
	case 2:  printf("Number one appears two times\n"); break;
	default: printf("Number one appears more than two times\n"); break;
	}
	switch (num_2)
	{
	case 0:  printf("Number two appears zero time\n"); break;
	case 1:  printf("Number two appears one time\n"); break;
	case 2:  printf("Number two appears two times\n"); break;
	default: printf("Number two appears more than two times\n"); break;
	}
	switch (num_3)
	{
	case 0:  printf("Number three appears zero time\n"); break;
	case 1:  printf("Number three appears one time\n"); break;
	case 2:  printf("Number three appears two times\n"); break;
	default: printf("Number three appears more than two times\n"); break;
	}
	switch (num_4)
	{
	case 0:  printf("Number four appears zero time\n"); break;
	case 1:  printf("Number four appears one time\n"); break;
	case 2:  printf("Number four appears two times\n"); break;
	default: printf("Number four appears more than two times\n"); break;
	}
	switch (num_others)
	{
	case 0:  printf("Other characters appear zero time\n"); break;
	case 1:  printf("Other characters appear one time\n"); break;
	case 2:  printf("Other characters appear two times\n"); break;
	default: printf("Other characters appear more than two times\n"); break;
	}
	
	return 0;
}