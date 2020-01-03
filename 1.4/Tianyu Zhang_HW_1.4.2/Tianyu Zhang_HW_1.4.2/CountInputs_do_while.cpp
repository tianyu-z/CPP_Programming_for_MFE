/*Purpose: Caculate the amount of characters, the amount of words and the amount of
newlines that have been typed, using a do-while loop.*/
/*Author: Tianyu Zhang*/
/*Date: 04/13/18*/

#include <stdio.h>

int main()
{
	int num_letter = 0, num_lines = 1, num_words = 0, num_char = 0;/*Initializing varibles.*/
	char content = ' ';
	char precontent = ' ';/*Define the previous character of the content.*/

	printf("Please input some words or sentences here. You can tpye Ctrl+D to exist anytime.\n");

	do
	{
		num_char++;
		if ((content != ' ') && (content != '\n') && (content != '\r') && (content != '\t') && ((precontent == ' ') || (precontent == '\n') || (precontent == '\r') || (precontent == '\t')))
		{
			num_words++;
		}/*Set the conditions for counting a word.*/
		if ((content == '\n') || (content == '\r'))
		{
			num_lines++;
		}/*Set the conditions for counting a line.*/
		precontent = content;
	} 
	while (((content = getchar()) != EOF) && (content != 4));/*Set the conditions for the program running.*/
	printf("The number of characters:%d; The number of words:%d, The number of lines:%d\n", num_char, num_words, num_lines);
	return 0;
}