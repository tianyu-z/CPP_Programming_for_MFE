/*Purpose: Caculate the amount of characters, the amount of words and the amount of
newlines that have been typed, using a while loop.*/
/*Author: Tianyu Zhang*/
/*Date: 04/18/18*/

#include <stdio.h>

int main()
{
	int num_0 = 0, num_1 = 0, num_2 = 0, num_3 = 0, num_4 = 0, num_others = 0,  num_char = 0;/*Initializing varibles.*/
	char content;
	char precontent = ' ';/*Define the previous character of the content.*/

	printf("Please input some characters here. You can tpye Ctrl+Z to exist anytime.\n");

	while (((content = getchar()) != EOF) && (content != 26))/*Set the conditions for the program running.*/
	{
		num_char++;
		switch (content)
		{
		case '0':
		{
			num_0++;
			break;
		}/*Set the conditions for counting a 0.*/
		case '1':
		{
			num_1++;
			break;
		}/*Set the conditions for counting a 1.*/
		case '2':
		{
			num_2++;
			break;
		}/*Set the conditions for counting a 2.*/
		case '3':
		{
			num_3++;
			break;
		}/*Set the conditions for counting a 3.*/
		case '4':
		{
			num_4++;
			break;
		}/*Set the conditions for counting a 4.*/
		default:
			num_others++;
			break;
		}
		}
		
	printf("Number 0 appears %d times\n", num_0);
	printf("Number 1 appears %d times\n", num_1);
	printf("Number 2 appears %d times\n", num_2);
	printf("Number 3 appears %d times\n", num_3);
	printf("Number 4 appears %d times\n", num_4);
	printf("Other characters appears %d times\n", num_others);
	return 0;
	}