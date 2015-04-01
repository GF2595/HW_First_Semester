#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void main()
{
	srand(time(nullptr));

	int const length = 7;
	int array[length];

	for (int i = 0; i < (length); i++)
	{
		array[i] = rand() % 100;
		cout << array[i] << " ";
	}

	cout << endl << endl;

	int firstPosition = 0;
	int i = 1;

	do
	{
		if (array[firstPosition] >= array[i])
		{
			swap(array[firstPosition + 1], array[i]);
			swap(array[firstPosition], array[firstPosition + 1]);
			firstPosition++;
		}
		i++;
	} while (i < length);

	for (int i = 0; i < (length); i++)
	{
		cout << array[i] << " ";
	}
}

/*Общий случай 1:
32 35 72 9 65 64 63

9 32 72 35 65 64 63


Общий случай 2:
25 99 82 21 1 65 90

21 1 25 99 82 65 90
*/