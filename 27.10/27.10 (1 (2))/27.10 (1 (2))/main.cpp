#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "arrayList.h"

using namespace std;

enum class SortType
{
	byName, 
	byPhone
};

void mergeSort(List *&list, SortType code)
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

		mergeSort(firstHalfList , code);
		mergeSort(secondHalfList, code);
		
		deleteList(list);
		list = makeList();
		int counter1 = 0;
		int counter2 = 0;

		while (counter1 < listLength(firstHalfList) && counter2 < listLength(secondHalfList))
		{
			if (code == SortType::byName)
			{
				if (checkElement(firstHalfList, counter1).name < checkElement(secondHalfList, counter2).name)
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
			else if (checkElement(firstHalfList, counter1).number < checkElement(secondHalfList, counter2).number)
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

	List *list = makeList();

	ifstream file("../base.txt", ios::in);
	if (!file.is_open())
	{
		cout << "File not found!" << endl;
		return EXIT_FAILURE;
	}

	while (!file.eof()) {
		string buffer;
		unsigned i = 0;

		getline(file, buffer);

		while (i < buffer.size() && buffer.substr(i, 3) != " - ")
		{
			i++;
		}

		Record temp;
		temp.name = buffer.substr(0, i);
		temp.number = atoi(buffer.substr(i + 4, buffer.size() - i - 4).c_str());
		

		addElement(list, temp);
	}

	file.close();

	int code = 1;

	cout << "Ѕаза загружена" << endl << endl;
	cout << "¬ведите 1, чтобы запустить сортировку по именам" << endl << "2, чтобы запустить сортировку по номерам" << endl;
	cin >> code;

	mergeSort(list, code == 1 ? SortType::byName : SortType::byPhone);

	printList(list);

	deleteList(list);

	return EXIT_SUCCESS;
}