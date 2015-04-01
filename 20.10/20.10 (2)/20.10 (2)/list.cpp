#include <iostream>
#include "list.h"

using namespace std;

struct ListElement {
	ElementType value;
	ListElement *next;
};

struct List {
	ListElement *head;
	unsigned size;
};

List* makeList()
{
	List *newList = new List;
	newList->head = nullptr;
	newList->size = 0;

	return newList;
}

void insertElement(List *list, int position, ElementType element)
{
	ListElement *newElement = new ListElement;
	newElement->value = element;
	newElement->next = nullptr;

	if (position == -1)
	{
		newElement->next = list->head;
		list->head = newElement;
		list->size++;
		return;
	}

	ListElement *temp = list->head;

	int i = 0;

	while (i < position - 1 && i < list->size - 1)
	{
		temp = temp->next;
		i++;
	}

	newElement->next = temp->next;
	temp->next = newElement;
	list->size++;
}

int search(List *list, ElementType element)
{
	if (list->size == 0)
	{
		return -1;
	}

	if (list->head->value > element)
	{
		return -1;
	}

	ListElement *temp = list->head;

	if (list->size > 1)
	{
		unsigned i = 1;
		do
		{
			if (temp->value <= element && temp->next->value > element)
			{
				return i;
			}

			temp = temp->next;
			i++;
		} while (i < list->size);
		
		return list->size;
	}
	else
	{
		return 0;
	}
}

void printList(List *list)
{
	ListElement *temp = list->head;

	for (int i = 0; i < list->size; i++)
	{
		cout << temp->value << " ";

		temp = temp->next;
	}

	cout << endl;
}

void deleteElement(List *list, ElementType element)
{
	unsigned i = 0;
	ListElement *temp = list->head;
	ListElement *tempPrevious = temp;

	if (list->size != 0)
	{
		if (element != list->head->value)
		{
			do
			{
				tempPrevious = temp;
				temp = temp->next;
				i++;
			} while (i < list->size && element != temp->value);
		}

		tempPrevious->next = temp->next;

		if (list->head == temp)
		{
			list->head = temp->next;
		}

		delete temp;
		list->size--;
	}
}

unsigned size(List *list)
{
	return list->size;
}

void deleteList(List *list)
{
	for (int i = 0; i < list->size; i++)
	{
		ListElement *temp = list->head;
		list->head = list->head->next;
		
		delete temp;
	}

	delete list;
}