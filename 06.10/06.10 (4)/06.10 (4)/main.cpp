#include <iostream>

using namespace std;

//Sorts array using Shell's method
//Receives array pointer and size of array
void shellSort(int *arr, int size)
{
	int step = size / 2;

	while (step > 0)
	{
		for (int i = 0; i < size - step; ++i)
		{
			int j = i;

			while (j >= 0 && arr[j] > arr[j + step])
			{
				swap(arr[j], arr[j + step]);

				j--;
			}
		}
		step = step / 2;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int const size = 10;

	int *arr = new int[size];

	cout << "Введите элементы массива: " << endl;

	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
	}
	
	shellSort(arr, size);

	cout << "Отсортированный массив: " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	delete[] arr;

	return EXIT_SUCCESS;
}

/*Общий случай:
Введите элементы массива:
7
8
3
5
7
12
65
44
7
5
Отсортированный массив: 
3 5 5 7 7 7 8 12 44 65
*/