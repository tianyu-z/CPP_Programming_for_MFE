//Purpose: The Test file of Stack Class
//Author: Tianyu Zhang
//Date: 06/22/18

#include "Stack.cpp"
#include "Stack.h"
#include <iostream>



using namespace std;

void main()
{
	// defalut constructor.
	Stack<int,10> stack00;

	// Push().

	for (int i = 0; i < 11; i++)
	{
		try
		{
			stack00.Push(i);
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}
	}

	// copy constructor.
	Stack<int,10> stack01(stack00);

	// assignment operator.
	Stack<int,10> stack02 = stack00;

	// Pop().
	for (int i = 0; i < 11; i++)
	{
		try
		{
			cout << stack00.Pop() << endl;
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}

		try
		{
			cout << stack01.Pop() << endl;
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}

		try
		{
			cout << stack02.Pop() << endl;
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}
	}
}