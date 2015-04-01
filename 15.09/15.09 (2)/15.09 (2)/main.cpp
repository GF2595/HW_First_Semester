#include <iostream>
#include <cstdlib>

using namespace std;

int division(int dividend, int divisor)
{
	int quotient = -1;
	do
		quotient++;
	while (divisor * quotient <= dividend);
	return quotient - 1;
}

int dividCheck(int dividend, int divisor)
{
	int quotient = 0;

	switch ((dividend > 0) ? 1 : 2)
	{
	case 1:
	{
		quotient = division(dividend, divisor);
	}
		break;
	case 2:
	{
		dividend *= (-1);
		quotient = division(dividend, divisor) * (-1);
	}
	}
	return quotient;
}

int main()
{
	int a = 0;
	int b = 0;

	cout << "Insert a" << endl;
	cin >> a;
	cout << "Insert b" << endl;
	cin >> b;

	switch ((b == 0) ? 1 : ((b < 0) ? 2 : 3))
	{
	case 1:
	{
		cout << "Error: division by 0" << endl;
	}
		break;
	case 2:
	{
		b *= (-1);
		cout << "Result of division is " << dividCheck(a, b) * (-1) << endl;
	}
		break;
	case 3:
	{
		cout << "Result of division is " << dividCheck(a, b) << endl;
	}
	}

	return EXIT_SUCCESS;
}