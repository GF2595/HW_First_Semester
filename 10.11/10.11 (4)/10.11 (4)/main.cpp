#include <iostream>
#include "longNumbers.h"
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	string insertedNumber;

	cout << "������� ������ �����" << endl;
	cin >> insertedNumber;

	Number *first = convertIntoNumber(insertedNumber);

	cout << "������� ������ �����" << endl;
	cin >> insertedNumber;

	Number *second = convertIntoNumber(insertedNumber);

	Number *third = multiply(first, second);
	cout << "��������� ��������� �����: " << endl;
	printNumber(third);

	third = sum(first, second);
	cout << "��������� �������� �����: " << endl;
	printNumber(third);

	third = subtract(first, second);
	cout << "��������� ��������� �����: " << endl;
	printNumber(third);

	deleteNumber(first);
	deleteNumber(second);
	deleteNumber(third);

	return EXIT_SUCCESS;
}

/*����� ������:
������� ������ �����
75
������� ������ �����
150
��������� ��������� �����:
11250
��������� �������� �����:
225
��������� ��������� �����:
-75
*/