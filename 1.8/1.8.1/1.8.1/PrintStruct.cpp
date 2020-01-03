// Purpose: Write a C-program that prints the contents of a struct called Article
// Author: Tianyu Zhang
// Date: 04/27/18

#include <stdio.h>
#include <string.h>

struct Article	// Claim what the Article contains.
{
	int Article_number;
	int Quantity;
	char Description[20];
};

void Print(struct Article *p_article);

int main()
{
	struct Article article;	// Initializing an Article struct
	article.Article_number = 1;
	article.Quantity=100;
	strcpy_s(article.Description, "An article on 1.8.1");

	Print(&article);
}

void Print(struct Article *p_article)	// Print all things in the Article
{
	printf("Article number:%d\n", (*p_article).Article_number);
	printf("Quantity:%d\n", (*p_article).Quantity);
	printf("Description:%s\n", (*p_article).Description);
}