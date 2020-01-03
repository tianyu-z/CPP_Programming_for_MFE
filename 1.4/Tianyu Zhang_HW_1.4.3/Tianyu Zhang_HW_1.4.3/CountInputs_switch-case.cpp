/*Purpose: Caculate the amount of characters, the amount of words and the amount of 
  newlines that have been typed, using a while loop.*/
/*Author: Tianyu Zhang*/
/*Date: 04/12/18*/

#include <stdio.h>

int main()
{
	int num_letter=0, num_lines=1, num_words=0, num_char=0;/*Initializing varibles.*/
	char content;
	char precontent = ' ';/*Define the previous character of the content.*/
	
	printf("Please input some words or sentences here. You can tpye Ctrl+D to exist anytime.\n");

	while (((content = getchar()) != EOF) && (content != 4))/*Set the conditions for the program running.*/
	{
		num_char++;
		switch (content)
		{
			case '\n':
			{
				num_lines++;
				if ((precontent != ' ')&&(precontent != '\n') && (precontent != '\r') && (precontent != '\t'))
				{
					num_words++;
				}
				break;
			}/*Set the conditions for counting a word.*/
			case '\r':
			{
				num_lines++;
				if ((precontent != ' ') && (precontent != '\n') && (precontent != '\r') && (precontent != '\t'))
				{
					num_words++;
				}
				break;
			}/*Set the conditions for counting a line.*/
			case ' ':
			{
				if ((precontent != ' ') && (precontent != '\n') && (precontent != '\r') && (precontent != '\t'))
				{
					num_words++;
				}
				break;
			}/*Set the conditions for counting a word.*/
			case '\t':
			{
				if ((precontent != ' ') && (precontent != '\n') && (precontent != '\r') && (precontent != '\t'))
				{
					num_words++;
				}
				break;
			}/*Set the conditions for counting a word.*/
			default:
			{ 
				num_letter++; 
				break; 
			}
		}
		precontent = content;/*Give the precontent the value of the content.*/
	}
	printf("The number of characters:%d; The number of words:%d, The number of lines:%d\n", num_char, num_words, num_lines);
	return 0;
}