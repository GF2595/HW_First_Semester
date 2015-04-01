#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Reordering of elements in specified part of array
//Receives array pointer, pivot around which elements will be reordered, numbers of first and last element of array part
//Returns position of pivot in reordered array
int reordering(int *arr, int pivot, int firstElement, int lastElement)
{
	int firstPosition = firstElement;
	int i = firstElement + 1;

	swap(arr[pivot], arr[firstElement]);

	do
	{
		if (arr[firstPosition] >= arr[i])
		{
			swap(arr[firstPosition + 1], arr[i]);
			swap(arr[firstPosition], arr[firstPosition + 1]);
			firstPosition++;
		}
		i++;
	} while (i <= lastElement);

	return firstPosition;
}

//Sorts specified part of array using insertion method
//Receives array pointer, numbers of first and last element of array part
void insertionSort(int *arr, int firstElement, int lastElement)
{
	for (int i = 1; i <= lastElement; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			swap(arr[j - 1], arr[j]);
		}
	}
}

//Sorts specified part of array using 'quick' method if length of part if more than 10 numbers, otherwise launches insertionSort
//Receives array pointer, numbers of first and last element of array part
void qsort(int *arr, int firstElement, int lastElement)
{
	if (lastElement - firstElement < 10)
	{
		insertionSort(arr, firstElement, lastElement);
	}
	else
	{
		int pivot = rand() % (lastElement - firstElement) + firstElement;
		int pivotPosition = reordering(arr, pivot, firstElement, lastElement);

		qsort(arr, firstElement, pivotPosition - 1);
		qsort(arr, pivotPosition + 1, lastElement);
	}
}

void main()
{
	srand(time(nullptr));

	int const size = 50;
	int *array = new(int[size]);

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
		cout << array[i] << " ";
	}

	cout << endl << endl;

	qsort(array, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	delete[]array;
}



/*Общий случай:
76 10 57 11 99 43 26 49 0 19 12 75 76 78 25 70 32 33 31 19 30 72 64 49 72 53 90
15 64 38 71 8 10 18 24 33 92 16 74 67 53 84 33 34 43 18 29 53 40 41

0 8 10 10 11 12 15 16 18 18 19 19 24 25 26 29 30 31 32 33 33 33 34 38 40 41 43 4
3 49 49 53 53 53 57 64 64 67 70 71 72 72 74 75 76 76 78 84 90 92 99
*/