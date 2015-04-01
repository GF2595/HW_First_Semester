#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Sorts array with 'bubble' method 
//Receives length of array and array pointer

void bubbleSort(int arrayLength, int *arr)
{
	for (int i = 0; i < arrayLength - 1; i++)
	{
		for (int j = 0; j < arrayLength - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//Sorts array with counting method 
//Receives length of array and array pointer

void countingSort(int arrayLength, int *arr)
{
	int const values = 10;
	int valuesArray[values] = { 0 };

	for (int i = 0; i < arrayLength; i++)
	{
		int lol = arr[i];
		valuesArray[lol]++;
	}

	int j = 0;

	for (int i = 0; i < values; i++)
	{
		if (valuesArray[i] != 0)
		{
			for (valuesArray[i]; valuesArray[i] > 0; valuesArray[i]--)
			{
				arr[j] = i;
				j++;
			}
		}
	}
}

void main()
{
	srand(time(nullptr));

	int const n = 10;
	int *array = new int[n];
	int const values = 10;
	int choice = 1;

	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % values;
		cout << array[i] << " ";
	}

	cout << endl << endl;

	cout << "Insert 1 if you want this array to be sorted with 'bubble' method, any other number if you want it to be sorted with counting method" << endl;
	cin >> choice;

	if (choice == 1)
	{
		bubbleSort(n, array);
	}
	else
	{
		countingSort(n, array);
	}

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl << endl;

	delete[]array;
}


/*Общий случай 1:
2 6 8 4 9 8 5 4 6 0 

Insert 1 if you want this array to be sorted with 'bubble' method, any other number if you want it to be sorted with counting method
1
0 2 4 4 5 6 6 8 8 9


Общий случай 2:
6 2 9 8 6 8 6 6 3 6

Insert 1 if you want this array to be sorted with 'bubble' method, any other number if you want it to be sorted with counting method
2
2 3 6 6 6 6 6 8 8 9
*/