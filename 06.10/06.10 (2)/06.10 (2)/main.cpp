#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include "sort.h"
#include <fstream>

using namespace std;

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
	int const size = 20;
	int *array = new(int[size]);

	ifstream arrayFile;

	arrayFile.open("../array.txt");

	for (int i = 0; i < size; i++)
	{
		arrayFile >> array[i];
	}

	arrayFile.close();

	qsort(array, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl << "Most repeated element is: " << mostRepeatedSeeker(array, size) << endl;

	delete[] array;
}



/*Общий случай:
1 1 2 2 6 7 20 33 45 49 57 57 64 74 76 86 87 87 87 90
Most repeated element is: 87
*/