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

void deleteElement(List *list, int number)
{
	ListElement *temp = list->head;
	ListElement *tempPrevious = temp;

	if (list->head != nullptr)
	{
		while (temp->next != nullptr && temp->value != number)
		{
			tempPrevious = temp;
			temp = temp->next;
		}

		if (temp->value == number)
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
		cout << temp->value << " ";
		temp = temp->next;
	}
}

int checkElement(List *list, int number)
{
	ListElement *temp = list->head;
	int i = 0;

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