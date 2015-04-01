#include <cstdlib>
#include <iostream>
#include "pointerList.h"

using namespace std;

struct ListElement
{
	ElementType value;
	ListElement *next;
};

struct List
{
	ListElement *head;
};

List* makeList()
{
	List *newList = new List;
	newList->head = nullptr;
	return newList;
}

void addElement(List *list, ElementType value)
{
	ListElement *newElement = new ListElement;
	newElement->value = value;
	newElement->next = nullptr;

	if (list->head == nullptr)
	{
		list->head = newElement;
	}
	else
	{
		ListElement *temp = list->head;

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = newElement;
	}
}

int listLength(List *list)
{
	ListElement *temp = list->head;
	int length = 0;

	while (temp != nullptr)
	{
		length += 1;

		temp = temp->next;
	}

	return length;
}

bool compare(ListValue first, ListValue second)
{
	if (first.word.compare(second.word) == 0)
	{
		return first.timesFound == second.timesFound;
	}
	else
	{
		return false;
	}
}

void deleteElement(List *list, ElementType element)
{
	ListElement *temp = list->head;
	ListElement *tempPrevious = temp;

	if (list->head != nullptr)
	{
		while (temp->next != nullptr && !compare(temp->value, element))
		{
			tempPrevious = temp;
			temp = temp->next;
		}

		if (compare(temp->value, element))
		{
			if (tempPrevious == temp)
			{
				list->head = temp->next;
			}
			else
			{
				tempPrevious->next = temp->next;
			}
			delete temp;
		}
	}
}

void printList(List *list)
{
	ListElement *temp = list->head;

	while (temp != nullptr)
	{
		cout << "Слово " << temp->value.word << " встретилось " << temp->value.timesFound << " раз" << endl;
		temp = temp->next;
	}
}

ElementType checkElement(List *list, int number)
{
	ListElement *temp = list->head;
	int i = 1;

	if (number <= listLength(list))
		while (temp->next != nullptr && i < number)
		{
			temp = temp->next;
			i++;
		}
	
	return temp->value;
}

void deleteList(List *list)
{
	while (list->head != nullptr)
	{
		ListElement *temp = list->head;
		list->head = temp->next;
		
		delete temp;
	}

	delete list;
}

void addTimesFound(List *&list, std::string element)
{
	ListElement *temp = list->head;

	while (temp != nullptr)
	{
		if (temp->value.word == element)
		{
			temp->value.timesFound++;
			return;
		}

		temp = temp->next;
	}

	ListValue newValue;
	newValue.timesFound = 1;
	newValue.word = element;
	addElement(list, newValue);
}