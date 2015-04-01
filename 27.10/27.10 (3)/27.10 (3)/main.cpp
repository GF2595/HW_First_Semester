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

	cout << "������� ���������" << endl;
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
		cout << "������� ������ �������" << endl;
	}
	else
	{
		cout << "������� ������ �� �������" << endl;
	}

	deleteStack(&brackets);
}


/*����� ������ 1: 
������� ���������
({)}
������� ������ �� �������

����� ������ 2:
������� ���������
(1+1)*2
������� ������ �������

����������� ������:
������� ���������
ololo
������� ������ �������
*/