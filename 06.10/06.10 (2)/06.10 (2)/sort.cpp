#include <iostream>
#include <cstdlib>
#include "sort.h"

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