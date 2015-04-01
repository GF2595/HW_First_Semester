#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void reversion(int segmLength, int firstElement, int *arr)
{
	for (int i = 0; i < segmLength / 2; i++)
	{
		int position = i + firstElement;
		int switcher = arr[position];
		arr[position] = arr[firstElement + segmLength - i - 1];
		arr[firstElement + segmLength - i - 1] = switcher;
	}
}


int main()
{
	srand(time(nullptr));

	int const m = 3;
	int const n = 7;
	int *array = new(int[m + n]);

	for (int i = 0; i < (m + n); i++)
	{
		array[i] = rand() % 100;
		cout << array[i] << " ";
	}

	cout << endl << endl;

	reversion(m, 0, array);
	reversion(n, m, array);
	reversion(m + n, 0, array);

	for (int i = 0; i < (m + n); i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	delete []array;

	return EXIT_SUCCESS;
}