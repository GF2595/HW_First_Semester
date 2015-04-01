#include <iostream>
#include <cstdlib>

using namespace std;

//Receives base and power numbers
//Checks size of power number in binary system then does exponentation using quick method
//Returns result of exponentation
int quickExponentation(int base, int power)
{
	int binaryPower = 0;
	int powerSizeChecker = power;
	int powerBinarySize = 0;

	while (powerSizeChecker !=	0)
	{
		powerSizeChecker >>= 1;
		powerBinarySize++;
	}

	int result = 1;

	for (int i = powerBinarySize; i >= 0 ; i--)
	{
		int mask = 1 << i;
		if (power & mask)
		{
			result = result * result * base;
		}
		else
		{
			result *= result;
		}
	}
	return result;
}

void main()
{
	int base = 0;
	int power = 0;

	cout << "Insert base number" << endl;
	cin >> base;
	cout << "Insert power number" << endl;
	cin >> power;

	int result = base;

	if (power != 0)
	{
		for (int i = 1; i < power; i++)
		{
			result *= base;
		}

		cout << "Result calculated using standard method: " << result << endl;

		cout << "Result calculated using quick method: " << quickExponentation(base, power) << endl;
	}
	else
	{
		if (base != 0)
		{
			cout << "Result of exponentation: 1" << endl;
		}
		else
		{
			cout << "Exponentation not defined" << endl;
		}
	}
}


/*Общий случай:
Insert base number
2
Insert power number
3
Result calculated using standard method: 8
Result calculated using quick method: 8

Пограничный случай 1:
Insert base number
0
Insert power number
0
Exponentation not defined

Пограничный случай 2:
Insert base number
2
Insert power number
0
Result of exponentation: 1
*/