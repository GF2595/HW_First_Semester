#include <cstdlib>
#include <iostream>

using namespace std;

//Adds 1 to specified position of binary number represented in array
//Receives array pointer and position of number
void additionOfOne(bool *number, int position)
{
	if (number[position])
	{
		number[position] = 0;
		additionOfOne(number, position - 1);
	}
	else
	{
		number[position] = 1;
	}
}

//Translates direct code into additional code
//Receives code containing array pointer and bit depth
void codeTranslation(bool *number, int bitDepth)
{
	for (int i = 0; i < bitDepth; i++)
	{
		number[i] = !number[i];
	}
	additionOfOne(number, bitDepth - 1);
}

//Converses decimal number into binary represented in array
//Receives array pointer, bit depth and decimal number
void translation(bool *number, int bitDepth, int numberDecimal)
{
	if (numberDecimal < 0)
	{
		int absNumberDecimal = -numberDecimal;
		for (int i = 0; i < bitDepth; i++)
		{
			int mask = 1 << i;
			number[bitDepth - 1 - i] = absNumberDecimal & mask;
		}
		codeTranslation(number, bitDepth);
	}
	else
	{
		for (int i = 0; i < bitDepth; i++)
		{
			int mask = 1 << i;
			number[bitDepth - 1 - i] = numberDecimal & mask;
		}
	}
}

//Prints array
//Receives array pointer and size of array
void numberOut(bool *number, int bitDepth)
{
	for (int i = 0; i < bitDepth; i++)
	{
		cout << number[i];
	}
	cout << endl;
}

//Adds two binary numbers represented in arrays
//Reveives arrays of both numbers pointer, point of resulting array and bit depth
void addition(bool *firstNumber, bool *secondNumber, bool *result, int bitDepth)
{
	bool remainder = 0;

	for (int i = bitDepth - 1; i >= 0; i--)
	{
		if (firstNumber[i] && secondNumber[i])
		{
			result[i] = remainder;
			remainder = 1;
		}
		else
		{
			if (remainder)
			{
				if (firstNumber[i] || secondNumber[i])
				{
					result[i] = 0;
					remainder = 1;
				}
				else
				{
					result[i] = 1;
					remainder = 0;
				}
			}
			else
			{
				result[i] = firstNumber[i] || secondNumber[i];
			}
		}
	}
}

//Converses binary number represented in array into decimal number
//Receives array pointer and bit depth
//Returns resulting decimal number
int reverseTranslation(bool *number, int bitDepth)
{
	int numberDecimal = 0;

	if (number[0])
	{
		codeTranslation(number, bitDepth);

		for (int i = 0; i < bitDepth; i++)
		{
			numberDecimal += number[bitDepth - 1 - i] * pow(2, i);
		}

		return -numberDecimal;
	}
	else
	{
		for (int i = 0; i < bitDepth; i++)
		{
			numberDecimal += number[bitDepth - 1 - i] * pow(2, i);
		}
		
		return numberDecimal;
	}
}

void main()
{
	setlocale(LC_ALL, "rus");

	int const bitDepth = 8;
	bool *firstNumber = new(bool[bitDepth]);
	bool *secondNumber = new (bool[bitDepth]);

	int firstNumberDecimal = 0;
	int secondNumberDecimal = 0;

	cout << "������� ������ �����" << endl;
	cin >> firstNumberDecimal;
	cout << "������� ������ �����" << endl;
	cin >> secondNumberDecimal;

	translation(firstNumber, bitDepth, firstNumberDecimal);
	translation(secondNumber, bitDepth, secondNumberDecimal);

	cout << endl << "������ ����� �� ���������� �������������:" << endl;
	numberOut(firstNumber, bitDepth);
	cout << "������ ����� �� ���������� �������������:" << endl;
	numberOut(secondNumber, bitDepth);
	cout << endl;

	bool *result = new(bool[bitDepth]);

	addition(firstNumber, secondNumber, result, bitDepth);

	cout << "��������� �� ���������� �������������: " << endl;
	numberOut(result, bitDepth);

	cout << "��������� � ���������� ������� ���������:" << endl;
	cout << reverseTranslation(result, bitDepth) << endl;

	delete[] result;
	delete[] firstNumber;
	delete[] secondNumber;
}



/*����� ������:
������� ������ �����
10
������� ������ �����
-1

������ ����� �� ���������� �������������:
00001010
������ ����� �� ���������� �������������:
11111111

��������� �� ���������� �������������:
00001001
��������� � ���������� ������� ���������:
9


����������� ������:
������� ������ �����
-32767
������� ������ �����
32768

������ ����� �� ���������� �������������:
00000001
������ ����� �� ���������� �������������:
00000000

��������� �� ���������� �������������:
00000001
��������� � ���������� ������� ���������:
1
*/