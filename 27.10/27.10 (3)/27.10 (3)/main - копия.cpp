#include <cstdlib>
#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	Stack brackets;
	string expression;

	cout << "Введите выражение" << endl;
	cin >> expression;

	int i = 0;
	bool orderIsObserved = true;

	do
	{
		if (expression[i] == '(')
		{
			push(&brackets, 1);
		}
		else if (expression[i] == '{')
		{
			push(&brackets, 2);
		}
		else if (expression[i] == '[')
		{
			push(&brackets, 3);
		}
		else if (expression[i] == ')')
		{
			if (pop(&brackets) != 1)
			{
				orderIsObserved = false;
			}
		}
		else if (expression[i] == '}')
		{
			if (pop(&brackets) != 2)
			{
				orderIsObserved = false;
			}
		}
		else if (expression[i] == ']')
		{
			if (pop(&brackets) != 3)
			{
				orderIsObserved = false;
			}
		}
		i++;
	} while (orderIsObserved == true && i < expression.size());

	if (orderIsObserved == true)
	{
		cout << "Порядок скобок соблюдён" << endl;
	}
	else
	{
		cout << "Порядок скобок не соблюдён" << endl;
	}

	deleteStack(&brackets);
}