#include <vector>
#include "longNumbers.h"
#include <iostream>
#include <string>

using namespace std;

//This struct is used to represent long number
//Sign is false, when number is positive and true if number is negative
//Vector represents number itself, each position of vector for each digit of number in reverse order
struct Number {
	bool sign;
	vector<unsigned short> number;
};

Number* makeNumber()
{
	Number *newNumber = new Number;
	newNumber->sign = false;
	return newNumber;
}

//Compares two numbers
//Receives two numbers pointers
//Returns '-1' if first is bigger, '1' if second is bigger and '0' if numbers are equal
short compareNumbers(Number *first, Number *second)
{
	if (first->number.size()  == 0 && second->number.size() == 0)
	{
		return 0;
	}

	if (first->number.size() > second->number.size())
	{
		return -1;
	}
	else if (first->number.size() < second->number.size())
	{
		return 1;
	}
	else
	{
		bool numbersAreEqual = true;
		int i = first->number.size() - 1;

		do
		{
			numbersAreEqual = (first->number[i] == second->number[i]);

			if (first->number[i] < second->number[i])
			{
				return 1;
			}

			i--;
		} while (i >= 0);

		if (numbersAreEqual)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
}

Number* convertIntoNumber(string const &insertedNumber)
{
	Number *result = makeNumber();

	if (insertedNumber.size() == 0)
	{
		return result;
	}

	int i = 0;

	if (insertedNumber[i] == '-')
	{
		result->sign = true;
		i++;
	}

	for (i = insertedNumber.size(); i >= 0; i--)
	{
		if (insertedNumber[i] >= '0' && insertedNumber[i] <= '9')
		{
			unsigned short digit = insertedNumber[i] - '0';

			result->number.push_back(digit);
		}
	}

	return result;
}

void negative(Number *&oldNumber)
{
	oldNumber->sign = !oldNumber->sign;
}

Number* subtract(Number *first, Number *second)
{
	Number *result = makeNumber();

	if (first->sign)
	{
		if (second->sign)
		{
			result->sign = !result->sign;
		}
		else
		{
			first->sign = false;
			delete result;
			Number *result = sum(first, second);
			result->sign = !result->sign;
			first->sign = true;

			return result;
		}
	}
	else
	{
		if (second->sign)
		{
			second->sign = false;

			delete result;
			Number *result = sum(first, second);
			second->sign = true;

			return result;
		}
	}

	bool numbersWereSwapped = false;

	if (compareNumbers(first, second) == 1)
	{
		result->sign = !result->sign;

		swap(first, second);
		numbersWereSwapped = true;
	}

	int i = 0;

	vector<unsigned short> temp = first->number;

	for (i; i < second->number.size(); i++)
	{
		if (second->number[i] <= first->number[i])
		{
			result->number.push_back(first->number[i] - second->number[i]);
		}
		else
		{
			int j = i + 1;

			while (first->number[j] == 0)
			{
				j++;
			}

			for (j; j > i; j--)
			{
				first->number[j]--;
				first->number[j - 1] += 10;
				j--;
			}

			result->number.push_back(first->number[i] - second->number[i]);
		}
	}

	for (i; i < first->number.size(); i++)
	{
		result->number.push_back(first->number[i]);
	}
	
	if (result->number.size() == 0)
	{
		result->number.push_back(0);
	}

	i = result->number.size() - 1;

	while (result->number[i] == 0 && i > 0)
	{
		result->number.pop_back();
		i--;
	}

	first->number = temp;

	if (numbersWereSwapped)
	{
		swap(first, second);
	}

	if (result->number[0] == 0)
	{
		result->sign = false;
	}

	return result;
}

Number* sum(Number *first, Number *second)
{
	Number *result = makeNumber();

	if (first->sign)
	{
		if (!second->sign)
		{
			first->sign = false;
			result = subtract(first, second);
			result->sign = !result->sign;

			first->sign = true;

			return result;
		}
		else
		{
			result->sign = true;
		}
	}
	else
	{
		if (second->sign)
		{
			second->sign = false;
			delete result;
			Number *result = subtract(first, second);

			second->sign = true;

			return result;
		}
	}

	bool numbersWereSwapped = false;

	if (first->number.size() < second->number.size())
	{
		swap(first, second);
		numbersWereSwapped = true;
	}

	int previousResidue = 0;
	int i = 0;

	for (i; i < second->number.size(); i++)
	{
		unsigned short currentDigit = first->number[i] + second->number[i] + previousResidue;

		if (currentDigit >= 10)
		{
			result->number.push_back(currentDigit % 10);
			previousResidue = currentDigit / 10;
		}
		else
		{
			result->number.push_back(currentDigit);
			previousResidue = 0;
		}
	}

	for (; i < first->number.size(); i++)
	{
		unsigned short currentDigit = first->number[i] + previousResidue;

		if (currentDigit >= 10)
		{
			result->number.push_back(currentDigit % 10);
			previousResidue = currentDigit / 10;
		}
		else
		{
			result->number.push_back(currentDigit);
			previousResidue = 0;
		}
	}
		
	while (previousResidue != 0)
	{
		result->number.push_back(previousResidue % 10);

		previousResidue /= 10;
	}

	if (result->number.size() == 0)
	{
		result->number.push_back(0);
	}

	i = result->number.size() - 1;

	while (result->number[i] == 0 && i > 0)
	{
		result->number.pop_back();
		i--;
	}

	if (numbersWereSwapped)
	{
		swap(first, second);
	}

	return result;
}

Number* multiply(Number *first, Number *second)
{
	Number *result = makeNumber();

	int i = 0;

	for (i; i < first->number.size(); i++)
	{
		Number *temp = makeNumber();

		for (int j = 0; j < i; j++)
		{
			temp->number.push_back(0);
		}

		int previousResidue = 0;

		for (int j = 0; j < second->number.size(); j++)
		{
			unsigned short currentDigit = second->number[j] * first->number[i] + previousResidue;

			if (currentDigit >= 10)
			{
				temp->number.push_back(currentDigit % 10);
				previousResidue = currentDigit / 10;
			}
			else
			{
				temp->number.push_back(currentDigit);
				previousResidue = 0;
			}
		}

		while (previousResidue != 0)
		{
			temp->number.push_back(previousResidue % 10);

			previousResidue /= 10;
		}

		if (temp->number.size() != 0)
		{
			int k = temp->number.size() - 1;

			while (temp->number[k] == 0 && k > 0)
			{
				temp->number.pop_back();
				k--;
			}
		}

		result = sum(result, temp);
	}

	if (result->number.size() == 0)
	{
		result->number.push_back(0);
	}

	i = result->number.size() - 1;

	while (result->number[i] == 0 && i > 0)
	{
		result->number.pop_back();
		i--;
	}

	if (first->sign ^ second->sign)
	{
		result->sign = true;
	}

	if (result->number[0] == 0 && result->number.size() == 1)
	{
		result->sign = false;
	}

	return result;
}

void printNumber(Number *num)
{
	if (num->sign)
	{
		cout << "-";
	}

	for (int i = num->number.size() - 1; i >= 0; i--)
	{
		cout << num->number[i];
	}

	cout << endl;
}

void deleteNumber(Number *num)
{
	delete num;
}