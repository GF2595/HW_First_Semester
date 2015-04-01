#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Predicate for sort procedure
//Receives two numbers
//Returns "true" if first number if lesser then second and "false" otherwise
bool predicate(int i, int j)
{
	return (i < j); 
}

int main()
{
	setlocale(LC_ALL, "rus");

	unsigned number = 0;
	vector<int> string;

	cout << "Введите количество элементов для перестановки" << endl;
	cin >> number;

	for (int i = 0; i < number; i++)
	{
		string.push_back(i + 1);
		cout << string[i] << " ";
	}

	cout << endl;

	bool lastStringIsFound = false;

	do
	{
		unsigned i = number;
		do
		{
			i--;
		} while (i > 1 && string[i - 1] > string[i]);

		if (string[i - 1] < string[i])
		{
			int numberToBeReplaced = 2147483647;
			int placeOfNumberToBeReplaced = -1;

			for (int j = i; j < number; j++)
			{
				if (string[j] < numberToBeReplaced && string[j] > string[i - 1])
				{
					numberToBeReplaced = string[j];
					placeOfNumberToBeReplaced = j;
				}
			}

			swap(string[placeOfNumberToBeReplaced], string[i - 1]);

			sort(string.begin() + i, string.end(), predicate);

			for (int j = 0; j < number; j++)
			{
				cout << string[j] << " ";
			}

			cout << endl;
		}
		else
		{
			lastStringIsFound = true;
		}
	} while (!lastStringIsFound);

	return EXIT_SUCCESS;
}

/*Общий случай:
Введите количество элементов для перестановки
3
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/