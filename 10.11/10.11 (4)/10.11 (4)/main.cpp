#include <iostream>
#include "longNumbers.h"
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	string insertedNumber;

	cout << "Введите первое число" << endl;
	cin >> insertedNumber;

	Number *first = convertIntoNumber(insertedNumber);

	cout << "Введите второе число" << endl;
	cin >> insertedNumber;

	Number *second = convertIntoNumber(insertedNumber);

	Number *third = multiply(first, second);
	cout << "Результат умножения чисел: " << endl;
	printNumber(third);

	third = sum(first, second);
	cout << "Результат сложения чисел: " << endl;
	printNumber(third);

	third = subtract(first, second);
	cout << "Результат вычитания чисел: " << endl;
	printNumber(third);

	deleteNumber(first);
	deleteNumber(second);
	deleteNumber(third);

	return EXIT_SUCCESS;
}

/*Общий случай:
Введите первое число
75
Введите второе число
150
Результат умножения чисел:
11250
Результат сложения чисел:
225
Результат вычитания чисел:
-75
*/