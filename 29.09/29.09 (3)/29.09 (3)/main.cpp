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

//Seeks for most repeated element
//Receives array pointer and size of array
//Returns most repeated element
int mostRepeatedSeeker(int *arr, int size)
{
	int maxRepeatings = 0;
	int maxRepeatedElement = 0;
	int currentRepeatngs = 1;
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			currentRepeatngs++;
		}
		else
		{
			if (currentRepeatngs > maxRepeatings)
			{
				maxRepeatings = currentRepeatngs;
				maxRepeatedElement = arr[i];
			}
			currentRepeatngs = 1;
		}
	}
	if (currentRepeatngs > maxRepeatings)
	{
		maxRepeatings = currentRepeatngs;
		maxRepeatedElement = arr[size - 1];

	}
	return maxRepeatedElement;
}

void main()
{

	srand(time(nullptr));

	int const size = 20;
	int *array = new(int[size]);

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
	}

	qsort(array, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl << "Most repeated element is: " << mostRepeatedSeeker(array, size) << endl;

	delete[]array;
}



/*ќЅщий случай:
23 35 36 42 52 59 59 63 66 67 69 71 76 80 81 82 86 89 90 99
Most repeated element is: 59
*/