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
		if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
		{
			push(&brackets, expression[i]);
		}
		else if (expression[i] == ')')
		{
			if (pop(&brackets) != '(')
			{
				orderIsObserved = false;
			}
		}
		else if (expression[i] == '}')
		{
			if (pop(&brackets) != '{')
			{
				orderIsObserved = false;
			}
		}
		else if (expression[i] == ']')
		{
			if (pop(&brackets) != '[')
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


/*Общий случай 1: 
Введите выражение
({)}
Порядок скобок не соблюдён

Общий случай 2:
Введите выражение
(1+1)*2
Порядок скобок соблюдён

Пограничный случай:
Введите выражение
ololo
Порядок скобок соблюдён
*/