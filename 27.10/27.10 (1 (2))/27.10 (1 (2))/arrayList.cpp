#include <iostream>
#include "arrayList.h"
#include <vector>
#include <string>

using namespace std;

struct List
{
	vector<ElementType> list;
};

List* makeList()
{
	return new List;
}

void deleteList(List *list)
{
	delete list;
}

void addElement(List *list, ElementType value)
{
	list->list.push_back(value);
}

int listLength(List *list)
{
	return list->list.size();
}

void deleteElement(List *list, int number)
{
	for (int i = number; i < list->list.size() - 1; i++)
	{
		list->list[i] = list->list[i + 1];
	}

	list->list.pop_back();
}

void printList(List *list)
{
	for (int i = 0; i < list->list.size(); i++)
	{
		cout << list->list[i].name << " " << list->list[i].number << endl;
	}
}

Record checkElement(List *list, int number)
{
	if (number <= list->list.size())
	{
		return list->list[number];
	}
	else
	{
		Record temp;
		temp.name = "";
		temp.number = 0;

		return temp;
	}
}