#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

using namespace std;

//Counts result of operation
//Receives two elements of operation and code of sign (1 for + , 2 for - , 3 for * and 4 for /)
//Returns result of operation
int operation(int firstElement, int secondElement, int const operation)
{
	switch (operation)
	{
	case '+':
	{
		return firstElement + secondElement;
	}
	case '-':
	{
		return firstElement - secondElement;
	}
	case '*':
	{
		return firstElement * secondElement;
	}
	case '/':
	{
		if (secondElement != 0)
		{
			return firstElement / secondElement;
		}
		else
		{
			return 0;
		}
	}
	default:
	{
		return 0;
	}
	}
}

bool isOperation(char symbol)
{
	return (symbol == '+') || (symbol == '-') || (symbol == '/') || (symbol == '*');
}

void main()
{
	setlocale(LC_ALL, "rus");

	Stack *numbers = makeStack();

	cout << "¬ведите выражение: " << endl;

	string expression;
	getline(cin, expression);

	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			push(numbers, expression[i] - '0');
		}
		else if (isOperation(expression[i]))
		{

			push(numbers, operation(pop(numbers), pop(numbers), expression[i]));
		}
	}

	cout << "–езультат вычислений: " << pop(numbers) << endl;

	deleteStack(numbers);
}

/*ќбщий случай 1:
¬ведите количество чисел
4
¬ведите числа
9
6
1
2

¬ведите операцию 1
-
¬ведите операцию 2
+
¬ведите операцию 3
*
–езультат вычислений: 9


ќбщий случай 2:
¬ведите количество чисел
2
¬ведите числа
1
-1

¬ведите операцию 1
+
–езультат вычислений: 0
*/