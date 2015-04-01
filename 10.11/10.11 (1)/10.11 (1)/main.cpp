#include <cstdlib>
#include <iostream>
#include "arrayList.h"

using namespace std;

void mergeSort(List *&list)
{
	if (listLength(list) > 1)
	{
		int size = listLength(list);
		List *firstHalfList = makeList();
		List *secondHalfList = makeList();

		for (int i = 0; i < size / 2; i++)
		{
			addElement(firstHalfList, checkElement(list, i));
		}

		for (int i = size / 2; i < size; i++)
		{
			addElement(secondHalfList, checkElement(list, i));
		}

		mergeSort(firstHalfList);
		mergeSort(secondHalfList);
		
		deleteList(list);
		list = makeList();
		int counter1 = 0;
		int counter2 = 0;

		while (counter1 < listLength(firstHalfList) && counter2 < listLength(secondHalfList))
		{
			if (checkElement(firstHalfList, counter1) < checkElement(secondHalfList, counter2))
			{
				addElement(list, checkElement(firstHalfList, counter1));
				counter1++;
			}
			else
			{
				addElement(list, checkElement(secondHalfList, counter2));
				counter2++;
			}
		}

		if (counter1 < listLength(firstHalfList))
		{
			for (int i = counter1; i < listLength(firstHalfList); i++)
			{
				addElement(list, checkElement(firstHalfList, i));
			}
		}
		else
		{
			for (int i = counter2; i < listLength(secondHalfList); i++)
			{
				addElement(list, checkElement(secondHalfList, i));
			}
		}

		deleteList(firstHalfList);
		deleteList(secondHalfList);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int length = 0;
	List *list = makeList();

	cout << "Задайте длину массива" << endl;
	cin >> length;

	for (int i = 0; i < length; i++)
	{
		int temp = 0;
		cout << "Введите " << i + 1 << "-ый элемент" << endl;
		cin >> temp;

		addElement(list, temp);
	}

	mergeSort(list);

	printList(list);
	deleteList(list);

	cout << endl;

	return EXIT_SUCCESS;
}