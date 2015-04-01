#include <cstdlib>
#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

//Sets priority of operation
//Receives operation sign
//Returns priority of operation
int getPriority(char operation)
{
	if (operation == ')')
	{
		return 0;
	}
	else if (operation == '(')
	{
		return 1;
	}
	else if (operation == '+' || operation == '-')
	{
		return 2;
	}
	else if (operation == '*' || operation == '/')
	{
		return 3;
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Stack *operations = makeStack();
	string expression;

	cout << "Введите выражение" << endl;
	getline(cin, expression);

	cout << "Выражение, записанное в обратной польской записи: " << endl;

	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			cout << expression[i] << " ";
		}
		else if (expression[i] == '(' || expression[i] == ')' || expression[i] == '-' || expression[i] == '+' || expression[i] == '*' || expression[i] == '/')
		{
			if (isStackEmpty(operations))
			{
				push(operations, expression[i]);
			}
			else
			{
				char temp = ' ';

				do
				{
					temp = pop(operations);

					if (getPriority(expression[i]) > getPriority(temp))
					{
						push(operations, temp);
					}
					else if (temp != '(')
					{
						cout << temp << " ";
					}
				} while (getPriority(expression[i]) <= getPriority(temp) && !isStackEmpty(operations));

				if (expression[i] == ')')
				{
					char deleted = pop(operations);
					deleted = pop(operations);
				}
				else
				{
					push(operations, expression[i]);
				}
			}
		}
	}

	while (!isStackEmpty(operations))
	{
		cout << pop(operations) << " ";
	}

	cout << endl;

	deleteStack(operations);

	return EXIT_SUCCESS;
}

/*Общий случай 1:
Введите выражение
(1 + 1) * 2
Выражение, записанное в обратной польской записи:
1 1 + 2 *

Пограничный случай:
Введите выражение
ololo
Выражение, записанное в обратной польской записи:

*/