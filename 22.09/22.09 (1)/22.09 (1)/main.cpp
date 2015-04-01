#include <iostream>
#include <stdio.h>
 
using namespace std;

int recursiveFibonacci(int n)							//Recursive numbers calculating
{										//Receives n - № of requiring Fibonacci number
	if (n <= 1)							//Returns requiring Fibonacci number
	{
		return n == 1? 1 : 0;
	}
	else
	{
		return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
	}
}

int iterativeFibonacci(int n)						//Iterative numbers calculating
{										//Receives n - № of requiring Fibonacci number
	if (n <= 2)							//Returns requiring Fibonacci number
	{
		return 1;
	}
	else
	{
		int previousNumber = 1;
		int earlyPreviousNumber = 0;
		int number = 1;

		for (int i = 2; i < n; i++)
		{
			earlyPreviousNumber = previousNumber;
			previousNumber = number;
			number = earlyPreviousNumber + previousNumber;
		}

		return number;
	}
}
 
int main()
{
	int n = 0;
	int choice = 0;

	cout << "Insert n" << endl;
	cin >> n;

	if (n > 0)
	{
		cout << "Insert 1 if you want to launch Fibonacci numbers calculating in recursive way, any other number if you want it in iterative" << endl;
		cin >> choice;

		if (choice = 1)
		{
			cout << recursiveFibonacci(n) << endl;
		}
		else
		{
			cout << iterativeFibonacci(n) << endl;
		}
	}
	else
	{
		cout << "Error: wrong number" << endl;
	}

    return 0;
}


/*Общий случай: 
Insert n
5
Insert 1 if you want to launch Fibonacci numbers calculating in recursive way, any other number if you want it in iterative
2
5

Ошибочный ввод:
Insert n
-1
Error: wrong number

Пограничный случай №1
Insert n
1
Insert 1 if you want to launch Fibonacci numbers calculating in recursive way, any other number if you want it in iterative
2
1

Пограничный случай №2
Insert n
2
Insert 1 if you want to launch Fibonacci numbers calculating in recursive way, any other number if you want it in iterative
1
1
*/